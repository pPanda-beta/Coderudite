#ifndef SESSIONSERVICE_H
#define SESSIONSERVICE_H

#include "../mapper/sessionmapper.h"
#include "../model/session.h"
#include "../model/user.h"


class SessionService
{
public:
	SessionMapper sessionMapper;
	SessionService(SessionMapper _sessionMapper);

	Session createSession(const User& ) ;
	string getData(string sid, string key) ;
	void setData(string sid, string key, string value) ;
};

#endif // SESSIONSERVICE_H
