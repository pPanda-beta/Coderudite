#ifndef USERSERVICE_H
#define USERSERVICE_H

#include "mapper/usermapper.h"

#include <mapper/userinfomapper.h>

class UserService
{
public:
	UserMapper userMapper;
	UserInfoMapper userInfoMapper;
	UserService(const UserMapper &, const UserInfoMapper& );

	bool login(User &);
	bool register_user(User &);
	void updateUserInfo(User &,const QVariantHash&);
};

#endif // USERSERVICE_H
