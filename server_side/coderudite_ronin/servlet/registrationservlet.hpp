#ifndef REGISTRATIONSERVLET_HPP
#define REGISTRATIONSERVLET_HPP

#include "abstractjsonservlet.hpp"

#include <service/userservice.h>



struct RegistrationServlet : public AbstractJsonServlet
{

	UserService userService;
	RegistrationServlet(SessionService &, UserService &);

	void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *);
};

#endif // REGISTRATIONSERVLET_HPP
