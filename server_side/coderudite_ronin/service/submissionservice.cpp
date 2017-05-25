#include "submissionservice.h"

#include <QJsonArray>
#include <QJsonObject>
#include "../mapper/qobjecthelper.h"

SubmissionService::SubmissionService(const SubmissionMapper &_sbmp)
	:submissionMapper(_sbmp)
{

}

void SubmissionService::submit(const string &userid, Submission &submission)
{
	submission
			.set_uid(userid)
			.set_status("WAIT");
	submissionMapper.insertSubmisssion(submission);
}

QJsonArray SubmissionService::getSubmissionIdsOf(const string &userid)
{
	auto idStrings = submissionMapper.getSubmissionIdsOfUser(userid);
	QJsonArray ids;
	for(QStringEx id:idStrings)
		ids.push_back(id);
	return ids;
}

QJsonObject SubmissionService::getSubmissionById(const string &sid)
{
	auto submsnP = submissionMapper.getSubmissionById(sid);
	return QObjectHelper::qobject2qjson(submsnP.get());
}
