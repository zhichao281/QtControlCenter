#include "QPortControl.h"
#include <QMessageBox>
QPortControl::QPortControl(QObject *parent)
	: QObject(parent)
{
	


	connect(gbl485SerialPort, SIGNAL(sig_ReadData(QString)), this, SLOT(slot_ReadData(QString)));

}

QPortControl::~QPortControl()
{
}

void QPortControl::slot_ReadData(QString strRecevice)
{
	//上位机收到开门请求
	if (strRecevice.toUpper() == WantOpenDoor)
	{
		//上位机发送开始执行开门动作
		m_Action = Action_OpenDoor;
		gbl485SerialPort->AddTask(StartOpenDoor);
		return;
	}
	//上位机发送开始执行开门动作
	if (strRecevice.toUpper() == StartOpenDoor && m_Action == Action_OpenDoor)
	{		
		gbl485SerialPort->AddTask(AskOpenDoor);
		return;
	}
	//上位机发送开始执行开门动作
	if (strRecevice.toUpper() == OpenDoorFail && m_Action == Action_OpenDoor)
	{
		gbl485SerialPort->AddTask(AskOpenDoor);
		return;
	}
	//上位机收到开门成功的信号
	if (strRecevice.toUpper() == OpenDoorSucess&& m_Action == Action_OpenDoor)
	{
		m_Action = Action_Null;
		emit sig_OpendoorFinish();	
		return;
	}

	/**********关门*****************/
	//上位机收到关门请求
	if (strRecevice.toUpper() == WantDoorClose)
	{
		//上位机发送开始执行关门动作
		m_Action = Action_CloseDoor;
		gbl485SerialPort->AddTask(StartCloseDoor);
		return;
	}
	//上位机询问是否完成关门门动作？
	if (strRecevice.toUpper() == StartCloseDoor && m_Action == Action_CloseDoor)
	{
		gbl485SerialPort->AddTask(AskCloseDoor);
		return;
	}
	//上位机发送开始执行关门动作
	if (strRecevice.toUpper() == CloseDoorFail && m_Action == Action_CloseDoor)
	{
		gbl485SerialPort->AddTask(AskCloseDoor);
		return;
	}
	//上位机收到关门成功的信号
	if (strRecevice.toUpper() == CloseDoorSucess && m_Action == Action_CloseDoor)
	{
		m_Action = Action_Null;
		emit sig_ClosedoorFinish();	
		return;
	}

	/**********吸住托盘*****************/
	//上位机收到吸住托盘请求
	if (strRecevice.toUpper() == WantSuckTray)
	{
		m_Action = Action_SuckTray;
		//上位机发送执行电磁体吸住托盘开始命令
		gbl485SerialPort->AddTask(StartSuckTray);
		return;
	}	
	if (strRecevice.toUpper() == StartSuckTray && m_Action == Action_SuckTray)
	{
		//上位机读取电磁吸盘动作是否执行完成？
		gbl485SerialPort->AddTask(AskSuckTray);
		return;
	}
	//上位机读取电磁吸盘动作是否执行完成
	if (strRecevice.toUpper() == SuckTrayFail && m_Action == Action_SuckTray)
	{
		m_Action = Action_Null;
		gbl485SerialPort->AddTask(AskSuckTray);	
		return;
	}
	//完成吸住托盘
	if (strRecevice.toUpper() == SuckTraySucess && m_Action == Action_SuckTray)
	{
		m_Action = Action_Null;
		emit sig_SuckTrayFinish();
		return;
	}

	/*********放开托盘*****************/
	//上位机收到放开托盘请求
	if (strRecevice.toUpper() == WantDropTray)
	{
		//上位机发送执行电磁体放开托盘开始命令
		m_Action = Action_DropTray;
		gbl485SerialPort->AddTask(StartDropTray);
		return;
	}
	if (strRecevice.toUpper() == StartDropTray && m_Action == Action_DropTray)
	{
		//上位机读取电磁放盘动作是否执行完成？
		gbl485SerialPort->AddTask(AskDropTray );
		return;
	}
	//上位机读取电磁放开盘动作是否执行完成
	if (strRecevice.toUpper() == DropTrayFail && m_Action == Action_DropTray)
	{
		gbl485SerialPort->AddTask(AskDropTray);
		return;
	}
	//完成放下托盘
	if (strRecevice.toUpper() == DropTraySucess && m_Action == Action_DropTray)
	{
		m_Action = Action_Null;
		emit sig_DropTrayFinish();
		return;
	}

	/**********拉取货物*****************/
	//PLC接收到上位机开门命令
	if (strRecevice.toUpper() == WantGetGoods)
	{
		//上位机发送开始执行拉取货物命令
		m_Action = Action_GetGoods;
		gbl485SerialPort->AddTask(StartGetGoods);
	}
	if (strRecevice.toUpper() == StartGetGoods && m_Action == Action_GetGoods)
	{
		//上位机读取电磁吸盘动作是否执行完成？
		gbl485SerialPort->AddTask(AskGetGoods);
	}
	//上位机读取电磁吸盘动作是否执行完成
	if (strRecevice.toUpper() == GetGoodsFail && m_Action == Action_GetGoods)
	{
		gbl485SerialPort->AddTask(AskGetGoods);
	}
	//完成拉取货物命令
	if (strRecevice.toUpper() == GetGoodsSucess && m_Action == Action_GetGoods)
	{
		m_Action = Action_Null;
		emit sig_GetGoodsFinish();
	}


	/**********推送到位*****************/
	//PLC接收到上位机推送货物命令
	if (strRecevice.toUpper() == WantPushGoods)
	{
		//收到并执行推送货物
		m_Action = Action_PushGoods;
		gbl485SerialPort->AddTask(StartPushGoods);
	}
	if (strRecevice.toUpper() == StartPushGoods && m_Action == Action_PushGoods)
	{
		//推送到位没有？？
		gbl485SerialPort->AddTask(AskPushGoods);
	}
	//推送到位没有？
	if (strRecevice.toUpper() == PushGoodsFail && m_Action == Action_PushGoods)
	{
		gbl485SerialPort->AddTask(AskPushGoods);
	}
	//已经推送到位
	if (strRecevice.toUpper() == PushGoodsSucess && m_Action == Action_PushGoods)
	{
		m_Action = Action_Null;
		emit sig_PushGoodsFinish();
	}

	/********运动到行列******************/
	//PLC收到行数信息
	if (strRecevice.toUpper() == m_strMoveToX)
	{
		//发送列数信息
		m_Action = Action_Move;
		gbl485SerialPort->AddTask(m_strMoveToY);
	}
	//PLC收到列数信息
	if (strRecevice.toUpper() == m_strMoveToY && m_Action == Action_Move)
	{
		//开始运动到相应的行、列
		gbl485SerialPort->AddTask(StartMove);
	}
	//PLC收到列数信息
	if (strRecevice.toUpper() == StartMove && m_Action == Action_Move)
	{
		//开始运动到相应的行、列
		gbl485SerialPort->AddTask(AskMove);
	}

	//上位机询问是否达到相应的行、列位置？
	if (strRecevice.toUpper() == MoveFail && m_Action == Action_Move)
	{
		gbl485SerialPort->AddTask(AskMove);
	}
	//已达到指定行、列位置
	if (strRecevice.toUpper() == MoveSucess && m_Action == Action_Move)
	{
		m_Action = Action_Null;
		emit sig_MoveFinish();
	}

}


bool QPortControl::OpenDoor()
{
	restart();
	gbl485SerialPort->AddTask(WantOpenDoor);
	return true;

}

bool QPortControl::CloseDoor() 
{
	restart();
	gbl485SerialPort->AddTask(WantDoorClose);
	return true;
}
//吸住托盘
bool QPortControl::SuckTray()
{
	restart();
	gbl485SerialPort->AddTask(WantSuckTray);
	return true;
}

//吸住托盘
bool QPortControl::DropTray()
{
	restart();
	gbl485SerialPort->AddTask(WantDropTray);
	return true;
}

//拉取货物
void QPortControl::GetGoods()
{//上位机发送拉取货物命令
	restart();
	gbl485SerialPort->AddTask(WantGetGoods);
}


int Hextoi(QString s, char len)
{
	int i;
	int n = 0;

	if (s.length() < len) return 0; //解决崩毁，指针溢出问题  

	for (i = 0; i < len; ++i)
	{
		if (s.at(i) > '9')
		{
			n = 16 * n + (10 + s.at(i).toLatin1() - 'A');
		}
		else
		{
			n = 16 * n + (s.at(i).toLatin1() - '0');
		}
	}
	return n;
}

QString hextoAss(QString i)
{
	if (i == ' ')
		return "";
	if (i < '9' || i == '9')
	{
		i = "3" + i;
	}
	else
	{
		if (i=='A')
		{
			i = "41";
		}
		if (i == 'B')
		{
			i = "42";
		}
		if (i == 'C')
		{
			i = "43";
		}
		if (i == 'D')
		{
			i = "44";
		}
		if (i == 'E')
		{
			i = "45";
		}
		if (i == 'F')
		{
			i = "46";
		}
	}
	i =   i+ ' ';
	return i;
}

QString PointToHex(int nRow,QString strSend)
{
	QString strRow = QString("%1").arg(nRow, 2, 16, QLatin1Char('0'));

	strSend = strSend +" "+ strRow.toUpper();
	QStringList lst;
	lst = strSend.split(' ');
	int num = 0;
	bool ok;
	unsigned char sum;
	for (int i = 0; i < lst.size(); i++)
	{
		QString str1 = lst[i];
		num += Hextoi(str1, 2);
	}
	num = ~num;
	num += 1;
	strRow = QString("%1").arg(num, 2, 16, QLatin1Char('0'));

	strSend = strSend+ " "+strRow.right(2).toUpper() ;
	QString strNew="3A ";
	for (int i = 0; i < strSend.length(); i++)
	{
		strNew += hextoAss(strSend.at(i));
	}
	strNew = strNew + MOVEEND;
	return strNew;
}

void  QPortControl::MovePoint(int nRow, int nColumn)
{
	m_nRow = nRow;
	m_nColumn = nColumn;

	if (nRow == 0 && nColumn == 0)
	{
		m_strMoveToX = MOVEZEROROW;
		m_strMoveToY = MOVEZEROCOLUMN;
	}
	else
	{
		m_strMoveToX = PointToHex(nRow, CountX);
		m_strMoveToY = PointToHex(nColumn, CountY);
	}
	
	restart();
	gbl485SerialPort->AddTask(m_strMoveToX);
}

void QPortControl::restart()
{
	gbl485SerialPort->close();
	gbl485SerialPort->InitSerial();
}

void QPortControl::PushGoods()
{
	restart();
	gbl485SerialPort->AddTask(WantPushGoods);
	return;
}