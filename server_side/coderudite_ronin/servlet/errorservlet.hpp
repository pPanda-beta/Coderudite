#ifndef ERRORSERVLET_H
#define ERRORSERVLET_H

#include "abstractServlet.hpp"

struct ErrorServlet : public AbstractServlet
{
	string reason;

	ErrorServlet(const string& _reason="An error occured");
	void handle_parsed_request_on_end(QHttpRequest *, map<string, string> , QHttpResponse *) const;
};

#endif // ERRORSERVLET_H
