#include "qstringex.h"


QStringEx::QStringEx(const QString &other):QString(other)
{
}

QStringEx::QStringEx(const std::string &other):QString (fromStdString(other))
{
}

QStringEx::operator std::string() const
{
	return toStdString();
}

QStringEx operator+(const QStringEx &a, const QStringEx &b)
{
	return static_cast<QString>(a)+static_cast<QString>(b);
}

sqlite::database_binder& operator << (sqlite::database_binder&& db, const QStringEx& val)
{
	return db << (std::string)val;
}

sqlite::database_binder& operator << (sqlite::database_binder& db, const QStringEx& val)
{
	return db << (std::string)val;
}


