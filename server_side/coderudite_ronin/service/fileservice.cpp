#include "fileservice.h"

#include "../constants.hxx"

#include <QDir>
#include <QFile>
#include <QJsonDocument>

FileService::FileService()
{

}

QByteArray FileService::getContentsOfFile(QStringEx name)
{
	QFile file(name);
	if(file.open(QFile::ReadOnly))
	{
		return file.readAll();
	}
	throw "File : '"+name+"' not found";
}

using namespace std;


QJsonObject FileService::getProblem(QStringEx pid)
{
	QFile problemFile(problemDir+"/"s+pid+".json"s);
	if(problemFile.open(QFile::ReadOnly))
	{
		QJsonParseError error;
		auto &&jsonObject = QJsonDocument::fromJson(problemFile.readAll(), &error).object();
		if(error.error != QJsonParseError::NoError)
			throw error.errorString();
		return jsonObject;
	}
	throw "Problem File id : '"+pid+"'  not found";
}

QStringList FileService::getProblemIds()
{
	QDir problems(QString::fromStdString(problemDir));

	return problems.entryList({"*.json"})
					.replaceInStrings(
						QRegExp("^(.*)\\.(.*)$"),
									  "\\1");
}


