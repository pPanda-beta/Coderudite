#include "sessionservice.h"

SessionService::SessionService(SessionMapper _sessionMapper)
	: sessionMapper(_sessionMapper)
{

}

Session SessionService::createSession(const User &user) const
{
	string sid = static_cast<SessionMapper>(sessionMapper).createSessionIdFor(user);
	return Session((SessionService *)this, sid);
}

string SessionService::getData(string sid, string key) const
{
	return static_cast<SessionMapper>(sessionMapper).getValueOf(sid,key);
}

void SessionService::setData(string sid, string key, string value) const
{
	return static_cast<SessionMapper>(sessionMapper).setValueOf(sid,key,value);
}
