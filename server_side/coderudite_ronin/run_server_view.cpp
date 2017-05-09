#include "run_server_view.h"
#include "ui_run_server_view.h"

run_server_view::run_server_view(QWidget *parent) :
	QFrame(parent),
	ui(new Ui::run_server_view)
{
	ui->setupUi(this);
	m_ldrs=new DedicatedRunServer(MAC2STR(APPROOT)+tr("/data/temp"), {5553,380});
}

run_server_view::~run_server_view()
{
	delete ui;
	delete m_ldrs;
}

void run_server_view::on_bt1_clicked()
{
	quint16 newPort=ui->newport->value();
	if(m_ldrs->servers.find(newPort)==m_ldrs->servers.end())
		ui->ports1->addItem(QString::number(newPort));
	initializer_list<quint16> freshPort = { newPort};
	m_ldrs->start(freshPort);
}

void run_server_view::on_bt2_clicked()
{
	if(ui->ports1->count()>0)
	{
		auto selPort=ui->ports1->currentItem()->text().toUShort();
		m_ldrs->servers[selPort]->stopListening();
		m_ldrs->servers[selPort]->deleteLater();
		m_ldrs->servers.erase(selPort);
		ui->ports1->takeItem(ui->ports1->currentRow());
	}
}
