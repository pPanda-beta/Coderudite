#ifndef LOGINSERVLET_H
#define LOGINSERVLET_H

#include "abstractjsonservlet.hpp"
#include <service/sessionservice.h>
#include <service/userservice.h>


struct LoginServlet : public AbstractJsonServlet
{
	UserService userService;
	LoginServlet(SessionService &, UserService &);

	void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *);
};

#endif // LOGINSERVLET_H
