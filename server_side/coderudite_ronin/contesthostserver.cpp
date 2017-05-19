#include "contesthostserver.h"
#include "servlet/abstractServlet.hpp"
#include "servlet/errorservlet.hpp"
#include "servlet/loginservlet.hpp"

ContestHostServer::ContestHostServer(initializer_list<quint16> portList)
{
	start(portList);
}


map<string, TServerHandler> ContestHostServer::requestMappings;

int initWebFramework()
{
	static UserMapper userMapper;
	static UserService usr=UserService(userMapper);
	static SessionMapper sessionMapper;
	static SessionService ssr(sessionMapper);

	ContestHostServer::requestMappings =
	{
		{	"/login", LoginServlet(ssr,usr)	},
		{	"/403", ErrorServlet("Access Denied")	},
		{	"/404", ErrorServlet("Servlet not found")	}
	};
	return 0;
}

void ContestHostServer::redirectTo(string servlet, QHttpRequest *req, QHttpResponse *resp)
{
	try
	{
		requestMappings[servlet](req,resp);
	}
	catch (...)
	{
		requestMappings["/403"](req,resp);
	}

}

void ContestHostServer::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
	static int ignore = initWebFramework();
	auto servletPath = req->url().path().toStdString();
	auto &&servlet = requestMappings[servletPath];
	if(servlet)
	{
		try
		{
			servlet(req,resp);
		}
		catch (...)
		{
			requestMappings["/403"](req,resp);
		}
	}
	else
		requestMappings["/404"](req,resp);
}
