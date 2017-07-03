#include "submission.h"
#include <utility>
#include <tuple>



DEFN_GETTERS_AND_SETTERS_OF(
		(Submission, QStringEx, sid),
		(Submission, QStringEx, pname),
		(Submission, QStringEx, status),
		(Submission, QStringEx, error),
		(Submission, QStringEx, src),
		(Submission, QStringEx, lang),
		(Submission, QStringEx, difficulty),
		(Submission, QStringEx, uid),
		(Submission, QStringEx, pid),
		(Submission, QStringEx, timestamp)
		);

Submission::Submission(QStringEx sid, QStringEx pname, QStringEx status, QStringEx error, QStringEx src, QStringEx lang, QStringEx difficulty, QStringEx uid, QStringEx pid, QStringEx timestamp)
{
	std::tie(this->sid, this->pname, this->status,
			 this->error, this->src, this->lang,
			 this->difficulty, this->uid, this->pid, this->timestamp)
			= std::make_tuple( sid, pname, status,
							   error, src, lang,
							   difficulty, uid, pid,timestamp);
}
