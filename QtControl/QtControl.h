#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtControl.h"
#include "keyboard.h"
#include <memory>

#include "frmcomtool.h"
#include "define.h"

class QGetWidget;

class QtControl : public QWidget,public Ui::QtControlClass
{
	Q_OBJECT

public:
	QtControl(QWidget *parent = Q_NULLPTR);


private slots:
	void displayInputContent(QString text);

	void on_slot_Get();

	void on_slot_Save();

	void on_slot_setting();

public:

	KeyBoard* keyBoardDlg;
	QWidget* parentWidget;

	std::shared_ptr<frmComTool>    m_pfrmWidget;

	std::shared_ptr<QGetWidget>    m_pGetWidget;
	
};
