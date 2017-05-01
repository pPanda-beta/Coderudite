#ifndef DEDICATEDRUNSERVER_H
#define DEDICATEDRUNSERVER_H

#include "abstractserver.h"
#include "model/run.h"

#include <QDir>
#include <QJsonObject>
#include <QJsonDocument>

#define Y2X(X)	#X
#define MAC2STR(Y) Y2X(Y)


struct DedicatedRunServer : public AbstractServer
{
	QDir base;

	DedicatedRunServer(const QDir& runrt, initializer_list<quint16> portlist);
	void handleRequest(QHttpRequest *, QHttpResponse *);
};

#endif // DEDICATEDRUNSERVER_H
