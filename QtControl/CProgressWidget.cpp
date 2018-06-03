#include "CProgressWidget.h"
#include <QTimer>
CProgressWidget::CProgressWidget(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	pMove = new QMovie(":/Image/Resources/Image/progree.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();
	QTimer::singleShot(1000 * 10, this, SLOT(on_slot_timeout()));
}

CProgressWidget::~CProgressWidget()
{
}


void CProgressWidget::on_slot_timeout()
{
	done(0);
}