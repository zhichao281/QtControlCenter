#include "QtControl.h"
#include <QtWidgets/QApplication>
#include <QSerialPort>  
#include <QSerialPortInfo>  
#include <iostream>
#include "define.h"
#include <stdio.h>
#include "QMoveControl.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	//gblMoveControl->SetMove(QPoint(0, 0), QPoint(5, 5));
	//gblMoveControl->StartWork();
	//while (1)
	//{
	//	Sleep(1000);
	//}

	gblRuntimeData->ReadConfig();
	QtControl w;
	w.showMaximized();
	return a.exec();
}
