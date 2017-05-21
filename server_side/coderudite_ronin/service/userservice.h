#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "mapper/usermapper.h"

class UserService
{
public:
	UserMapper userMapper;
	UserService(const UserMapper &);

	bool login(User &)const;
};

#endif // USERSERVICE_H
