#ifndef USERINFOMAPPER_H
#define USERINFOMAPPER_H

#include "abstractmapper.h"

#include <QVariantHash>



struct UserInfoMapper : public AbstractMapper
{
public:
	UserInfoMapper();

	void updateUserInfo(string userid, string key, string value);
	string getInfoOfUser(string userid,string key);
	QVariantHash getAllInfoOfUser(string userid);
};

#endif // USERINFOMAPPER_H
