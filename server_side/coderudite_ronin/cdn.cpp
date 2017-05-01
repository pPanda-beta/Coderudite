#include "cdn.h"
#include <QDebug>

#include <fstream>
#include <iostream>
#include <map>

map<string,string> mime;



CDN::CDN(const QDir& wwwrt, initializer_list<quint16> portList)
{
	base=wwwrt;
	start(portList);

	if(mime.empty())
	{
		string ext,typ;
		ifstream k(MAC2STR(SITEROOT)+"/data/mime_types.txt"s);

		while( k.is_open() and not k.eof())
		{
			k>>ext>>typ;
			mime[ext]=typ;
		}
	}
}


void CDN::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{

	qDebug()<<base.path()<<req->url().path()<<(req->url()==tr("/"));
	auto docname=base.path() + (req->url().path()==tr("/") ?tr("/index.html"):req->url().path()) ;

	QFile document(docname);

	if(not document.open(QFile::ReadOnly))
	{
		QByteArray body = "Sorry Not found";
		resp->addHeader("Content-Length", QByteArray::number(body.size()));
		resp->setStatusCode(ESTATUS_NOT_FOUND);
		resp->end(body);
		return;
	}

	try {
		auto nm=docname.toStdString();
		auto ext=nm.substr(nm.find_last_of('.'));
		resp->addHeader("Content-Type", mime[ext].data());
	} catch (...) {
		resp->addHeader("Content-Type", "application/octet-stream");
	}

	replyWith(resp, document.readAll());
}

