#include "errorservlet.hpp"
#include "helpers.hxx"


ErrorServlet::ErrorServlet(const string &_reason):reason(_reason)
{
}

void ErrorServlet::handle_parsed_request_on_end(QHttpRequest *req, map<string, string> reqFields, QHttpResponse *resp) const
{
//	for(auto &t:reqFields)
//		qDebug()<<t.first.data()<<t.second.data();
//	qDebug()<<req->url().path();
	replyWith(resp,reason,TStatusCode::ESTATUS_NOT_FOUND);
}
