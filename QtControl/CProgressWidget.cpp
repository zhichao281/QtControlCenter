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
	btn_back->hide();
	btn_home->hide();
	
	connect(gblPortControl, SIGNAL(sig_OpendoorFinish()), this, SLOT(on_slot_OpendoorFinish()));

	connect(gblPortControl, SIGNAL(sig_MoveFinish()), this, SLOT(on_slot_MoveFinish()));

	connect(gblPortControl, SIGNAL(sig_PushGoodsFinish()), this, SLOT(on_slot_PushGoodsFinish()));

	connect(gblPortControl, SIGNAL(sig_SuckTrayFinish()), this, SLOT(on_slot_SuckTrayFinish()));

	connect(gblPortControl, SIGNAL(sig_GetGoodsFinish()), this, SLOT(on_slot_GetGoodsFinish()));

	connect(gblPortControl, SIGNAL(sig_DropTrayFinish()), this, SLOT(on_slot_DropTrayFinish()));

	connect(gblPortControl, SIGNAL(sig_ClosedoorFinish()), this, SLOT(on_slot_ClosedoorFinish()));

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
		gblPortControl->MovePoint(app.savePoint.x(), app.savePoint.y());
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

void CProgressWidget::on_slot_OpendoorFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		gblPortControl->SuckTray();
	}
	else
	{
		done(0);
	}
}

void CProgressWidget::on_slot_ClosedoorFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		gblPortControl->SuckTray();
	}
	else
	{

	}

}

void CProgressWidget::on_slot_MoveFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		gblPortControl->PushGoods();
	}
	else
	{
		if (m_bSecond == false)
		{
			gblPortControl->PushGoods();
		}
		else
		{
			gblPortControl->PushGoods();
		}
	}

}

void CProgressWidget::on_slot_PushGoodsFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		gblPortControl->DropTray();
	}
	else
	{
		if (m_bSecond == false)
		{
			gblPortControl->SuckTray();
		}
		else
		{
			gblPortControl->DropTray();
		}
	}
}
void CProgressWidget::on_slot_SuckTrayFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		gblPortControl->GetGoods();
	}
	else
	{
		if (m_bSecond == false)
		{
			gblPortControl->GetGoods();
		}
	}
}

void CProgressWidget::on_slot_DropTrayFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		done(0);
	}
	else
	{
		gblPortControl->OpenDoor();
	}
}

void CProgressWidget::on_slot_GetGoodsFinish()
{
	if (m_type == WIDGET_TYPE::MSGBOX_SAVE)
	{
		AppInfo app;
		bool bres = gblControlSql->Get_App_By_QRnum(m_nInputNum, app);
		if (bres)
		{
			gblPortControl->MovePoint(app.savePoint.x(),app.savePoint.y());
		}

	}
	else
	{
		if (m_bSecond == false)
		{
			gblPortControl->MovePoint(0, 0);
			m_bSecond = true;
		}
	}

}
