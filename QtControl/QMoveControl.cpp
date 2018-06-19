#include "QMoveControl.h"
#include <QMessageBox>
QMoveControl::QMoveControl(QObject *parent)
	: QObject(parent)
{
	m_bSecond = false;

	connect(gblPortControl, SIGNAL(sig_MoveFinish()), this, SLOT(on_slot_MoveFinish()));

	connect(gblPortControl, SIGNAL(sig_PushGoodsFinish()), this, SLOT(on_slot_PushGoodsFinish()));

	connect(gblPortControl, SIGNAL(sig_GetGoodsFinish()), this, SLOT(on_slot_GetGoodsFinish()));

	connect(gblPortControl, SIGNAL(sig_SuckTrayFinish()), this, SLOT(on_slot_SuckTrayFinish()));

	connect(gblPortControl, SIGNAL(sig_DropTrayFinish()), this, SLOT(on_slot_DropTrayFinish()));
	
}

QMoveControl::~QMoveControl()
{
}

void QMoveControl::SetMove(QPoint startPoint, QPoint endPoint)
{
	m_StartPoint = startPoint;
	m_EndPoint = endPoint;
}
void QMoveControl::StartWork()
{	
	gblPortControl->restart();

    gblPortControl->MovePoint(m_StartPoint.rx(), m_StartPoint.ry());
	m_bSecond = false;
	m_bFinish = false;
}


void QMoveControl::on_slot_MoveFinish()
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

void QMoveControl::on_slot_PushGoodsFinish()
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

void QMoveControl::on_slot_GetGoodsFinish()
{
	if (m_bFinish)
	{
		//完成；
		emit sig_finish();
		return;
	}	

	if (m_bSecond == false)
	{
		gblPortControl->MovePoint(m_StartPoint.x(), m_StartPoint.y());
	}
	else
	{
		gblPortControl->MovePoint(m_EndPoint.x(), m_EndPoint.y());
	}


}

void QMoveControl::on_slot_SuckTrayFinish()
{
	if (m_bSecond == false)
	{
		gblPortControl->GetGoods();
		m_bSecond = true;
	}
}

void QMoveControl::on_slot_DropTrayFinish()
{
	if (m_bSecond == false)
	{
		gblPortControl->GetGoods();
	}
	else
	{
		gblPortControl->GetGoods();
		m_bFinish = true;
		//完成；
	}



}