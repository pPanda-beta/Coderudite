#include "user.h"


User::User( QStringEx _email, QStringEx _password, QStringEx _id)
	:id(_id),
	  email(_email),
	  password(_password)
{
}

DEFN_GETTERS_AND_SETTERS_OF(
	(User, QStringEx, id),
	(User, QStringEx, email),
	(User, QStringEx, password)
);
