#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <QJsonObject>
#include "../model/qstringex.h"

class FileService
{
public:
	FileService();

	QByteArray getContentsOfFile(QStringEx);
	QJsonObject getProblem(QStringEx);
	QStringList getProblemIds();
};

#endif // FILESERVICE_H
