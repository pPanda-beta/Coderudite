#ifndef EVENTSERVICE_H
#define EVENTSERVICE_H

#include <map>
#include <list>
#include <tuple>
#include "../model/session.h"

class EventService
{
	std::map<std::string,
		std::list<
			std::pair<Session, qhttp::server::QHttpResponse *>
		>
	>	eventListeners;
public:
	EventService();

	void addListener(const QStringEx &event, Session, qhttp::server::QHttpResponse *);
	void replyForEvent(const QStringEx &event, const std::function<void(qhttp::server::QHttpResponse*)> &f);
};

#endif // EVENTSERVICE_H
