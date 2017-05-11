#ifndef ABSTRACTMAPPER_H
#define ABSTRACTMAPPER_H

#include "sqlite_modern_cpp.h"

using namespace std;
using namespace sqlite;

struct AbstractMapper
{
	database db;

	AbstractMapper();
};

#endif // ABSTRACTMAPPER_H
