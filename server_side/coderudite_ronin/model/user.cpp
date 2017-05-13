#include "user.h"


User::User( QString _email, QString _password, QString _id)
	:id(_id),
	  email(_email),
	  password(_password)
{
}

QString User::get_password() const
{
	return password;
}

User& User::set_password(const QString &value)
{
	password = value;
	return *this;
}

QString User::get_email() const
{
	return email;
}

User& User::set_email(const QString &value)
{
	email = value;
	return *this;
}

QString User::get_id() const
{
	return id;
}

User& User::set_id(const QString &value)
{
	id = value;
	return *this;
}

