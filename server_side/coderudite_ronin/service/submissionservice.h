#ifndef SUBMISSIONSERVICE_H
#define SUBMISSIONSERVICE_H

#include <mapper/submissionmapper.h>



class SubmissionService
{
public:
	SubmissionMapper submissionMapper;
	SubmissionService( const SubmissionMapper &);

	void submit(const string& userid, Submission &submission);
	QJsonArray getSubmissionIdsOf(const string& userid);
	QJsonObject getSubmissionById(const string &sid);
};

#endif // SUBMISSIONSERVICE_H
