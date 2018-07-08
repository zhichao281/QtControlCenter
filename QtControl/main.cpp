
#include <QtWidgets/QApplication> 
#include <iostream>
#include "define.h"
#include <stdio.h>
#include "ConfigWidget.h"
#include "QPortControl.h"
using namespace std;

int Hextoi1(QString s, char len)
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
QString ValueToHex1(QString strSend, int nValue)
{
	QString strValue = QString("%1").arg(nValue, 4, 16, QLatin1Char('0'));
	strSend = strSend + " " + strValue.mid(0, 2).toUpper() + " " + strValue.mid(2, 2).toUpper();
	QStringList lst;
	lst = strSend.split(' ');
	int num = 0;
	bool ok;
	unsigned char sum;
	for (int i = 0; i < lst.size(); i++)
	{
		QString str1 = lst[i];
		num += Hextoi1(str1, 2);
	}
	num = ~num;
	num += 1;
	QString	strLRC = QString("%1").arg(num, 2, 16, QLatin1Char('0'));
	strSend = strSend + " " + strLRC.right(2).toUpper() + " 0D 0A";
	return strSend;
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	gblRuntimeData->ReadConfig();
	ConfigWidget config;
	config.show();
	
	return a.exec();
}
