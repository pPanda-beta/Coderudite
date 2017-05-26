#ifndef SUBMISSIONSERVLET_HPP
#define SUBMISSIONSERVLET_HPP

#include "abstractjsonservlet.hpp"

#include <service/fileservice.h>
#include <service/submissionservice.h>



class SubmissionServlet : public AbstractJsonServlet
{
public:
	FileService fileService;
	SubmissionService submissionService;
	SubmissionServlet(SessionService &_sp, FileService &, SubmissionService &s);

	void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *);
};

#endif // SUBMISSIONSERVLET_HPP
