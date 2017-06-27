#include "leaderboardservice.h"
#include <unordered_map>

LeaderBoardService::LeaderBoardService(SubmissionMapper _smp)
	:submissionMapper(_smp)
{

}

list<QStringList> LeaderBoardService::getCurrentLeaderBoard()
{
	static QStringList problemIds({"P001","P002","P003"});

	list<QStringList> leaderBoardData;
	unordered_map <string, QStringList> userVsSubmission;
	unordered_map <string, int> columnNoOf;

	for(int i=0, columnNo=1; i<problemIds.size(); i++, columnNo++)
		columnNoOf[problemIds[i].toStdString()]=columnNo;

	auto &&submissions=submissionMapper.getLatestSubmissionOfAllUsers();
	for(auto &subPtr : submissions)
	{
		userVsSubmission[subPtr->get_uid()]
				.insert(columnNoOf[subPtr->get_pid()],
				subPtr->get_status()
				+ "\n"s
				+ subPtr->get_timestamp());
	}

	for(auto kv : userVsSubmission)
	{
		kv.second.insert(0, QString::fromStdString(kv.first));
		leaderBoardData.push_back(kv.second);
	}
	return leaderBoardData;
}
