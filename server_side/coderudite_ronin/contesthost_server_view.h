#ifndef CONTESTHOST_SERVER_VIEW_H
#define CONTESTHOST_SERVER_VIEW_H

#include <QFrame>
#include "contesthostserver.h"

namespace Ui {
class contesthost_server_view;
}

class contesthost_server_view : public QFrame
{
	Q_OBJECT

public:
	explicit contesthost_server_view(QWidget *parent = 0);
	~contesthost_server_view();

	ContestHostServer *m_ldrs;

private slots:
	void on_bt1_clicked();

	void on_bt2_clicked();

private:
	Ui::contesthost_server_view *ui;
};

#endif // CONTESTHOST_SERVER_VIEW_H
