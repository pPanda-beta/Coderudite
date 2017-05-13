#ifndef USER_H
#define USER_H

#include <QObject>
#include <string>

using namespace std;

struct User : public QObject
{
	Q_OBJECT
	Q_PROPERTY(string email READ get_email WRITE set_email)
	Q_PROPERTY(string password READ get_password WRITE set_password)

	User(string, string _password="");

	string get_email() const;
	User& set_email(const string &value);

	string get_password() const;
	User& set_password(const string &value);

private :
	string email, password;
};

#endif // USER_H
