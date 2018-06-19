#pragma once

#include <QObject>
#include "CSerialPort.h"
#include <string>

#include "include/HSingleton/HSingleton.h"
using namespace  std;

enum ActionControl
{
	Action_Null=0,
	Action_DropTray = 10,
	Action_SuckTray = 20,
	Action_OpenDoor = 30,
	Action_CloseDoor = 40,
	Action_GetGoods = 50,
	Action_PushGoods = 60,
	Action_Move = 70

};
class QPortControl : public QObject
{
	Q_OBJECT

public:
	QPortControl(QObject *parent=nullptr);
	~QPortControl();

public slots:
	void slot_ReadData(QString strRecevice);


signals:
	void sig_OpendoorFinish();

	void sig_ClosedoorFinish();

	void sig_SuckTrayFinish();

	void sig_DropTrayFinish();

	void sig_MoveFinish();

	void sig_PushGoodsFinish();

	void sig_GetGoodsFinish();
public:

	bool  OpenDoor();

	bool CloseDoor();

	//吸住托盘
	bool SuckTray();

	//放开托盘
	bool DropTray();

	//拉回机械臂
	void GetGoods();

	//推送机械臂
	void PushGoods();
	//运动到行列动作
	void  MovePoint(int nRow, int nColumn);


	void restart();
public:

	int m_nRow;
	int m_nColumn;
	QString m_strMoveToX;
	QString m_strMoveToY;
	ActionControl  m_Action;
};


#define gblPortControl HSingletonTemplatePtr<QPortControl>::get()
