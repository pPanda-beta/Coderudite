#include "abstractjsonservlet.hpp"
#include "helpers.hxx"

#include <QJsonObject>
#include <QJsonArray>

#include "../service/sessionservice.h"

AbstractJsonServlet::AbstractJsonServlet(SessionService &s)
	:sessionService(s)
{

}

void AbstractJsonServlet::handle_parsed_request_on_end(QHttpRequest *req, map<string, string> requestFields, QHttpResponse *resp)
{
	SessionService *sp=(SessionService *)(&sessionService);
	Session session(sp, requestFields["sessionId"]);

	session.req = req;
	session.requestFields = requestFields;

	qDebug()<<"Got session Id : "<<requestFields["sessionId"].data()<< " | User id : " <<session.userid;

	if(requestFields.find("json")==requestFields.end())
		throw "Not a Json Request";

	QJsonParseError error;
	auto jsonDoc=QJsonDocument::fromJson(requestFields["json"].data(), &error);

	if(error.error != QJsonParseError::NoError)
		throw error.errorString();

	this->handle_parsed_request_on_end(session,jsonDoc,resp);
}

void AbstractJsonServlet::handle_parsed_request_on_end(Session &session, const QJsonDocument &jsonDoc, QHttpResponse *resp)
{
	if(jsonDoc.isObject())
		this->handle_parsed_request_on_end(session, jsonDoc.object(), resp);
	else if(jsonDoc.isArray())
		this->handle_parsed_request_on_end(session, jsonDoc.array(), resp);
	else
		throw "Unknown json type";
}

void AbstractJsonServlet::handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *)
{
	throw "This servlet does'nt serve json objects";
}

void AbstractJsonServlet::handle_parsed_request_on_end(Session &, const QJsonArray &, QHttpResponse *)
{
	throw "This servlet does'nt serve json arrays";
}

void AbstractJsonServlet::replyWithJson(QHttpResponse *resp, const QJsonDocument &qJsonDoc, TStatusCode code)
{
	replyWith(resp, qJsonDoc.toJson(), code);
}
