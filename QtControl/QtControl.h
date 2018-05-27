#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtControl.h"
#include "keyboard.h"
#include <memory>
#include "NumKeyBoard.h"
#include "frmcomtool.h"
class QtControl : public QWidget,public Ui::QtControlClass
{
	Q_OBJECT

public:
	QtControl(QWidget *parent = Q_NULLPTR);
	void QtControl::initPort();
private:
	void InitkeyBoardDlg();
	void disPlayKeyBoard();
private slots:
	void displayInputContent(QString text);

	void on_slot_Get();

	void on_slot_setting();

public:

	KeyBoard* keyBoardDlg;
	QWidget* parentWidget;
	std::shared_ptr<NumKeyBoard>   m_pNumKeyWidget;
	std::shared_ptr<frmComTool>   m_pfrmWidget;

	
};
