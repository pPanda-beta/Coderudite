#include "sseservlet.hpp"


SSEServlet::SSEServlet(EventService &esr)
	: eventService(esr)
{

}

void SSEServlet::handle_parsed_request_on_end(QHttpRequest *req, map<string, string> requestFields, QHttpResponse *resp)
{
	Session session(NULL, requestFields["sid"]);
	eventService.addListener(requestFields["event"], session, resp);
}
