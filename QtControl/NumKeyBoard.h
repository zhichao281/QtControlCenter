#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDialog>
#include <QSignalMapper>
#include <QMouseEvent>
#include "ui_NumKeyBoard.h"
#include "define.h"

class NumKeyBoard : public QDialog,public Ui::NumKeyBoard
{
	Q_OBJECT
public:
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
	void Init(WIDGET_TYPE types);


private slots:
	void setDispText(const QString& text);
	void onEnter();
	void onBackspace();

	/*******大小写*/
	void onInvMode();

	void  on_slot_textChanged(const QString &text);

	void on_btnBack_clicked();

	void on_btnHome_clicked();
public:
	QString text;

private:
	int inputMode;
	bool waitingForOperand;
	QSignalMapper *signalMapper;
	QPoint dragPosition;
	bool caps_Lock;
	WIDGET_TYPE  m_type;




};
