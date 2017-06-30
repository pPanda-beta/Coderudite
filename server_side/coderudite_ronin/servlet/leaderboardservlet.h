#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "abstractjsonservlet.hpp"

#include <service/fileservice.h>
#include <service/leaderboardservice.h>



class LeaderboardServlet : public AbstractJsonServlet
{
public:
	FileService fileService;
	LeaderBoardService ldbService;
	LeaderboardServlet(SessionService &, FileService , LeaderBoardService);

	void handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *);
};

#endif // LEADERBOARD_H
