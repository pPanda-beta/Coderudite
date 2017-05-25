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
			(QString, error),
			(QString, src),
			(QString, lang),
			(QString, type),
			(QString, uid),
			(QString, pid)
			);
	QStringEx sid, pname, error, src, lang, type, uid, pid;
public:

	DECL_GETTERS_AND_SETTERS_OF(
				(QStringEx, sid),
				(QStringEx, pname),
				(QStringEx, error),
				(QStringEx, src),
				(QStringEx, lang),
				(QStringEx, type),
				(QStringEx, uid),
				(QStringEx, pid)
				);
};

#endif // SUBMISSION_H
