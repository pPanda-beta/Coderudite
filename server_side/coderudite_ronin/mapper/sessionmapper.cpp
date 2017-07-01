#include "sessionmapper.h"

const char* createSessionTableSql = R"sql1(
CREATE TABLE IF NOT EXISTS session (
	sid integer primary key autoincrement not null,
	userid text not null
);	)sql1";

const char* createSessionDataTableSql = R"sql1(
CREATE TABLE IF NOT EXISTS session_data (
	sid text not null,
	key text not null,
	value text	,
	CONSTRAINT unique_key_for_session UNIQUE ( sid, key )
);	)sql1";

const char* selectSessionIdsByUserIdSql = R"sql1(
SELECT sid FROM session
WHERE userid = ? ;	)sql1";


const char* selectUserIdFromSessionIdSql = R"sql1(
SELECT userid FROM session
WHERE sid = ? ;		)sql1";



SessionMapper::SessionMapper()
{
	db<<createSessionTableSql;
	db<<createSessionDataTableSql;
}

string SessionMapper::createSessionIdFor(const User &user)
{
	db<<"INSERT INTO session (userid) VALUES (?) ;"
	 <<user.get_id();
	int last_row_index=db.last_insert_rowid()-1;
	int sid;
	db<<"SELECT sid FROM session LIMIT "+to_string(last_row_index)+",1 ;"
	>>sid;
	return to_string(sid);
}

string SessionMapper::getUserIdFor(const string &sid)
{
	string userid;
	db<<selectUserIdFromSessionIdSql
	 <<sid
	>>userid;
	return userid;
}

string SessionMapper::getValueOf(string sid, string key)
{
	string value;
	db<<"SELECT value FROM session_data WHERE sid = ? and key = ? ;"
	 <<sid<<key
	>>value;
	return value;
}

void SessionMapper::setValueOf(string sid, string key, string value)
{
	try
	{
		db<<"INSERT INTO session_data (sid,key,value) VALUES(?,?,?) ;"
		 <<sid<<key<<value;
	}
	catch(...)
	{
		db<<"UPDATE session_data "
			"SET value = ?"
			"WHERE sid = ? and key = ? ;"
		 <<value
		<<sid<<key;
	}
}
