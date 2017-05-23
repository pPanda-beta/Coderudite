#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <QJsonObject>
#include "../model/qstringex.h"

class FileService
{
public:
	FileService();

	QJsonObject getProblem(QStringEx);
};

#endif // FILESERVICE_H
