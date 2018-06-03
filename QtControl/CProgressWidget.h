#pragma once

#include <QDialog>
#include <QMovie> 
#include "ui_CProgressWidget.h"

class CProgressWidget : public QDialog,public Ui::CProgressWidget
{
	Q_OBJECT

public:
	CProgressWidget(QWidget *parent = Q_NULLPTR);
	~CProgressWidget();

private slots:

	void on_slot_timeout();

private:
	QMovie * pMove;
};
