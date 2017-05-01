#ifndef RUN_SERVER_VIEW_H
#define RUN_SERVER_VIEW_H

#include <QFrame>
#include "dedicatedrunserver.h"

namespace Ui {
class run_server_view;
}

class run_server_view : public QFrame
{
	Q_OBJECT

public:
	explicit run_server_view(QWidget *parent = 0);
	~run_server_view();

	DedicatedRunServer *m_ldrs;

private slots:
	void on_bt1_clicked();

	void on_bt2_clicked();

private:
	Ui::run_server_view *ui;
};

#endif // RUN_SERVER_VIEW_H
