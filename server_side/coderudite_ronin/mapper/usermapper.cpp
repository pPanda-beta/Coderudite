#include "usermapper.h"

const char* createUserTableSql = R"sql1(
CREATE TABLE IF NOT EXISTS user (
	_id integer primary key autoincrement not null,
	email text not null,
	password text not null
);
)sql1";


UserMapper::UserMapper()
{
	db<<createUserTableSql;
}

bool UserMapper::insertUser(const User &)
{//Not implemented

}
