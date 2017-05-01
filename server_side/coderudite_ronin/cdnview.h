#ifndef CDNVIEW_H
#define CDNVIEW_H

#include "cdn.h"
#include <QFrame>


namespace Ui {
class CDNview;
}

class CDNview : public QFrame
{
	Q_OBJECT

public:
	explicit CDNview(QWidget *parent = 0);
	~CDNview();
	CDN *m_cdn;
private slots:
	void on_bt1_clicked();

	void on_bt2_clicked();

private:
	Ui::CDNview *ui;
};

#endif // CDNVIEW_H
