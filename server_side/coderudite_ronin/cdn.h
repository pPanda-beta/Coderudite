#ifndef CDN_H
#define CDN_H

#include "abstractserver.h"
#include <QDir>



struct CDN : public AbstractServer
{
	QDir base;
//	CDN()=default;
	CDN(const QDir& wwwrt, initializer_list<quint16> portlist);
	void handleRequest(QHttpRequest *, QHttpResponse *);
};

#endif // CDN_H
