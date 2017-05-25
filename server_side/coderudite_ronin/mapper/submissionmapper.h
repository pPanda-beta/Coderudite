#ifndef SUBMISSIONMAPPER_H
#define SUBMISSIONMAPPER_H

#include "abstractmapper.h"
#include <model/submission.h>
#include <list>


class SubmissionMapper : public AbstractMapper
{
public:
	SubmissionMapper();

	bool insertSubmisssion(Submission &);
	shared_ptr<Submission> getSubmissionById(string sid);
	list<string> getSubmissionIdsOfUser(string uid);
};

#endif // SUBMISSIONMAPPER_H
