#ifndef PROBLEMFETCH_HPP
#define PROBLEMFETCH_HPP

#include "abstractjsonservlet.hpp"

#include <service/userservice.h>



struct ProblemFetchServlet : public AbstractJsonServlet
{
	UserService userService;
	ProblemFetchServlet(SessionService &, UserService &);

	void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *);
};

#endif // PROBLEMFETCH_HPP
