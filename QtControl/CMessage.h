#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QDialog>
#include <QMovie> 
#include "ui_CMessage.h"
#include "define.h"
class CMessage : public QDialog,public Ui::CMessage
{
	Q_OBJECT
public:
Q_FLAGS(MSGBOX_TYPE)
	enum MSGBOX_TYPE
	{
		MSGBOX_WAITSAVE = 0x0001,
		MSGBOX_WAITGET = 0x0002,
		MSGBOX_SAVEEND= 0x0004,
		MSGBOX_GETEND= 0x0008,
		MSGBOX_CLOSE = 0x0010
	};
	Q_DECLARE_FLAGS(MSGBOX_TYPES, MSGBOX_TYPE)
public:
	CMessage(QWidget *parent = Q_NULLPTR);
	~CMessage();
public:
	void Init(MSGBOX_TYPE types);

	/*
	* Describe : 提示
	*/
	static int WaitSave(QWidget *parent = 0);

	/*
	* Describe : 提示
	*/
	static int WaitGet(QWidget *parent = 0);

	/*
	* Describe : 提示
	*/
	static int SaveEnd(QWidget *parent = 0);

	/*
	* Describe : 提示
	*/
	static int GetEnd(QWidget *parent = 0);

private slots:
	void on_btnBack_clicked();

	void on_btnHome_clicked();

	void on_btnOk_clicked();

	void on_btnReturn_clicked();

	void on_slot_timeout();
private:
	QMovie * pMove;

	int  nTime;
};
