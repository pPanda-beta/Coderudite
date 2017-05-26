#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "mapper/usermapper.h"

class UserService
{
public:
	UserMapper userMapper;
	UserService(const UserMapper &);

	bool login(User &);
	bool register_user(User &);
};

#endif // USERSERVICE_H
