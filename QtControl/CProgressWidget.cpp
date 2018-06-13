#include "CProgressWidget.h"
#include "ControlSql.h"
#include <QTimer>
CProgressWidget::CProgressWidget(QWidget *parent)
	: QDialog(parent)
{
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint| Qt::WindowMinimizeButtonHint);
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


bool CProgressWidget::setInputNum(int nInputNum, WIDGET_TYPE types)
{
	AppInfo app;
	bool bres = gblControlSql->Get_App_By_QRnum(nInputNum, app);
	if (types == WIDGET_TYPE::MSGBOX_SAVE)
	{
		if (bres ==true )
		{
			QMessageBox::about(nullptr, "警告", "此二维码已使用！");
			return false;
		}
		app.saveQRNum = nInputNum;


	}
	else
	{
		if (bres == false)
		{
			QMessageBox::about(nullptr, "警告", "此二维码不存在！");
			return false;
		}

		bool bres = gblControlSql->Get_App_By_QRnum(nInputNum, app);
		label_weight->setText(QString::number(app.saveWeight));
		label_height->setText(QString::number(app.saveHeight));

	}

	return true;

}



void CProgressWidget::setValue(QString strWeight, QString strHeight)
{
	label_weight->setText(strWeight);
	label_height->setText(strHeight);
}



void CProgressWidget::on_slot_timeout()
{
	done(0);
}