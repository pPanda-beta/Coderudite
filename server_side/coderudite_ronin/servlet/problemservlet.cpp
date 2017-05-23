#include "problemservlet.hpp"

ProblemServlet::ProblemServlet(SessionService &_sp, FileService _fser)
	: AbstractJsonServlet (_sp),
	  fileService(_fser)
{

}

void ProblemServlet::handle_parsed_request_on_end(Session &session, const QJsonObject &reqJson, QHttpResponse *resp)
{
	if(session.req->url().fileName()=="getById")
		replyWithJson(resp, QJsonDocument(fileService.getProblem(reqJson["id"].toString())));
}
