#ifndef SSESERVLET_HPP
#define SSESERVLET_HPP

#include "abstractServlet.hpp"
#include <service/eventservice.h>



struct SSEServlet : public AbstractServlet
{
	EventService &eventService;
	SessionService &sessionService;
	SSEServlet(EventService &, SessionService &);

	QHash<QHttpConnection *, int> requestNoOf;

	void handle_parsed_request_on_end(QHttpRequest *, map<string, string> , QHttpResponse *)
;};

#endif // SSESERVLET_HPP
