#include "user.h"


User::User(string _email, string _password):email(_email),password(_password)
{
}

string User::get_password() const
{
	return password;
}

User& User::set_password(const string &value)
{
	password = value;
	return *this;
}

string User::get_email() const
{
	return email;
}

User& User::set_email(const string &value)
{
	email = value;
	return *this;
}

