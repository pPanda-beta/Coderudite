#include "abstractServlet.hpp"
#include "../helpers.hxx"

void
AbstractServlet::operator()(QHttpRequest *req,  QHttpResponse *resp) const
{
	req->collectData(20*1024*1024);

	if(req->method() == EHTTP_GET)
	{
		auto queryString = req->url().query().toStdString();
		auto &&requestFields = parsePOST(queryString);
		req->onEnd([=]
		{
			this->handle_parsed_request_on_end(req, requestFields, resp);
		});
	}
	else
	{
		req->onEnd([=]
		{
			auto queryString = req->collectedData().toStdString();
			auto &&requestFields = parsePOST(queryString);
			this->handle_parsed_request_on_end(req, requestFields, resp);
		});
	}
}

