#include "userservice.h"

UserService::UserService(const UserMapper &_mapper, const UserInfoMapper &_uinfo_mapper)
	:userMapper(_mapper),
	  userInfoMapper(_uinfo_mapper)
{
}

bool UserService::login(User &trial_user)
{
//	UserMapper &&userMapper = static_cast<UserMapper>(this->userMapper);
	try
	{
		auto actual_userP=userMapper.getUserByEmail(trial_user.get_email());
		if(trial_user.get_password() == actual_userP->get_password())
		{
			trial_user.set_id(actual_userP->get_id());
			return true;
		}
	}
	catch (...)
	{
	}
	return false;
}

bool UserService::register_user(User &user)
{
	return userMapper.insertUser(user);
}

void UserService::updateUserInfo(User &user, const QVariantHash &info)
{
	auto userid = userMapper.getUserByEmail(user.get_email())->get_id();
	for(auto i = info.begin(); i != info.end(); ++i)
		if(i.key() != "password")
			userInfoMapper.updateUserInfo(userid, i.key().toStdString(), i.value().toString().toStdString());

}
