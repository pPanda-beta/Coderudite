#ifndef ABSTRACTJSONSERVLET_HPP
#define ABSTRACTJSONSERVLET_HPP

#include "abstractServlet.hpp"
#include <QJsonDocument>
#include "../model/Session.h"
#include "../service/sessionservice.h"


struct AbstractJsonServlet : public AbstractServlet
{
	SessionService sessionService;

	AbstractJsonServlet(SessionService &s);

	void handle_parsed_request_on_end(QHttpRequest *, map<string, string> , QHttpResponse *)const;

	virtual void handle_parsed_request_on_end(Session &, const QJsonDocument &, QHttpResponse *)const;
	virtual void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *)const;
	virtual void handle_parsed_request_on_end(Session &, const QJsonArray &, QHttpResponse *)const;

	static void replyWithJson(QHttpResponse *res,const QJsonDocument &qJsonDoc, TStatusCode code=ESTATUS_OK);
};

#endif // ABSTRACTJSONSERVLET_HPP
