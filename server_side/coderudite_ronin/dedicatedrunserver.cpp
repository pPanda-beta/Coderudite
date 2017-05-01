#include "dedicatedrunserver.h"

DedicatedRunServer::DedicatedRunServer(const QDir& runrt, initializer_list<quint16> portlist)
{
	base = runrt;
	start(portlist);
}


void DedicatedRunServer::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
	req->collectData(20*1024*1024);
	req->onEnd([=]
	{
		string form_data = req->collectedData().toStdString();
		auto &&fields = parsePOST(form_data);

//		qDebug()<<form_data.data()<<"\n|||";
//		for(auto &t:fields)
//		{
//			qDebug()<<t.first.data()<<":" << t.second.data();
//		}

		Solution sol(fields["source"], fields["type"]);
		Run run(sol);
		RunResult result = run.execute(fields["inp"], 1500);


		static QString statusToString[] = { "SUCC", "CTE", "RTE", "TLE", "ERR" };

		QJsonObject resultJSON
		{
			{ "status", statusToString[result.status]},
			{ "src", result.m_src.getSource().data() },
			{ "input_data", result.m_inp.str().data() },
			{ "output_data", result.m_oup.str().data()},
			{ "errors", result.m_err.str().data() }
		};

		QByteArray doc = QJsonDocument(resultJSON).toJson();
		replyWith(resp, doc);
	});
}



