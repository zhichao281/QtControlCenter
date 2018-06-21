
#include <QtWidgets/QApplication> 
#include <iostream>
#include "define.h"
#include <stdio.h>
#include "ConfigWidget.h"
using namespace std;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	gblRuntimeData->ReadConfig();
	ConfigWidget config;
	config.show();
	
	return a.exec();
}
