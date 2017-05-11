#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//new CDN(QDir::currentPath()+tr("/data/basic_1"),{1234,80});
	//system("ls ../../.. -al");
//	system("cd ../../../../../..");
//	system("ls");
//	system("pwd");
	on_lnchCDN_clicked();
	on_lnchRunSrv_clicked();
	on_lnchCHostSrv_clicked();
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_lnchCDN_clicked()
{
	ui->tabWidget->addTab(new CDNview,tr("CDN"));
}

void MainWindow::on_lnchRunSrv_clicked()
{
	ui->tabWidget->addTab(new run_server_view,tr("Run Server"));
}

void MainWindow::on_lnchCHostSrv_clicked()
{
	ui->tabWidget->addTab(new contesthost_server_view,tr("Contest Host Server"));
}
