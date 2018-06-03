#include "QtControl.h"
#include <QtWidgets/QApplication>
#include <QSerialPort>  
#include <QSerialPortInfo>  
#include <iostream>
#include "define.h"
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gblRuntimeData->ReadConfig();
	QtControl w;
	w.showMaximized();
	return a.exec();
}
