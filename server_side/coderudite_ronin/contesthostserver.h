#ifndef CONTESTHOSTSERVER_H
#define CONTESTHOSTSERVER_H

#include "abstractserver.h"

struct ContestHostServer : public AbstractServer
{
	ContestHostServer(initializer_list<quint16> portList);
	void handleRequest(QHttpRequest *, QHttpResponse *);

	static map<string, TServerHandler> requestMappings;
	static void redirectTo(string servlet, QHttpRequest *req, QHttpResponse *resp);
};

#endif // CONTESTHOSTSERVER_H
