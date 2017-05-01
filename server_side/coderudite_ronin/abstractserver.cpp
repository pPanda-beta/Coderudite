#include "abstractserver.h"

AbstractServer::AbstractServer()
{

}


bool AbstractServer::start(initializer_list<quint16> &portList)
{

	for(auto &port:portList)
	{
		auto &ser=servers[port];
		if(not ser)
			ser->deleteLater();
		ser=new QHttpServer(this);
		ser->listen(QString::number(port), [this](auto req, auto resp){
			this->handleRequest(req,resp);
		});
	//	connect(ser, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
	//			this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));
	//	connect(ser,&QHttpServer::newRequest,this,&AbstractServer::handleRequest);
	}
	return true;
}

AbstractServer::~AbstractServer()
{
	for(auto &t:servers)
	{
		t.second->stopListening();
		t.second->deleteLater();
	}
}
