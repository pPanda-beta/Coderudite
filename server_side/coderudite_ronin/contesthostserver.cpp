#include "contesthostserver.h"
#include "servlet/abstractServlet.hpp"
#include "servlet/errorservlet.hpp"
#include "servlet/loginservlet.hpp"
#include "servlet/problemservlet.hpp"
#include "servlet/sseservlet.hpp"

#include <service/submissionservice.h>

#include <servlet/submissionservlet.hpp>

ContestHostServer::ContestHostServer(initializer_list<quint16> portList)
{
	start(portList);
}


map<string, TServerHandler> ContestHostServer::requestMappings;

int initWebFramework()
{
	static UserMapper userMapper;
	static UserService usr(userMapper);
	static SessionMapper sessionMapper;
	static SessionService ssr(sessionMapper);
	static FileService fsr;
	static EventService esr;
	static SubmissionMapper submissionMapper;
	static SubmissionService sbsr(submissionMapper);

	static ProblemServlet problemServlet(ssr, fsr);
	static SubmissionServlet submissionServlet(ssr, fsr, sbsr);

	ContestHostServer::requestMappings =
	{
		{	"/login", LoginServlet(ssr,usr)	},
		{	"/problem/getById", problemServlet	},
		{	"/events", SSEServlet(esr)	},
		{	"/events", submissionServlet	},
		{	"/submission/getById", submissionServlet	},
		{	"/submission/getAllIds", submissionServlet	},
		{	"/submission/submit", submissionServlet	},
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
