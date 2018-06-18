#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDialog>
#include <QMovie> 
#include "ui_CProgressWidget.h"
#include "define.h"
#include "QPortControl.h"
class CProgressWidget : public QDialog,public Ui::CProgressWidget
{
	Q_OBJECT

public:
	CProgressWidget(QWidget *parent = Q_NULLPTR);
	~CProgressWidget();


	void setValue(QString strWeight, QString strHeight);

	bool setInputNum(int nInputNum, WIDGET_TYPE types);

public slots :

	void on_slot_OpendoorFinish();

	void on_slot_ClosedoorFinish();

	void on_slot_MoveFinish();

	void on_slot_PushGoodsFinish();

	void on_slot_SuckTrayFinish();

	void on_slot_DropTrayFinish();

	void on_slot_GetGoodsFinish();

private:
	QMovie * pMove;

	WIDGET_TYPE  m_type;

	int  m_nInputNum;

	bool  m_bSecond;
};
