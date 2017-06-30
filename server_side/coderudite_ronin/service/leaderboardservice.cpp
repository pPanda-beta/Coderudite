#include "leaderboardservice.h"
#include <unordered_map>


LeaderBoardService::LeaderBoardService(SubmissionMapper _smp, UserInfoMapper &_uinfomp)
	:submissionMapper(_smp),
	userInfoMapper(_uinfomp)
{

}

vector<QStringList> LeaderBoardService::getCurrentLeaderBoard(const QStringList &problemIds, const vector<int> &scores)
{
//	static list<string> problemIds({"P001","P002","P003"});

	unordered_map <string, int> columnNoOf;
	int columnNo = 1;
	for(auto &pid : problemIds)
		columnNoOf[pid.toStdString()] = columnNo++;

	QStringList emptyRow;
	for(int i=0 ; i<columnNo; i++)
		emptyRow.append("N/A");

	unordered_map <string, QStringList> userVsSubmission;
	unordered_map <string, int> scoreOfUser;

	auto &&submissions=submissionMapper.getLatestSubmissionOfAllUsers();
	for(auto &subPtr : submissions)
	{
		auto &&row = userVsSubmission[subPtr->get_uid()];
		if(row.isEmpty())
			row = emptyRow;
		auto col_i = columnNoOf[subPtr->get_pid()];
		row[col_i] = subPtr->get_status()
					+ "\n"s
					+ subPtr->get_timestamp();

		if(subPtr->get_status()=="SUCC")
			scoreOfUser[subPtr->get_uid()] += scores[col_i-1];
	}

	vector<QStringList> leaderBoardData;
	leaderBoardData.reserve(userVsSubmission.size());

	for(auto &kv : userVsSubmission)
	{
		try {
			auto uid = kv.first;
			auto fname = userInfoMapper.getInfoOfUser(uid,"firstName");
			auto lname = userInfoMapper.getInfoOfUser(uid,"lastName");
			kv.second[0] = QString::fromStdString(fname+" "+lname);
		} catch (...) {
			kv.second[0] = "Annonymous User";
		}

		kv.second.append(QString::number(scoreOfUser[kv.first]));
		leaderBoardData.push_back(kv.second);
	}
	return leaderBoardData;
}
