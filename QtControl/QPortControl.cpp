#include "QPortControl.h"
#include <QMessageBox>
QPortControl::QPortControl(QObject *parent)
	: QObject(parent)
{
	connect(gbl485SerialPort, SIGNAL(sig_ReadData(QString)), this, SLOT(slot_ReadData(QString)));

	connect(gbl232SerialPort, SIGNAL(sig_ReadData(QString)), this, SLOT(slot_232ReadData(QString)));

	connect(gbl485HeightPort, SIGNAL(sig_ReadData(QString)), this, SLOT(slot_heightReadData(QString)));

}

QPortControl::~QPortControl()
{
}

void QPortControl::slot_ReadData(QString strRecevice)
{
	LOG_INFO("slot_ReadData =[%s]", strRecevice.toStdString().c_str());




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
		m_nError = 0;
		return;
	}
	//上位机读取电磁吸盘动作是否执行完成
	if (strRecevice.toUpper() == SuckTrayFail && m_Action == Action_SuckTray)
	{
		if (m_nError == ERRORNUM)
		{
			m_Action = Action_Null;
			emit sig_SuckTrayFinish();
			m_nError = 0;
			return;
		}
		gbl485SerialPort->AddTask(AskSuckTray);	
		m_nError = m_nError + 1;
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
		m_nError = 0;
		return;
	}
	//上位机读取电磁放开盘动作是否执行完成
	if (strRecevice.toUpper() == DropTrayFail && m_Action == Action_DropTray)
	{
		if (m_nError == ERRORNUM)
		{
			m_Action = Action_Null;
			emit sig_DropTrayFinish();
			m_nError = 0;
			return;

		}
		gbl485SerialPort->AddTask(AskDropTray);
		m_nError = m_nError + 1;
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
		return;
	}
	if (strRecevice.toUpper() == StartGetGoods && m_Action == Action_GetGoods)
	{
		//上位机读取电磁吸盘动作是否执行完成？
		gbl485SerialPort->AddTask(AskGetGoods);
		Sleep(10);
		GetHeight();
		return;
	}
	//上位机读取电磁吸盘动作是否执行完成
	if (strRecevice.toUpper() == GetGoodsFail && m_Action == Action_GetGoods)
	{
		gbl485SerialPort->AddTask(AskGetGoods);
		Sleep(10);
		GetHeight();
		return;
	}
	//完成拉取货物命令
	if (strRecevice.toUpper() == GetGoodsSucess && m_Action == Action_GetGoods)
	{
		m_Action = Action_Null;
		emit sig_GetGoodsFinish();
		return;
	}

	/**********推送到位*****************/
	//PLC接收到上位机推送货物命令
	if (strRecevice.toUpper() == WantPushGoods)
	{
		//收到并执行推送货物
		m_Action = Action_PushGoods;
		gbl485SerialPort->AddTask(StartPushGoods);
		return;
	}
	if (strRecevice.toUpper() == StartPushGoods && m_Action == Action_PushGoods)
	{
		//推送到位没有？？
		gbl485SerialPort->AddTask(AskPushGoods);
		return;
	}
	//推送到位没有？
	if (strRecevice.toUpper() == PushGoodsFail && m_Action == Action_PushGoods)
	{
		gbl485SerialPort->AddTask(AskPushGoods);
		return;
	}
	//已经推送到位
	if (strRecevice.toUpper() == PushGoodsSucess && m_Action == Action_PushGoods)
	{
		m_Action = Action_Null;
		emit sig_PushGoodsFinish();
		return;
	}

	/********运动到行列******************/
	//PLC收到行数信息
	if (strRecevice.toUpper() == m_strMoveToX)
	{
		//发送列数信息
		m_Action = Action_Move;
		gbl485SerialPort->AddTask(m_strMoveToY);
		return;
	}
	//PLC收到列数信息
	if (strRecevice.toUpper() == m_strMoveToY && m_Action == Action_Move)
	{
		//开始运动到相应的行、列
		gbl485SerialPort->AddTask(StartMove);
		return;
	}
	//PLC收到列数信息
	if (strRecevice.toUpper() == StartMove && m_Action == Action_Move)
	{
		//开始运动到相应的行、列
		gbl485SerialPort->AddTask(AskMove);
		return;
	}

	//上位机询问是否达到相应的行、列位置？
	if (strRecevice.toUpper() == MoveFail && m_Action == Action_Move)
	{
		gbl485SerialPort->AddTask(AskMove);
		return;
	}
	//已达到指定行、列位置
	if (strRecevice.toUpper() == MoveSucess && m_Action == Action_Move)
	{
		m_Action = Action_Null;
		emit sig_MoveFinish();
		return;
	}

	if (strRecevice.indexOf("3A 30 32 30 33 30 32") != -1)
	{
		emit sig_ReadSetting(m_Action, strRecevice);
		return;
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

void QPortControl::SetZero()
{
	gbl232SerialPort->AddTask(SETWEIGHTZERO);
	return;
}

void QPortControl::slot_232ReadData(QString strRecevice)
{
	strRecevice.replace(" 02 40 6", "02 40 6");
	LOG_INFO("strRecevice=[%s]", strRecevice.toStdString().c_str());

	if (strRecevice.toUpper() == ZEROWEIGHT)
	{
		gblRuntimeData->strWeight = "0";
		return;
	}
	if (strRecevice.toUpper().indexOf("02 40 62")!= -1)
	{
		QString strweight;
		int strten;
		if (strRecevice.section(" ", 5, 5).toInt() < 30)
		{
			strten = 0;
		}
		else
		{
			strten = strRecevice.section(" ", 5, 5).toInt() - 30;
		}
		if (strten > 2)
		{	
			emit sig_overWeight();
			gblRuntimeData->strWeight = "超重";
			return;		
		}
		int strone = strRecevice.section(" ", 6, 6).toInt() - 30;
		QString strpoint = ".";
		int strpointone = strRecevice.section(" ", 8, 8).toInt() - 30;
		int strpointten = strRecevice.section(" ", 9, 9).toInt() - 30;
		double weight = strten * 10 + strone + strpointone * 0.1 + strpointten * 0.01;
		/*	if (weight - gblRuntimeData->strWeight.toDouble() > 0)
			{

			}*/
		if (weight-1.86>0)
		{
			gblRuntimeData->strWeight = QString::number((weight-1.86), 10, 2);
		}
		else
		{
			gblRuntimeData->strWeight = QString::number(weight, 10, 2);
		}
		
		LOG_INFO("weight =[%f], strWeight=[%s]", weight, gblRuntimeData->strWeight.toStdString().c_str());
	}
}

void QPortControl::slot_heightReadData(QString strRecevice)
{
	LOG_INFO("heightReadData=[%s]", strRecevice.toStdString().c_str());

	if (strRecevice.toUpper().indexOf("01 03 04") != -1)
	{
		int height2 = strRecevice.section(" ", 6, 6).toInt(0, 16)*20+40;
		if (height2 == 40)
		{
			height2 = 30;
		}
		if (height2 - gblRuntimeData->strHeight.toInt()>0)
		{
			gblRuntimeData->strHeight = QString::number(height2);
		}
		
	}

}

void QPortControl::setReadState(bool bRead)
{
	gbl232SerialPort->setReadState(bRead);
	//gblRuntimeData->strWeight="0";
}

void QPortControl::GetHeight()
{
	gbl485HeightPort->AddTask(GEIHEIGHT);


}

QString ValueToHex(QString strSend,int nValue)
{
	QString strValue = QString("%1").arg(nValue, 4, 16, QLatin1Char('0'));
	strSend = strSend + " " + strValue.mid(0,2).toUpper() + " " + strValue.mid(2, 2).toUpper();
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
	QString	strLRC = QString("%1").arg(num, 2, 16, QLatin1Char('0'));
	strSend = strSend + " " + strLRC.right(2).toUpper();
	
	QString strNew = "3A ";
	for (int i = 0; i < strSend.length(); i++)
	{
		strNew += hextoAss(strSend.at(i));
	}
	strNew = strNew + MOVEEND;
	
	return strNew;
}


void QPortControl::move_setting(int nValue)
{
	QString strSend = "02 06 17 D0";
	strSend = ValueToHex(strSend, nValue);
	gbl485SerialPort->AddTask(strSend);

}

void QPortControl::move_read()
{
	gbl485SerialPort->AddTask("3A 30 32 30 33 31 37 44 30 30 30 30 31 31 33 0D 0A");
	m_Action = Action_Read_Move;
}

void QPortControl::rotate_setting(int nValue)
{
	QString strSend = "02 06 17 DA";
	strSend = ValueToHex(strSend, nValue);


	gbl485SerialPort->AddTask(strSend);

}

void QPortControl::rotate_read()
{
	gbl485SerialPort->AddTask("3A 30 32 30 33 31 37 44 41 30 30 30 31 30 39 0D 0A");
	m_Action = Action_Read_Rotate;
}

void QPortControl::tray_setting(int nValue)
{

	QString strSend = "02 06 17 E4";
	strSend = ValueToHex(strSend, nValue);
	gbl485SerialPort->AddTask(strSend);

}

void QPortControl::tray_read()
{
	gbl485SerialPort->AddTask("3A 30 32 30 33 31 37 45 34 30 30 30 31 46 46 0D 0A");
	m_Action = Action_Read_Tray;
}

void QPortControl::door_setting(int nValue)
{
	QString strSend = "02 06 17 EE";
	strSend = ValueToHex(strSend, nValue);
	gbl485SerialPort->AddTask(strSend);
}

void QPortControl::door_read()
{
	gbl485SerialPort->AddTask("3A 30 32 30 33 31 37 45 45 30 30 30 31 46 35 0D 0A");
	m_Action = Action_Read_Door;
}

void QPortControl::zero_setting(int nValue)
{

	QString strSend = "02 06 1F A0";
	strSend = ValueToHex(strSend, nValue);
	gbl485SerialPort->AddTask(strSend);

}

void QPortControl::zero_read()
{
	gbl485SerialPort->AddTask("3A 30 32 30 33 31 46 41 30 30 30 30 31 33 42 0D 0A");
	m_Action = Action_Read_Zero;
}

