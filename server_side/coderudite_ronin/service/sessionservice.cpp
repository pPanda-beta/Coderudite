#include "sessionservice.h"
#include <QDebug>

SessionService::SessionService(SessionMapper _sessionMapper)
	: sessionMapper(_sessionMapper)
{

}

Session SessionService::createSession(const User &user)
{
//	string sid = static_cast<SessionMapper>(sessionMapper).createSessionIdFor(user);
	string sid = sessionMapper.createSessionIdFor(user);
	Session ssn((SessionService *)this, sid);
	ssn.userid = user.get_id();
	return ssn;
}

QStringEx SessionService::getUserIdFor(const string& sid)
{
	try
	{
		return sessionMapper.getUserIdFor(sid);
	}
	catch (sqlite_exception e)
	{
		qDebug()<<__FILE__<<__LINE__<<e.what()<<e.get_code()<<e.get_sql().data()<<"\n";
		return "";
	}
}

string SessionService::getData(string sid, string key)
{
//	return static_cast<SessionMapper>(sessionMapper).getValueOf(sid,key);
	return sessionMapper.getValueOf(sid,key);
}

void SessionService::setData(string sid, string key, string value)
{
	return sessionMapper.setValueOf(sid,key,value);
}
