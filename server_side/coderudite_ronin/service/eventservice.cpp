#include "eventservice.h"

EventService::EventService()
{

}

void EventService::addListener(const QStringEx &event, Session ssn, qhttp::server::QHttpResponse *resp)
{
	eventListeners[event].push_back({ssn,resp});
}

void EventService::replyForEvent(const QStringEx &event, const std::function<void (qhttp::server::QHttpResponse *)> &f)
{
	auto &&listeners = eventListeners[event];
	for(auto &listener: listeners)
	{
		f(get<1>(listener));
	}
}
