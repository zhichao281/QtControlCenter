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

private slots:

	void on_slot_timeout();

	void on_slot_ClosedoorFinish();

	void slot_SuckTrauFinish();
private:
	QMovie * pMove;
};
