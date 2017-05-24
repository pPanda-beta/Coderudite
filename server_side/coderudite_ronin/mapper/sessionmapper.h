#ifndef SESSIONMAPPER_H
#define SESSIONMAPPER_H

#include "abstractmapper.h"

#include <model/user.h>



struct SessionMapper : public AbstractMapper
{
	SessionMapper();

	string createSessionIdFor(const User&);
	string getUserIdFor(const string &);
	string getValueOf(string sid, string key) ;
	void setValueOf(string sid, string key, string value) ;
};

#endif // SESSIONMAPPER_H
