#ifndef CDN_H
#define CDN_H

#include "abstractserver.h"
#include <QDir>


#define Y2X(X)	#X
#define MAC2STR(Y) Y2X(Y)


struct CDN : public AbstractServer
{
	QDir base;
//	CDN()=default;
	CDN(const QDir& wwwrt, initializer_list<quint16> portlist);
	void handleRequest(QHttpRequest *, QHttpResponse *);
};

#endif // CDN_H
