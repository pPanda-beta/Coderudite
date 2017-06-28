#include "leaderboardservice.h"
#include <unordered_map>

LeaderBoardService::LeaderBoardService(SubmissionMapper _smp)
	:submissionMapper(_smp)
{

}

vector<QStringList> LeaderBoardService::getCurrentLeaderBoard(const list<string> &problemIds)
{
//	static list<string> problemIds({"P001","P002","P003"});

	unordered_map <string, int> columnNoOf;
	int columnNo = 1;
	for(auto &pid : problemIds)
		columnNoOf[pid] = columnNo++;

	QStringList emptyRow;
	for(int i=0 ; i<columnNo; i++)
		emptyRow.append("N/A");

	unordered_map <string, QStringList> userVsSubmission;
	auto &&submissions=submissionMapper.getLatestSubmissionOfAllUsers();
	for(auto &subPtr : submissions)
	{
		auto &&row = userVsSubmission[subPtr->get_uid()];
		if(row.isEmpty())
			row = emptyRow;
		row[columnNoOf[subPtr->get_pid()]] =
				subPtr->get_status()
				+ "\n"s
				+ subPtr->get_timestamp();
	}

	vector<QStringList> leaderBoardData;
	leaderBoardData.reserve(userVsSubmission.size());

	for(auto &kv : userVsSubmission)
	{
		kv.second[0] = QString::fromStdString(kv.first);
		leaderBoardData.push_back(kv.second);
	}
	return leaderBoardData;
}
