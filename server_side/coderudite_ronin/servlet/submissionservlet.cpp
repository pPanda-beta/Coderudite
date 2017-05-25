#include "submissionservlet.hpp"

#include <QJsonObject>
#include <QJsonArray>
#include "../mapper/qobjecthelper.h"

SubmissionServlet::SubmissionServlet(SessionService &_sp, SubmissionService &sbsr)
	: AbstractJsonServlet (_sp),
	  submissionService(sbsr)
{

}

void SubmissionServlet::handle_parsed_request_on_end(Session &session, const QJsonObject &submissionJson, QHttpResponse *resp)
{
	QJsonDocument reply;
	qDebug()<<session.req->url().fileName();
	if(session.req->url().fileName() == "getById")
	{
		reply = (QJsonDocument) submissionService.getSubmissionById(submissionJson["sid"].toString().toStdString());
	}
	else if(session.req->url().fileName() == "getAllIds")
	{
		reply = (QJsonDocument) submissionService.getSubmissionIdsOf(session.userid);
	}
	else if(session.req->url().fileName() == "submit")
	{
		Submission submission;
		QObjectHelper::qjson2qobject(submissionJson, &submission);
		submissionService.submit(session.userid, submission);
		reply = QJsonDocument::fromJson("{ \"message\" : \" successfully submitted\" }");
	}
	replyWithJson(resp,reply);
}
