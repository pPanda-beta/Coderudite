#ifndef LEADERBOARDSERVICE_H
#define LEADERBOARDSERVICE_H

#include <QJsonArray>

#include <mapper/submissionmapper.h>
#include <mapper/userinfomapper.h>



class LeaderBoardService
{
public:
	SubmissionMapper submissionMapper;
	UserInfoMapper userInfoMapper;
	LeaderBoardService(SubmissionMapper _smp, UserInfoMapper &);

	vector<QStringList> getCurrentLeaderBoard(const QStringList &problemIds, const vector<int> &scores);
};

#endif // LEADERBOARDSERVICE_H
