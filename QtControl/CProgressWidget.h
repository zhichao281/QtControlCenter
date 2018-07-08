#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDialog>
#include <QMovie> 
#include "ui_CProgressWidget.h"
#include "define.h"
#include "QPortControl.h"
#include "QMoveControl.h"
#include "ControlSql.h"
class CProgressWidget : public QDialog,public Ui::CProgressWidget
{
	Q_OBJECT

public:
	CProgressWidget(QWidget *parent = Q_NULLPTR);
	~CProgressWidget();

	virtual void setValue(QString strWeight, QString strHeight);

	virtual  bool setInputNum(int nInputNum, WIDGET_TYPE types);

public:
	QMovie * pMove;

	WIDGET_TYPE  m_type;

	int  m_nInputNum;
	

};
