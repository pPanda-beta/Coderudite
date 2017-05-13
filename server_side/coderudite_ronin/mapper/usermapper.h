#ifndef USERMAPPER_H
#define USERMAPPER_H

#include "abstractmapper.h"
#include "../model/user.h"

struct UserMapper : public AbstractMapper
{
	UserMapper();

	bool insertUser(const User&);
};

#endif // USERMAPPER_H

