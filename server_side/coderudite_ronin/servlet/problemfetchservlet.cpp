#include "problemfetchservlet.hpp"

#include <QJsonObject>

ProblemFetchServlet::ProblemFetchServlet(SessionService &sp, UserService &us)
						   : userService(us),
							 AbstractJsonServlet(sp)
{

}

void ProblemFetchServlet::handle_parsed_request_on_end(Session &, const QJsonObject &reqJson, QHttpResponse *resp) const
{
	replyWithJson(resp,QJsonDocument
	(QJsonObject{
		 { "pid" , "P001"},
		 { "name" , "Problem 1"},
		 { "desc" , "Problem 1 - desc"}
	}));
}
