#pragma once

#include <QWidget>
#include <QWidget>
#include <QSignalMapper>
#include <QMouseEvent>
#include "ui_NumKeyBoard.h"

class NumKeyBoard : public QWidget,public Ui::NumKeyBoard
{
	Q_OBJECT

public:
	NumKeyBoard(QWidget *parent = Q_NULLPTR);
	~NumKeyBoard();
private:

	void mouseMoveEvent(QMouseEvent *);
	void mousePressEvent(QMouseEvent *);
	enum
	{
		iMode_Normal = 0,
		iMode_Passwd = 1
	}; //密码模式与正常模式
private:
	void setMapper();
	void connectMapper();
	void button_init();

public:
	QString text;
signals:
	void setvalue(QString text);
private slots:
	void setDispText(const QString& text);
	void onEnter();
	void onBackspace();

	/*******大小写*/
	void onInvMode();

	void  on_slot_textChanged(const QString &text);
private:
	int inputMode;
	bool waitingForOperand;
	QSignalMapper *signalMapper;
	QPoint dragPosition;
	bool caps_Lock;
};
