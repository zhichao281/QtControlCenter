#pragma once
#include <memory>
#include <string.h>
#include "../QtControl/include/develop_interface.h"
#include "../QtControl/log/log_deffine.h"
#include "Base/myhelper.h"
#include "Base/RunTime.h"
#include "qextserialport_win/qextserialport.h"

enum WIDGET_TYPE
{
	MSGBOX_GET = 0x0001,
	MSGBOX_SAVE = 0x0002,
	MSGBOX_CLOSE = 0x0004,
	MSGBOX_BACK = 0x0008,
	MSGBOX_HOME = 0x00010,
	MSGBOX_OK = 0x00020,
	MSGBOX_RETURN = 0x00040
};


class AppInfo
{
public:
	QPoint savePoint;  //保存的位置
	//int    saveRow;
	//int    saveColumn;
	int    saveQRNum;	//保存的二维码数据	
	int    saveHeight;//保存的高度
	int    saveWeight;//保存的重量
	long   phoneNum;
	std::string userName;

	//int    isdetele;
};



//静态库
#ifdef _DEBUG

#pragma comment(lib, "../QtControl/lib/vbar.lib")


#else

#pragma comment(lib, "../QtControl/lib/vbar.lib")

#endif
