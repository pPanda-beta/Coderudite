#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>
#include <string>

using namespace std;

struct User : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString id READ get_id WRITE set_id)
	Q_PROPERTY(QString email READ get_email WRITE set_email)
	Q_PROPERTY(QString password READ get_password WRITE set_password)

public:
	User(auto&& ...args):User(QString::fromStdString(args)...)	{}

	User(const User&)=default;
	User(QString, QString _password="", QString _id="");

	QString get_id() const;
	User& set_id(const QString &value);

	QString get_email() const;
	User& set_email(const QString &value);

	QString get_password() const;
	User& set_password(const QString &value);

private :
	QString id, email, password;
};

#endif // USER_H
