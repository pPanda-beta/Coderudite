#include "userservice.h"

UserService::UserService(const UserMapper &_mapper):userMapper(_mapper)
{
}

bool UserService::login(User &trial_user) const
{
	UserMapper &&userMapper = static_cast<UserMapper>(this->userMapper);
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
