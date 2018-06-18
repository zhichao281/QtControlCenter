
#include <QtWidgets/QApplication>
#include <QSerialPort>  
#include <QSerialPortInfo>  
#include <iostream>
#include "define.h"
#include <stdio.h>
#include "QMoveControl.h"

#include "ConfigWidget.h"
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	
	gblMoveControl->SetMove(QPoint(0, 0), QPoint(5, 5));
	gblMoveControl->StartWork();

	gblRuntimeData->ReadConfig();
	ConfigWidget config;
	config.show();

	
	return a.exec();
}
