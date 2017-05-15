#include "usermapper.h"
#include <QDebug>

const char* createUserTableSql = R"sql1(
CREATE TABLE IF NOT EXISTS user (
	_id integer primary key autoincrement not null,
	email text not null unique,
	password text not null
);
)sql1";


const char* selectUserByEmailSql = R"sql1(
SELECT * FROM user
WHERE email = ? ;
)sql1";


UserMapper::UserMapper()
{
	db<<createUserTableSql;
}


shared_ptr<User> UserMapper::getUserByEmail(string trialEmail)
{
	string id, email, password;
	db<<selectUserByEmailSql<<trialEmail>>tie(id,email,password);
	if(trialEmail != email)
		throw ("User not found with email : "+ trialEmail);

	return make_shared<User>(email,password,id);
}



bool UserMapper::insertUser(const User &user)
{
	try
	{
		getUserByEmail(user.get_email());
		return false;
	}	//should throw exception
	catch (...)	{}

	db<<"INSERT INTO user (email, password) values(?,?) ;"
	 <<user.get_email()
	<<user.get_password();
	return true;
}
