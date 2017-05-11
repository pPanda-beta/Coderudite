#include "mainwindow.h"
#include <QApplication>

#include "mapper/abstractmapper.h"

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

	AbstractMapper::universal_db = database(dbPath);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	appInit();

	return a.exec();
}
