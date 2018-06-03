#pragma once
#include <memory>
#include "../QtControl/include/develop_interface.h"
#include "../QtControl/log/log_deffine.h"
#include "Base/myhelper.h"
#include "Base/RunTime.h"

enum WIDGET_TYPE
{
	MSGBOX_GET = 0x0001,
	MSGBOX_SAVE = 0x0002,
	MSGBOX_CLOSE = 0x0004,
	MSGBOX_BACK = 0x0008,
	MSGBOX_HOME = 0x00010,
	MSGBOX_OK = 0x00020
};


//¾²Ì¬¿â
#ifdef _DEBUG

#pragma comment(lib, "../QtControl/lib/vbar.lib")


#else

#pragma comment(lib, "../QtControl/lib/vbar.lib")

#endif
