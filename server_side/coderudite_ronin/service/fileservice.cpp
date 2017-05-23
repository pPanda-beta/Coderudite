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
	{
		QJsonParseError error;
		auto &&jsonObject = QJsonDocument::fromJson(problemFile.readAll(), &error).object();
		if(error.error != QJsonParseError::NoError)
			throw error.errorString();
		return jsonObject;
	}
	throw "Problem File not found";
}
