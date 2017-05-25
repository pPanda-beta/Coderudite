#ifndef SUBMISSIONSERVLET_HPP
#define SUBMISSIONSERVLET_HPP

#include "abstractjsonservlet.hpp"

#include <service/submissionservice.h>



class SubmissionServlet : public AbstractJsonServlet
{
public:
	SubmissionService submissionService;
	SubmissionServlet(SessionService &_sp, SubmissionService &s);

	void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *);
};

#endif // SUBMISSIONSERVLET_HPP
