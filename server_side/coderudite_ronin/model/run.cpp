#include "run.h"
#include <QDebug>

map<string, function<void(Solution &, QProcess&, RunResult &)>> prepare;
string runsDirPath = appRoot + "/data/tmp"s;

Run::Run(Solution src):m_src(src)
{
	string type = m_src.getType();
	if(prepare.find(type) != prepare.end())
		prepare[type](m_src,m_handle, result);
	else
	{
		result.status = RunResult::STATUS::ERR;
		result.m_err<<"File Type not supported";
	}
	result.m_src = m_src;
}

RunResult Run::execute(string inp, int ms)
{
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

void prepareGcc(Solution &src, QProcess &run_process, RunResult &result)
{
	saveToFile(runsDirPath+"/src.c", src);

	QProcess compile;
	compile.setWorkingDirectory(QString::fromStdString(runsDirPath));
	compile.start("gcc", QStringList()<<"src.c"<<"-o"<<"src.out");
	if(!compile.waitForFinished()  || compile.exitCode() != 0)
		setCompilationError(result, compile);
	else
		run_process.setProgram("./src.out");
}

void prepareJava(Solution &src, QProcess &run_process, RunResult &result)
{
	saveToFile(runsDirPath+"/Main.java",src);
	QProcess compile;
	compile.setWorkingDirectory(QString::fromStdString(runsDirPath));
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
	return 0;
}();
