#ifndef USER_H
#define USER_H

#include <QObject>
#include "qstringex.h"
#include "bean.hxx"

using namespace std;

struct User : public QObject
{
	Q_OBJECT

	DECL_Q_PROPERTIES(
					(QString, id),
					(QString, email),
					(QString, password)
			);
public:
	User(const User&)=default;
	User(QStringEx, QStringEx _password="", QStringEx _id="");

	DECL_GETTERS_AND_SETTERS_OF(
				(QStringEx, id),
				(QStringEx, email),
				(QStringEx, password)
		);

private :
	QStringEx id, email, password;
};

#endif // USER_H
