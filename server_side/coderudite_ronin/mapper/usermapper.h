#ifndef USERMAPPER_H
#define USERMAPPER_H

#include "abstractmapper.h"
#include "../model/user.h"
#include <memory>

struct UserMapper : public AbstractMapper
{
	UserMapper();

	shared_ptr<User> getUserByEmail(string);
	bool insertUser(const User&);
};

#endif // USERMAPPER_H

