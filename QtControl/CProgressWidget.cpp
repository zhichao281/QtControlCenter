#include "CProgressWidget.h"
#include "ControlSql.h"
#include <QTimer>
#include "QPortControl.h"
#include "QMoveControl.h"
CProgressWidget::CProgressWidget(QWidget *parent)
	: QDialog(parent)
{
	m_bFinish = false;
	this->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint| Qt::WindowMinimizeButtonHint);
	this->setWindowIcon(QIcon(":/Image/Resources/Image/zhihuiwu.ico"));
	pMove = new QMovie(":/Image/Resources/Image/loading.gif");
	pMove->setScaledSize(label_gif->size());
	label_gif->setMovie(pMove);
	pMove->start();
	btn_back->hide();
	btn_home->hide();
	
	connect(gblPortControl, SIGNAL(sig_OpendoorFinish()), this, SLOT(on_slot_OpendoorFinish()));

	connect(gblPortControl, SIGNAL(sig_ClosedoorFinish()), this, SLOT(on_slot_ClosedoorFinish()));

	connect(gblMoveControl, SIGNAL(sig_finish()), this, SLOT(on_slot_finish()));
}

CProgressWidget::~CProgressWidget()
{
}


bool CProgressWidget::setInputNum(int nInputNum, WIDGET_TYPE types)
{

	m_nInputNum = nInputNum;
	m_type = types;
	if (types == WIDGET_TYPE::MSGBOX_SAVE)
	{
		gblPortControl->CloseDoor();
	}
	else
	{
		AppInfo app;
		bool bres = gblControlSql->Get_App_By_QRnum(m_nInputNum, app);
		if (bres == false)
		{
			QMessageBox::about(nullptr, "警告", "此二维码不存在！");
			return false;
		}
		m_bSecond = false;
		gblMoveControl->SetMove(QPoint(app.savePoint.rx(), app.savePoint.ry()), QPoint(0, 0));
		gblMoveControl->StartWork();
		m_bFinish = false;
	
	}
	return true;

}



void CProgressWidget::setValue(QString strWeight, QString strHeight)
{
	label_weight->setText(strWeight);
	label_height->setText(strHeight);
}

void CProgressWidget::on_slot_OpendoorFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		
	}
	else
	{
		m_bFinish = true;
		done(0);
	}
}
void CProgressWidget::on_slot_finish()
{

	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		done(0);
	}
	else
	{		
		if (m_bFinish == false)
		{
			gblPortControl->OpenDoor();
		}
	
	}
}
void CProgressWidget::on_slot_ClosedoorFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		AppInfo app;
		bool bres = gblControlSql->Get_App_By_QRnum(m_nInputNum, app);
		if (bres)
		{
			gblMoveControl->SetMove(QPoint(0, 0), QPoint(app.savePoint.x(), app.savePoint.y()));
			gblMoveControl->StartWork();
		}
	}
	else
	{

	}

}

