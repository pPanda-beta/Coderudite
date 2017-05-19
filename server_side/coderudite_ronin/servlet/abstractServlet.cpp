#include "abstractServlet.hpp"
#include "../helpers.hxx"
#include "contesthostserver.h"

void
AbstractServlet::operator()(QHttpRequest *req,  QHttpResponse *resp) const
{
	req->collectData(20*1024*1024);

	req->onEnd([=]
	{
		string queryString;
		if(req->method() == EHTTP_GET)
		{
			queryString = req->url().query().toStdString();
		}
		else
		{
			queryString = req->collectedData().toStdString();
		}

		auto &&requestFields = parsePOST(queryString);

		try
		{
			this->handle_parsed_request_on_end(req, requestFields, resp);
		}
		catch(const char *t)
		{
			qDebug()<<t;
			replyWith(resp,"Error : "s + t);
		}
		catch(...)
		{
			qDebug()<<"Unknown exception";
			replyWith(resp,"Error 500: internal server error"s);
		}
	});

}

