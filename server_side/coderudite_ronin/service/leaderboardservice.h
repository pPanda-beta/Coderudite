#ifndef LEADERBOARDSERVICE_H
#define LEADERBOARDSERVICE_H

#include <QJsonArray>

#include <mapper/submissionmapper.h>



class LeaderBoardService
{
public:
	SubmissionMapper submissionMapper;
	LeaderBoardService(SubmissionMapper _smp);

	vector<QStringList> getCurrentLeaderBoard(const list<string> &);
};

#endif // LEADERBOARDSERVICE_H