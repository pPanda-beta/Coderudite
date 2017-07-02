#include "sseservlet.hpp"
#include "helpers.hxx"


SSEServlet::SSEServlet(EventService &esr, SessionService &ssr)
	: eventService(esr),
	  sessionService(ssr)
{

}

void SSEServlet::handle_parsed_request_on_end(QHttpRequest *req, map<string, string> requestFields, QHttpResponse *resp)
{
	auto tcpSocketConn = req->connection();
	requestNoOf[tcpSocketConn]++;

	resp->addHeader("connection", "keep-alive");

	if(requestNoOf[tcpSocketConn] == 1)
	{
		QObject::connect((QObject *)tcpSocketConn, &QObject::destroyed, [=]
		{
			requestNoOf.remove(tcpSocketConn);
		});

		replyWith(resp, "{ \"m\" : \"Socket ready for SSE\" }"s);
	}

	if(requestNoOf[tcpSocketConn] == 2)
	{
		Session session(&sessionService, requestFields["sessionId"]);
		eventService.addListener(requestFields["event"], session, resp);
	}
}
