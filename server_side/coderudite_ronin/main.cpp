#include "mainwindow.h"
#include <QApplication>

#include "mapper/abstractmapper.h"
#include "mapper/usermapper.h"

void createPathIfNotExist(string path)
{
	QDir(".").mkpath(QString::fromStdString(path));
}

void appInit()
{
	createPathIfNotExist(appRoot);
	createPathIfNotExist(dataRoot);
	createPathIfNotExist(siteRoot);
	createPathIfNotExist(userDataRoot);
	createPathIfNotExist(tmpRoot);
	createPathIfNotExist(problemDir);

	try
	{
		AbstractMapper::universal_db = database(dbPath);
		UserMapper uMp;
		uMp.insertUser(User("12","34"));
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	appInit();

	return a.exec();
}
