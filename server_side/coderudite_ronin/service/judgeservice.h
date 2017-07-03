#ifndef JUDGESERVICE_H
#define JUDGESERVICE_H

#include "eventservice.h"
#include "fileservice.h"
#include <condition_variable>
#include <vector>
#include <memory>
#include <atomic>
#include <QThreadPool>
#include <mapper/submissionmapper.h>
#include "../model/submission.h"
#include "../model/run.h"
#include "../model/solution.h"


class JudgeService
{
	SubmissionMapper &submissionMapper;
	EventService	&eventService;
	FileService		&fileService;

	condition_variable_any cv;

	QThreadPool *pool;
	atomic<bool> running;

	vector<shared_ptr<Submission>> pendingSubmissions;
	vector<shared_ptr<Run>> runnableSolutions;
	vector<shared_ptr<RunResult>> runResults;

	void prepareRuns();
	void runSubmissionCodes();
	void verifyOutputsAndUpdateSubmissions();

	void mainLoop();
public:
	JudgeService(SubmissionMapper &, EventService &, FileService &);

	void processPendimgSubmissions();

	~JudgeService();
};

#endif // JUDGESERVICE_H
