#include "judgeservice.h"
#include <thread>
#include <future>
#include <list>
#include <algorithm>
#include "../concurrency_helpers.hxx"

using namespace std;


JudgeService::JudgeService(SubmissionMapper &smp, EventService &esr, FileService &fsr)
	: submissionMapper(smp),
	  eventService(esr),
	  fileService(fsr)
{
	running = true;
	pool = new QThreadPool(qApp);
}

void JudgeService::prepareRuns()
{
	auto &&listOfSubmissions = submissionMapper.getAllWaitingSubmissions();
	pendingSubmissions = {listOfSubmissions.begin(), listOfSubmissions.end()};

	async_transform(pool, pendingSubmissions, runnableSolutions, [](auto subP)
	{
		Solution sol(subP->get_src(), subP->get_lang());
		return  make_shared<Run>(sol);
	});
}

void JudgeService::runSubmissionCodes()
{
	for(int i=0; i<pendingSubmissions.size(); i++)
	{
		auto inputData = fileService.getContentsOfFile(problemDir+"/"s+pendingSubmissions[i]->get_pid().toStdString()+".input"s);
		auto runResult = runnableSolutions[i]->execute(inputData.toStdString(), 2000);
		runResults[i] = make_shared<RunResult>(runResult);
	}
}

void JudgeService::verifyOutputsAndUpdateSubmissions()
{
	for(int i=0; i<pendingSubmissions.size(); i++)
	{
		auto outputData = fileService.getContentsOfFile(problemDir+"/"s+pendingSubmissions[i]->get_pid().toStdString()+".output"s);
		auto &result = *runResults[i];
		string output = result.m_oup.str()+"";
		if(result.status == RunResult::SUCC)
		{
	//		convertCRLF2LF(output);
	//		convertCRLF2LF(outputData);
			if(output != outputData.toStdString())
			{
				result.status = RunResult::ERR;
				result.m_err.str("Test case failed : Wrong Answer");
			}
		}

		static QString statusToString[] = { "SUCC", "CTE", "RTE", "TLE", "ERR" };

		pendingSubmissions[i]
				->set_status(statusToString[result.status])
				.set_error(result.m_err.str());
		submissionMapper.update(*pendingSubmissions[i]);
	}
}

void JudgeService::mainLoop()
{
	mutex mt;
	while(running)
	{
		cv.wait(mt);
		if(not running)
			break;
		prepareRuns();
		runSubmissionCodes();
		verifyOutputsAndUpdateSubmissions();
	}
}

void JudgeService::processPendimgSubmissions()
{
	cv.notify_all();
}

JudgeService::~JudgeService()
{
	running = false;
}
