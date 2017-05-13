#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

using namespace std;

struct User : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString email READ get_email WRITE set_email)
	Q_PROPERTY(QString password READ get_password WRITE set_password)

public:
	User(QString, QString _password="");

	QString get_email() const;
	User& set_email(const QString &value);

	QString get_password() const;
	User& set_password(const QString &value);

private :
	QString email, password;
};

#endif // USER_H
