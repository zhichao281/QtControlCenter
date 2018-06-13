#include "CQRWidget.h"
#include <QTimer>
#include "Qtxqm.h"
CQRWidget::CQRWidget(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);

	//setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::WindowMinimizeButtonHint);
	setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	pMove = new QMovie(":/Image/Resources/Image/saoma.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();
	connect(btn_back, SIGNAL(clicked()), this, SLOT(on_btnBack_clicked()));
	connect(btn_home, SIGNAL(clicked()), this, SLOT(on_btnHome_clicked()));
	QTimer::singleShot(1000 * 10, this, SLOT(on_slot_timeout()));

	connect(gblTxqm, SIGNAL(sig_SendResult(QString)), this, SLOT(on_slot_SendResult(QString)));
}

CQRWidget::~CQRWidget()
{
}

void CQRWidget::Init(WIDGET_TYPE types)
{

	if (types & MSGBOX_GET)
	{
			label_title->setStyleSheet("min-width:504;"
									   "max-width:504;"
			                           "min-height:71px;"
			                           "max-height:71px;"
			                           "border-image: url(:/Image/Resources/Image/ÇëÉ¨Ãè¶þÎ¬ÂëÈ¡¼þ.png);");
	}
	if (types & MSGBOX_SAVE)
	{	
		label_title->setStyleSheet("min-width:504;"
								   " max-width:504;"
								   "min-height:71px;"
			                       "max-height:71px;"
			                       "border-image: url(:/Image/Resources/Image/ÇëÉ¨Ãè¶þÎ¬Âë´æ¼þ.png);");
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
	//done(102400);
}

void CQRWidget::on_slot_SendResult(QString strResult)
{
	int nResult = strResult.toInt();
	done(nResult);
}

