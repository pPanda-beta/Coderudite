#include "userinfomapper.h"


const char* createUserInfoTableSql = R"sql1(
CREATE TABLE IF NOT EXISTS user_info (
	uid integer not null,
	key text not null,
	value text not null,
	CONSTRAINT unique_key_for_user UNIQUE ( uid, key )
);	)sql1";


UserInfoMapper::UserInfoMapper()
{
	db<<createUserInfoTableSql;
}

void UserInfoMapper::updateUserInfo(string userid, string key, string value)
{
	try
	{
		db<<"INSERT INTO user_info (uid,key,value) VALUES(?,?,?) ;"
		 <<userid<<key<<value;
	}
	catch(...)
	{
		db<<"UPDATE user_info "
			"SET value = ?"
			"WHERE uid = ? and key = ? ;"
		 <<value
		<<userid<<key;
	}
}

string UserInfoMapper::getInfoOfUser(string userid, string key)
{
	string value;
	db<<"SELECT value "
		"FROM user_info "
		"WHERE uid = ? and key = ? ; "
		<<userid<<key
		>>value;
	return value;
}

QVariantHash UserInfoMapper::getAllInfoOfUser(string userid)
{
	QVariantHash info;
	db<<"SELECT key, value "
		"FROM user_info "
		"WHERE uid = ? ; "
		<<userid
	   >>[&](string key, string value)
	{
		info.insert(QString::fromStdString(key), QString::fromStdString(value));
	};

	return info;
}
