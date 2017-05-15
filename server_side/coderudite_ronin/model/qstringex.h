#ifndef QSTRINGEX_H
#define QSTRINGEX_H

#include <string>
#include <QString>
#include <sqlite_modern_cpp.h>

class QStringEx : public QString
{
public:
	using QString::QString;

	QStringEx(const QString &other="");
	QStringEx(const std::string &other);
	operator std::string()const;
};

//SHOULD NOT BE A MEMBER	op+(a1,b1) => a1->a, b1->b, op+(a,b) | a1 and/or b1 can be anything
QStringEx operator+(const QStringEx &a, const QStringEx &b);

//DB handling methods (non-member)
sqlite::database_binder& operator << (sqlite::database_binder&& db, const QStringEx& val);
sqlite::database_binder& operator << (sqlite::database_binder& db, const QStringEx& val);

#endif // QSTRINGEX_H
