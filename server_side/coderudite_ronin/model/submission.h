#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <QObject>
#include "qstringex.h"
#include "bean.hxx"

class Submission : public QObject
{
	Q_OBJECT

	DECL_Q_PROPERTIES(
			(QString, sid),
			(QString, pname),
			(QString, status),	// CTE/RTE/...
			(QString, error),
			(QString, src),
			(QString, lang),
			(QString, difficulty),
			(QString, uid),
			(QString, pid),
			(QString, timestamp)
			);
	QStringEx sid, pname, status, error, src, lang, difficulty, uid, pid, timestamp;
public:
	Submission() = default;
	Submission(QStringEx sid, QStringEx pname, QStringEx status, QStringEx error, QStringEx src, QStringEx lang, QStringEx difficulty, QStringEx uid, QStringEx pid, QStringEx timestamp);
	DECL_GETTERS_AND_SETTERS_OF(
				(QStringEx, sid),
				(QStringEx, pname),
				(QStringEx, status),
				(QStringEx, error),
				(QStringEx, src),
				(QStringEx, lang),
				(QStringEx, difficulty),
				(QStringEx, uid),
				(QStringEx, pid),
				(QStringEx, timestamp)
				);
};

#endif // SUBMISSION_H
