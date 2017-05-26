#include "submissionservlet.hpp"

#include <QJsonObject>
#include <QJsonArray>
#include "../mapper/qobjecthelper.h"
#include "../constants.hxx"
#include "../helpers.hxx"
#include <model/run.h>
#include <model/solution.h>

SubmissionServlet::SubmissionServlet(SessionService &_sp, FileService &_fp, SubmissionService &sbsr)
	: AbstractJsonServlet (_sp),
	  fileService(_fp),
	  submissionService(sbsr)
{

}

QJsonObject judge(Submission &submission, FileService &fileService, SubmissionService &submissionService)
{
	auto inputData = fileService.getContentsOfFile(problemDir+"/"s+submission.get_pid().toStdString()+".input"s);
	auto outputData = fileService.getContentsOfFile(problemDir+"/"s+submission.get_pid().toStdString()+".output"s);
	Solution sol(submission.get_src(), submission.get_lang());
	Run run(sol);
	RunResult result = run.execute(inputData.data(), 2000);

	static QString statusToString[] = { "SUCC", "CTE", "RTE", "TLE", "ERR" };

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

	QJsonObject resultJSON
	{
		{ "status", statusToString[result.status]},
		{ "src", result.m_src.getSource().data() },
		{ "error", result.m_err.str().data() }
	};

	submission.set_status(statusToString[result.status])
			.set_error(result.m_err.str());
	submissionService.updateSubmissionDetails(submission);

	return resultJSON;
}

void SubmissionServlet::handle_parsed_request_on_end(Session &session, const QJsonObject &submissionJson, QHttpResponse *resp)
{
	QJsonDocument reply;
	qDebug()<<session.req->url().fileName();
	if(session.req->url().fileName() == "getById")
	{
		reply = (QJsonDocument) submissionService.getSubmissionById(submissionJson["sid"].toString().toStdString());
	}
	else if(session.req->url().fileName() == "getAllIds")
	{
		reply = (QJsonDocument) submissionService.getSubmissionIdsOf(session.userid);
	}
	else if(session.req->url().fileName() == "submit")
	{
		Submission submission;
		QObjectHelper::qjson2qobject(submissionJson, &submission);
		submissionService.submit(session.userid, submission);

		reply = (QJsonDocument) judge(submission, fileService, submissionService);
//		reply = QJsonDocument::fromJson("{ \"message\" : \" successfully submitted\" }");
	}
	replyWithJson(resp,reply);
}
