#ifndef ABSTRACTMAPPER_H
#define ABSTRACTMAPPER_H

#include "sqlite_modern_cpp.h"
#include "constants.hxx"

using namespace std;
using namespace sqlite;

struct AbstractMapper
{
	database db;

	AbstractMapper(database _db=universal_db);

	static database universal_db;
};

#endif // ABSTRACTMAPPER_H
