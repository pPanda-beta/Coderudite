#include "session.h"
#include "../service/sessionservice.h"

Session::Session(SessionService *_sp, std::string _sid)
	: sessionServiceP(_sp),
	  sid(_sid)
{

}

Session::key_binder Session::operator[](const string &key) const
{
	return key_binder(sessionServiceP,sid,key);
}


Session::key_binder::key_binder(SessionService *_sp, string _sid, string _key)
	: sessionServiceP(_sp),
	  sid(_sid),
	  key(_key)
{

}

void Session::key_binder::operator=(string value) const &&
{
	sessionServiceP->setData(sid,key,value);
}


Session::key_binder::operator string() const
{
	return sessionServiceP->getData(sid,key);
}

