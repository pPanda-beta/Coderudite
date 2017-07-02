#include "eventservice.h"
#include "concurrency_helpers.hxx"
//#include <QDebug>
//#include <QTime>

EventService::EventService()
{
}



void EventService::addListener(const QStringEx &event, Session ssn, qhttp::server::QHttpResponse *resp)
{
	std::lock_guard<std::mutex> lk(mt);
	eventListeners[event].push_back({ssn, deriveSmartPtr(resp) });

}

//#define g qDebug()<< QTime::currentTime().toString(" mm:ss.zzz")<<__LINE__;

void EventService::replyForEvent(const QStringEx &event, const std::function<void (qhttp::server::QHttpResponse *)> &f)
{
	std::lock_guard<std::mutex> lk(mt);
	auto listeners = eventListeners[event];
	for(auto it = listeners.begin(); it != listeners.end(); ++it)
	{
		if(get<1>(*it).expired())
		{
			listeners.erase(it);
		}
		else
		{
			f(get<1>(*it).lock().get());
		}
	}
}
