#include "CQRWidget.h"
#include <QTimer>
CQRWidget::CQRWidget(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);
	pMove = new QMovie(":/Image/Resources/Image/QR.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();


	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	connect(btn_back, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
	connect(btn_home, SIGNAL(clicked()), this, SLOT(on_btnHome_clicked()));
	QTimer::singleShot(1000 * 10, this, SLOT(on_slot_timeout()));
}

CQRWidget::~CQRWidget()
{
}

void CQRWidget::Init(WIDGET_TYPE types)
{

	if (types & MSGBOX_GET)
	{
		label_title->setText("请扫描二维码取件");
	}
	if (types & MSGBOX_SAVE)
	{
		label_title->setText("请扫描二维码存件");
	}

}


void CQRWidget::on_btnBack_clicked()
{
	done(MSGBOX_BACK);
}
void CQRWidget::on_btnHome_clicked()
{
	done(MSGBOX_HOME);
}

void CQRWidget::on_slot_timeout()
{
	done(102400);
}