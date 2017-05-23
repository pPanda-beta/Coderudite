#include "fileservice.h"

#include "../constants.hxx"

#include <QFile>
#include <QJsonDocument>

FileService::FileService()
{

}

using namespace std;

QJsonObject FileService::getProblem(QStringEx pid)
{
	QFile problemFile(problemDir+"/"s+pid+".json"s);
	if(problemFile.open(QFile::ReadOnly))
		return QJsonDocument::fromJson(problemFile.readAll()).object();
	throw "Problem File not found";
}
