#pragma once
#include <memory>
#include <string.h>
#include "../QtControl/include/develop_interface.h"
#include "../QtControl/log/log_deffine.h"
#include "Base/myhelper.h"
#include "Base/RunTime.h"
#include "qextserialport_win/qextserialport.h"



//开门
#define  WantOpenDoor      "3A 30 32 30 36 31 32 30 33 30 30 30 31 45 32 0D 0A"
#define  StartOpenDoor     "3A 30 32 30 36 31 32 30 34 30 30 30 31 45 31 0D 0A"
#define  AskOpenDoor       "3A 30 32 30 33 31 32 30 34 30 30 30 31 45 34 0D 0A"
#define OpenDoorFail       "3A 30 32 30 33 30 32 30 30 30 31 46 38 0D 0A"
#define OpenDoorSucess     "3A 30 32 30 33 30 32 30 30 30 30 46 39 0D 0A"

//关门
#define  WantDoorClose     "3A 30 32 30 36 31 32 30 33 30 30 30 30 45 33 0D 0A"
#define  StartCloseDoor    "3A 30 32 30 36 31 32 30 34 30 30 30 31 45 31 0D 0A"
#define  AskCloseDoor      "3A 30 32 30 33 31 32 30 34 30 30 30 31 45 34 0D 0A"
#define  CloseDoorFail     "3A 30 32 30 33 30 32 30 30 30 31 46 38 0D 0A"
#define  CloseDoorSucess   "3A 30 32 30 33 30 32 30 30 30 30 46 39 0D 0A"

//吸住托盘
#define WantSuckTray       "3A 30 32 30 36 31 32 30 37 30 30 30 31 44 45 0D 0A"
#define StartSuckTray      "3A 30 32 30 36 31 32 30 38 30 30 30 31 44 44 0D 0A"
#define AskSuckTray        "3A 30 32 30 33 31 32 30 38 30 30 30 31 45 30 0D 0A"
#define SuckTrayFail       "3A 30 32 30 33 30 32 30 30 30 31 46 38 0D 0A"
#define SuckTraySucess     "3A 30 32 30 33 30 32 30 30 30 30 46 39 0D 0A"

//放开托盘
#define WantDropTray      "3A 30 32 30 36 31 32 30 37 30 30 30 30 44 46 0D 0A"
#define StartDropTray     "3A 30 32 30 36 31 32 30 38 30 30 30 31 44 44 0D 0A"
#define AskDropTray       "3A 30 32 30 33 31 32 30 38 30 30 30 31 45 30 0D 0A"
#define DropTrayFail      "3A 30 32 30 33 30 32 30 30 30 31 46 38 0D 0A"
#define DropTraySucess    "3A 30 32 30 33 30 32 30 30 30 30 46 39 0D 0A"

//推送到位
#define  WantPushGoods     "3A 30 32 30 36 31 32 30 35 30 30 30 31 45 30 0D 0A"
#define  StartPushGoods    "3A 30 32 30 36 31 32 30 36 30 30 30 31 44 46 0D 0A"
#define  AskPushGoods      "3A 30 32 30 33 31 32 30 36 30 30 30 31 45 32 0D0A"
#define  PushGoodsFail     "3A 30 32 30 33 30 32 30 30 30 31 46 38 0D 0A"
#define  PushGoodsSucess   "3A 30 32 30 33 30 32 30 30 30 30 46 39 0D 0A"

// 拉取货物
#define  WantGetGoods      "3A 30 32 30 36 31 32 30 35 30 30 30 30 45 31 0D 0A"
#define  StartGetGoods     "3A 30 32 30 36 31 32 30 36 30 30 30 31 44 46 0D 0A"
#define  AskGetGoods       "3A 30 32 30 33 31 32 30 36 30 30 30 31 45 32 0D0A"
#define  GetGoodsFail      "3A 30 32 30 33 30 32 30 30 30 31 46 38 0D 0A"
#define  GetGoodsSucess    "3A 30 32 30 33 30 32 30 30 30 30 46 39 0D 0A"



//运动到行列动作
#define WantMoveToX      "3A 30 32 30 36 31 32 30 30 30 30"
#define WantMoveToY      "3A 30 32 30 36 31 32 30 31 30 30"

#define CountX           "02 06 12 00 00"
#define CountY           "02 06 12 01 00"

#define StartMove        "3A 30 32 30 36 31 32 30 32 30 30 30 31 45 33 0D 0A"
#define AskMove          "3A 30 32 30 33 31 32 30 32 30 30 30 31 45 36 0D 0A"
#define MoveFail         "3A 30 32 30 33 30 32 30 30 30 31 46 38 0D 0A"
#define MoveSucess       "3A 30 32 30 33 30 32 30 30 30 30 46 39 0D 0A"

#define MOVEZEROROW      "3A 30 32 30 36 31 32 30 30 30 30 30 30 45 36 0D 0A"
#define MOVEZEROCOLUMN   "3A 30 32 30 36 31 32 30 31 30 30 30 30 45 35 0D 0A"

#define  MOVEEND         "0D 0A"




#define  SETWEIGHTZERO   "02 52 5A 52 40 BE 0D"
#define  ZEROWEIGHT      "02 40 63 20 20 20 30 2E 30 30 66 A7 0D"


#define  GEIHEIGHT     "01 03 00 05 00 02 D4 0A"

#define   MAXCOLUMN  8
#define   MAXROW     20

#define   ADDROW       5
#define   MAXNULLTRAY  5

#define   ERRORNUM      30
class AppInfo
{
public:
	AppInfo()
	{
		savePoint.setX(0);
		savePoint.setY(0);
		saveQRNum = 0;
		saveHeight = "0";
		saveWeight = "0";
		phoneNum = "0";
		userName = "";
		saveDateTime = "";
		getDateTime = "";
		useState = 0;
	};
public:
	QPoint		savePoint;  //保存的位置
	int			saveQRNum;	//保存的二维码数据	
	QString     saveHeight;//保存的高度
	QString     saveWeight;//保存的重量
	QString     phoneNum;
	QString     userName;
	QString     saveDateTime;               
	QString     getDateTime;
	int         useState;


	//int    isdetele;
};



//静态库
#ifdef _DEBUG

#pragma comment(lib, "../QtControl/lib/vbar.lib")


#else

#pragma comment(lib, "../QtControl/lib/vbar.lib")

#endif
