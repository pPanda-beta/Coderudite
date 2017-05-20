
#ifndef HELPERS_HXX
#define HELPERS_HXX

#include <string>
#include <cstdio>
#include <regex>
#include <map>
#include "qhttpserver.hpp"
#include "qhttpserverresponse.hpp"
#include "qhttpserverrequest.hpp"


#define Y2X(X)	#X
#define MAC2STR(Y) Y2X(Y)


namespace
{
using namespace std;

using namespace qhttp;
using namespace qhttp::server;


auto convertCRLF2LF(auto &&str)
{
	int i=0, j=0;
	while( i < str.size()-1)
	{
		if(str[i]=='\r' and str[i+1]=='\n')
			i++;
		str[j++] = str[i++];
	}
	str[j]='\0';
	return str;
}


template<typename T>
T deHexFilter(const T &v)
{
	T org_v;
	org_v.reserve(v.size());
	for(size_t i=0; i<v.size(); i++)
		if(v[i]!='%')
			org_v+=v[i];
		else
		{
			int c;
			sscanf(v.data()+i+1,"%2x",&c);
			org_v+=c;
			i+=2;
		}
	return org_v;
}

map<string,string> parsePOST(auto &&req)
{
	string requestString(req);
	const static regex reg("[&]+");
	replace(requestString.begin(), requestString.end(), '+', ' ');

	map<string,string> parsed_req;

	for(sregex_token_iterator iter(begin(requestString),end(requestString),reg,-1),end ; iter!=end; ++iter)
	{
		string &&t=*iter;

		auto m=t.find_first_of('=');
		if(m==string::npos || m>=t.size()-1)
			parsed_req[t.substr(0,m)]="";
		else
			parsed_req[t.substr(0,m)]=deHexFilter(t.substr(m+1));
	}
	return parsed_req;
}
}


template<typename T>
void replyWith(QHttpResponse *resp, const T& doc, TStatusCode code)
{
	resp->addHeader("Content-Length", QByteArray::number(doc.size()));
	resp->addHeader("Access-Control-Allow-Origin"," * ");
	resp->addHeader("Access-Control-Allow-Headers","GET,POST,PUT");
	resp->setStatusCode(code);
	resp->end(QByteArray(doc.data()));
}

template<typename T>
void replyWith(QHttpResponse *resp, const T& doc)
{
	replyWith(resp,doc,ESTATUS_OK);
}

#endif // HELPERS_HXX
