#include "CProgressWidget.h"

#include <QTimer>
CProgressWidget::CProgressWidget(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMinimizeButtonHint);
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	pMove = new QMovie(":/Image/Resources/Image/loading.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();
	QTimer::singleShot(1000 * 10, this, SLOT(on_slot_timeout()));

	btn_back->hide();
	btn_home->hide();
	
}

CProgressWidget::~CProgressWidget()
{
}

void CProgressWidget::setValue(QString strWeight, QString strHeight)
{
	label_weight->setText(strWeight);
	label_weight->setText(strHeight);
}



void CProgressWidget::on_slot_timeout()
{
	done(0);
}