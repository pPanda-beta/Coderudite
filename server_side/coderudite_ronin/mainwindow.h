#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "cdnview.h"
#include "run_server_view.h"
#include "contesthost_server_view.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_lnchCDN_clicked();

	void on_lnchRunSrv_clicked();

	void on_lnchCHostSrv_clicked();

private:
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
