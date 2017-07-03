#include "run.h"
#include <QDebug>
#include <QDir>
#include <mutex>

map<string, function<void(Solution &, QProcess&, RunResult &, string &)>> prepare;

static int runId = 1;
static mutex mtRun;


Run::Run(Solution src):m_src(src)
{
	{
		lock_guard<mutex> lk(mtRun);
		workingDir = tmpRoot + "/"s + QString::number(runId).toStdString();
		QDir(".").mkpath(QString::fromStdString(workingDir));
		runId++;
	}

	string type = m_src.getType();
	if(prepare.find(type) != prepare.end())
		prepare[type](m_src,m_handle, result, workingDir);
	else
	{
		result.status = RunResult::STATUS::ERR;
		result.m_err<<"File Type not supported";
	}
	result.m_src = m_src;
}

RunResult Run::execute(string inp, int ms)
{
	m_handle.setWorkingDirectory(QString::fromStdString(workingDir));
	if(result.status != RunResult::STATUS::SUCC)
		return result;

	result.m_inp.str(inp);

	auto start_time = chrono::system_clock::now();

	m_handle.start();
	m_handle.waitForStarted();

	m_handle.write(inp.data());
	m_handle.closeWriteChannel();

	m_handle.waitForFinished(ms);
	auto end_time = chrono::system_clock::now();

	if(m_handle.state() == QProcess::Running)
	{
		m_handle.terminate();
		result.status = RunResult::STATUS::TLE;
	}

	result.m_oup.str(m_handle.readAllStandardOutput().toStdString());
	result.exec_time = end_time - start_time;
	return result;
}


//Compilers for different types ...

void saveToFile(string filename, Solution &src)
{
	{
		QFile file( filename.data() );
		if(file.exists())
			file.remove();
	}
	QFile file(filename.data());
	if ( file.open(QIODevice::ReadWrite) )
		file.write(src.getSource().data());
	file.close();
}

void setCompilationError(RunResult &result, QProcess &compile)
{
	result.status = RunResult::STATUS::CTE;
	result.m_err<<compile.readAllStandardError().toStdString()<<"\n"<<compile.readAllStandardOutput().toStdString();
}

void prepareGcc(Solution &src, QProcess &run_process, RunResult &result, string &workingDir)
{
	saveToFile(workingDir+"/src.c"s, src);

	QProcess compile;
	compile.setWorkingDirectory(QString::fromStdString(workingDir));
	compile.start("gcc", QStringList()<<"src.c"<<"-o"<<"src.exe");
	if(!compile.waitForFinished()  || compile.exitCode() != 0)
		setCompilationError(result, compile);
	else
		run_process.setProgram(QString::fromStdString(workingDir+"/src.exe"s));
}

void prepareCpp(Solution &src, QProcess &run_process, RunResult &result, string &workingDir)
{
	saveToFile(workingDir+"/src.cpp"s, src);

	QProcess compile;
	compile.setWorkingDirectory(QString::fromStdString(workingDir));
	compile.start("g++", QStringList()<<"src.cpp"<<"-std=c++11"<<"-o"<<"src.exe");
	if(!compile.waitForFinished()  || compile.exitCode() != 0)
		setCompilationError(result, compile);
	else
		run_process.setProgram(QString::fromStdString(workingDir+"/src.exe"s));
}

void prepareJava(Solution &src, QProcess &run_process, RunResult &result, string &workingDir)
{
	saveToFile(workingDir+"/Main.java"s,src);
	QProcess compile;
	compile.setWorkingDirectory(QString::fromStdString(workingDir));
	compile.start("javac", QStringList()<<"Main.java");
	if(!compile.waitForFinished()  || compile.exitCode() != 0)
		setCompilationError(result, compile);
	else
	{
		run_process.setProgram("java");
		run_process.setArguments(QStringList()<<"Main");
	}
}

int r=[]()
{
	prepare["c"]=prepareGcc;
	prepare["java"]=prepareJava;
	prepare["cpp"] = prepareCpp;
	return 0;
}();
