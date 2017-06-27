#ifndef LEADERBOARDSERVICE_H
#define LEADERBOARDSERVICE_H

#include <QJsonArray>

#include <mapper/submissionmapper.h>



class LeaderBoardService
{
public:
	SubmissionMapper submissionMapper;
	LeaderBoardService(SubmissionMapper _smp);

	list<QStringList> getCurrentLeaderBoard();
};

#endif // LEADERBOARDSERVICE_H
