#ifndef ABSTRACTSERVLET_HPP
#define ABSTRACTSERVLET_HPP

#include <string>
#include <map>
#include "qhttpserver.hpp"
#include "qhttpserverresponse.hpp"
#include "qhttpserverrequest.hpp"

using namespace std;

using namespace qhttp;
using namespace qhttp::server;

struct AbstractServlet
{
	void operator()(QHttpRequest *req,  QHttpResponse *resp) const;
	virtual void handle_parsed_request_on_end(QHttpRequest *, map<string, string> , QHttpResponse *)const = 0;
};

#endif
