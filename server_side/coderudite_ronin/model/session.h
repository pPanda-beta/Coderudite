#ifndef SESSION_H
#define SESSION_H

//#include "../service/sessionservice.h"
#include "qstringex.h"
#include "qhttpserverrequest.hpp"

class SessionService;
using namespace std;
struct Session
{
	qhttp::server::QHttpRequest *req;
	std::map<string,string> requestFields;
	QStringEx userid;
	SessionService *sessionServiceP;
	std::string sid;
	Session(SessionService *_sp, std::string _sid);

	struct key_binder
	{
		SessionService *sessionServiceP;
		string sid, key;
		key_binder(SessionService *, string, string);

		void operator=(string value) const &&;
		operator string() const;
	};

	key_binder operator[](const string &)const ;
};

#endif // SESSION_H
