#include "cdnview.h"
#include "ui_cdnview.h"

CDNview::CDNview(QWidget *parent) :
	QFrame(parent),
	ui(new Ui::CDNview)
{
	ui->setupUi(this);

	m_cdn=new CDN(MAC2STR(SITEROOT)+tr("/data/webroot"),{8080,80});
}

CDNview::~CDNview()
{
	delete ui;
	delete m_cdn;
}

void CDNview::on_bt1_clicked()
{
	quint16 newPort=ui->newport->value();
	if(m_cdn->servers.find(newPort)==m_cdn->servers.end())
		ui->ports1->addItem(QString::number(newPort));
	initializer_list<quint16> freshPort = { newPort};
	m_cdn->start(freshPort);
}

void CDNview::on_bt2_clicked()
{
	if(ui->ports1->count()>0)
	{
		auto selPort=ui->ports1->currentItem()->text().toUShort();
//		m_cdn->servers[selPort]->close();
		m_cdn->servers[selPort]->deleteLater();
		m_cdn->servers.erase(selPort);
		ui->ports1->takeItem(ui->ports1->currentRow());
	}
}
