#include "contesthostserver.h"
#include "servlet/abstractServlet.hpp"
#include "servlet/errorservlet.hpp"

ContestHostServer::ContestHostServer(initializer_list<quint16> portList)
{
	start(portList);
}

map<string, TServerHandler> ContestHostServer::requestMappings =
{
//	{	"/login", [](auto r, auto s){}	},
	{	"/404", ErrorServlet("Servlet not found")	}
};

void ContestHostServer::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
	auto servletPath = req->url().path().toStdString();
	auto &&servlet = requestMappings[servletPath];
	if(servlet)
		servlet(req,resp);
	else
		requestMappings["/404"](req,resp);
}
