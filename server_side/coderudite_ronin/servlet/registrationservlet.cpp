#include "registrationservlet.hpp"
#include "../mapper/qobjecthelper.h"

RegistrationServlet::RegistrationServlet(SessionService &ssr, UserService &usr)
	: AbstractJsonServlet (ssr),
	  userService(usr)
{

}

void RegistrationServlet::handle_parsed_request_on_end(Session &, const QJsonObject &trialUserJson, QHttpResponse *resp)
{
	User trialUser;
	QObjectHelper::qjson2qobject(trialUserJson, &trialUser);
	if(userService.register_user(trialUser))
	{
		replyWithJson(resp,QJsonDocument
		(QJsonObject{
			{ "message" , "Successfully Registered "}
		 }));
	}
	else
		replyWithJson(resp,QJsonDocument
		(QJsonObject{
			{ "message" , "Email already exists!!"}
		}));
}
