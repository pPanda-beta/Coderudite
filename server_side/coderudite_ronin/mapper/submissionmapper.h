#ifndef SUBMISSIONMAPPER_H
#define SUBMISSIONMAPPER_H

#include "abstractmapper.h"
#include <model/submission.h>
#include <list>
#include <tuple>


class SubmissionMapper : public AbstractMapper
{
public:
	SubmissionMapper();

	bool insertSubmisssion(Submission &);
	shared_ptr<Submission> getSubmissionById(string sid);
	list<string> getSubmissionIdsOfUser(string uid);
	void update(const Submission &submission);
	list<shared_ptr<Submission>> getLatestSubmissionOfAllUsers();
	list<shared_ptr<Submission>> getAllWaitingSubmissions();
};

#endif // SUBMISSIONMAPPER_H
