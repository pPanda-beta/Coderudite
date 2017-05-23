#ifndef PROBLEMSERVLET_HPP
#define PROBLEMSERVLET_HPP

#include "abstractjsonservlet.hpp"
#include "../service/fileservice.h"


struct ProblemServlet : public AbstractJsonServlet
{
	FileService fileService;
	ProblemServlet(SessionService &_sp, FileService _fser);

	void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *);
};

#endif // PROBLEMSERVLET_HPP
