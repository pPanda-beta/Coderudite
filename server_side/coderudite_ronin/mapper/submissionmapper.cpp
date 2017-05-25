#include "submissionmapper.h"

#include <collectors.h>

const char* createSubmissionTableSql = R"sql1(
CREATE TABLE IF NOT EXISTS submission (
	sid integer primary key autoincrement not null,
	pname text not null,
	status text not null,
	error text not null,
	src text not null,
	lang text not null,
	difficulty text not null,
	uid text not null,
	pid text not null
);
)sql1";

SubmissionMapper::SubmissionMapper()
{
	db<<createSubmissionTableSql;
}

bool SubmissionMapper::insertSubmisssion(Submission &submission)
{
	db<<"INSERT INTO submission (pname, status, error, src, lang, difficulty, uid, pid) "
		"values(?,?,?,?,?,?,?,?) ;"
	 <<submission.get_pname()
	<<submission.get_status()
	<<submission.get_error()
	<<submission.get_src()
	<<submission.get_lang()
	<<submission.get_difficulty()
	<<submission.get_uid()
	<<submission.get_pid();
}

shared_ptr<Submission> SubmissionMapper::getSubmissionById(string sid)
{
	string pname, status, error, src, lang, difficulty, uid, pid;

	db<<"SELECT * FROM submission "
		"WHERE sid=? ;"
	 <<sid
	>>tie(sid, pname, status, error, src, lang, difficulty, uid, pid);

	auto sbP = make_shared<Submission>();
	sbP->set_pname(pname)
			.set_status(status)
			.set_error(error)
			.set_src(src)
			.set_lang(lang)
			.set_difficulty(difficulty)
			.set_uid(uid)
			.set_pid(pid);
	return sbP;
}

list<string> SubmissionMapper::getSubmissionIdsOfUser(string uid)
{
	return db<<"SELECT sid FROM submission "
		"WHERE uid=?"
	 <<uid
	>>collect<string>::as<list,string>();
}
