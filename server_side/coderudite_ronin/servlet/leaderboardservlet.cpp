#include "leaderboardservlet.h"

LeaderboardServlet::LeaderboardServlet(SessionService &sp, FileService fsv, LeaderBoardService ldbsv)
	: fileService(fsv),
	  ldbService(ldbsv),
	  AbstractJsonServlet (sp)
{

}

void LeaderboardServlet::handle_parsed_request_on_end(Session &, const QJsonObject &, QHttpResponse *resp)
{
	auto problemIds = fileService.getProblemIds();

	vector<int> scores;
	scores.reserve(problemIds.size());

	QStringList thead({"User id"});

	for(auto &pid : problemIds)
	{
		auto problem = fileService.getProblem(pid);
		thead.push_back(problem["name"].toString());
		scores.push_back(problem["score"].toInt());
	}
	thead.push_back("Score");
	auto tbody = ldbService.getCurrentLeaderBoard(problemIds, scores);

	QJsonArray bodyOfTable;
	for(auto &row : tbody)
		bodyOfTable.push_back(QJsonArray::fromStringList(row));

	QJsonObject ldbTable;
	ldbTable.insert("header", QJsonArray::fromStringList(thead));
	ldbTable.insert("body", bodyOfTable);

	replyWithJson(resp, QJsonDocument(ldbTable));
}
