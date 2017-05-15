#include "user.h"


User::User( QStringEx _email, QStringEx _password, QStringEx _id)
	:id(_id),
	  email(_email),
	  password(_password)
{
}

QStringEx User::get_password() const
{
	return password;
}

User& User::set_password(const QStringEx &value)
{
	password = value;
	return *this;
}

QStringEx User::get_email() const
{
	return email;
}

User& User::set_email(const QStringEx &value)
{
	email = value;
	return *this;
}

QStringEx User::get_id() const
{
	return id;
}

User& User::set_id(const QStringEx &value)
{
	id = value;
	return *this;
}

