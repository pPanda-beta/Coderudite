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

	Session createSession(const User& ) const;
	string getData(string sid, string key) const;
	void setData(string sid, string key, string value) const;
};

#endif // SESSIONSERVICE_H
