#include "QtControl.h"
#include <QtWidgets/QApplication>
#include <QSerialPort>  
#include <QSerialPortInfo>  
#include <iostream>
#include "define.h"
#include <stdio.h>
using namespace std;


//ÇóÁ½¸ö×Ö·û´®Òì»ò
QString getXORresult(QString str1, QString str2)
{
	QString result;
	//×Ö·û´®×ªQByteArray
	QByteArray bs1 = str1.toLatin1();
	QByteArray bs2 = str2.toLatin1();
	int size = bs1.size();
	int size2 = bs2.size();
	if (size != size2)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			bs1[i] = bs1[i] ^ bs2[i];
		}
	}
	//QByteArray×ª×Ö·û´®
	return result.prepend(bs1);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gblRuntimeData->ReadConfig();







	QtControl w;
	w.showMaximized();
	return a.exec();
}
