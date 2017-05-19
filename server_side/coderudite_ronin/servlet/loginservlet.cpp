#include "loginservlet.hpp"

#include <QJsonObject>
#include "mapper/qobjecthelper.h"
#include "helpers.hxx"

LoginServlet::LoginServlet(SessionService &sp, UserService &us)
	: userService(us),
	  AbstractJsonServlet(sp)
{

}

void LoginServlet::handle_parsed_request_on_end(Session &session, const QJsonObject &trialUserJson, QHttpResponse *resp) const
{
	User trialUser;
	QObjectHelper::qjson2qobject(trialUserJson, &trialUser);
	if(userService.login(trialUser))
	{
		Session ssn=sessionService.createSession(trialUser);
		replyWithJson(resp,QJsonDocument
		(QJsonObject{
			{ "message" , "Successfully Logged In"},
			{ "sessionId", QStringEx(ssn.sid)	}
		}));
	}
}
