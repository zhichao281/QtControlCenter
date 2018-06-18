#pragma once
#include <memory>
#include <string.h>
#include "../QtControl/include/develop_interface.h"
#include "../QtControl/log/log_deffine.h"
#include "Base/myhelper.h"
#include "Base/RunTime.h"
#include "qextserialport_win/qextserialport.h"
#include "QPortControl.h"


//开门
#define  WantDoorOpen      "3A 02 06 12 03 00 01 E2 0D 0A"
#define  StartOpenDoor     "3A 02 06 12 04 00 01 E1 0D 0A"
#define  AskOpenDoor       "3A 02 03 12 04 00 01 E4 0D 0A"
#define  OpenDoorSucess    "3A 02 03 12 04 00 00 E5 0D 0A"

//关门
#define  WantDoorClose     "3A 02 06 12 03 00 00 E3 OD OA"
#define  StartCloseDoor    "3A 02 06 12 04 00 01 E1 0D 0A"
#define  AskCloseDoor      "3A 02 03 12 04 00 01 E4 0D 0A"
#define  CloseDoorSucess   "3A 02 03 12 04 00 00 E5 0D 0A"

//吸住托盘
#define WantSuckTray       "3A 02 06 12 07 00 01 DE 0D 0A"
#define StartSuckTray      "3A 02 06 12 08 00 01 DD 0D 0A"
#define AskSuckTray        "3A 02 03 12 08 00 01 E0 0D 0A"
#define SuckTraySucess     "3A 02 03 12 08 00 00 E1 0D 0A"

//放开托盘
#define WantDropTray      "3A 02 06 12 07 00 00 DF 0D 0A"
#define StartDropTray     "3A 02 06 12 08 00 01 DD 0D 0A"
#define AskDropTray       "3A 02 03 12 08 00 01 E0 0D 0A"
#define DropTraySucess    "3A 02 03 12 08 00 00 E1 0D 0A"

//拉取货物
#define WantGetGoods      "3A 02 06 12 05 00 01 E0 0D 0A"
#define StartGetGoods     "3A 02 06 12 06 00 01 DF 0D 0A"
#define AskGetGoods       "3A 02 03 12 06 00 01 E2 0D 0A"
#define GetGoodsSucess    "3A 02 03 12 06 00 00 E3 0D 0A"


//运动到行列动作
#define WantMoveToX       "3A 02 06 12 00 00"
#define WantMoveToY       "3A 02 06 12 01 00"

#define StartMove   "3A 02 06 12 02 00 01 E3 0D 0A"
#define AskMove     "3A 02 03 12 02 00 01 E6 0D 0A"
#define MoveSucess  "3A 02 03 12 02 00 00 E7 0D 0A"


//推送到位
#define WantPushGoods    "3A 02 06 12 05 00 00 E1 0D 0A"
#define StartPushGoods   "3A 02 06 12 06 00 01 DF 0D 0A"
#define AsktPushGoods    "3A 02 03 12 06 00 01 E2 0D OA"
#define PushGoodsSucess  "3A 02 03 12 06 00 00 E3 0D 0A"



#define   MAXCOLUMN  8
#define   MAXROW     20

#define   ADDROW       5
#define   MAXNULLTRAY  5

class AppInfo
{
public:
	AppInfo()
	{
		savePoint.setX(0);
		savePoint.setY(0);
		saveQRNum = 0;
		saveHeight = 0;
		saveWeight = 0;
		phoneNum = 0;
		userName = "";
	};
public:
	QPoint savePoint;  //保存的位置
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
