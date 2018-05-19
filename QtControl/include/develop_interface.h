#ifndef DEVELOP_INTERFACE_H_INCLUDED
#define DEVELOP_INTERFACE_H_INCLUDED

/* bool类型支持 */


/* 动态导出函数的声明宏 */
#ifdef VBAR_BUILD_AS_DLL
#   if defined(_WIN32) || defined(_WIN64)
#       ifdef VBAR_LIB
#           define VBARLIB_API __declspec(dllexport)
#       else
#           define VBARLIB_API __declspec(dllimport)
#       endif
#   elif defined(__GNUC__) && defined(__linux__)
#       ifdef VBAR_LIB
#           define VBARLIB_API __attribute__((visibility("default")))
#       else
#           define VBARLIB_API
#       endif
#   else
#       error "不支持的操作系统"
#   endif
#else
#   define VBARLIB_API
#endif /* VBAR_BUILD_AS_DLL */






#include <stdio.h>
/* 条码符号类别ID定义 */
#define VBAR_SYM_NONE           0   /* 代表无效ID */
#define VBAR_SYM_QRCODE         1
#define VBAR_SYM_EAN8           2
#define VBAR_SYM_EAN13          3
#define VBAR_SYM_ISBN13         4
#define VBAR_SYM_CODE39         5
#define VBAR_SYM_CODE93         6
#define VBAR_SYM_CODE128        7
#define VBAR_SYM_DATABAR        8
#define VBAR_SYM_DATABAR_EXP    9
#define VBAR_SYM_PDF417         10
#define VBAR_SYM_DATAMATRIX     11
#define VBAR_SYM_ITF            12
#define VBAR_SYM_ISBN10         13
#define VBAR_SYM_UPCE           14
#define VBAR_SYM_UPCA           15


/* 令C/C++兼容支持bool类型 */
#ifndef __cplusplus
#   ifndef bool
#   define bool     int
#   endif /* bool */
#   ifndef false
#   define false    0
#   endif /* false */
#   ifndef true
#   define true     (!false)
#   endif /* true */
#endif /* __cplusplus */

#ifdef __cplusplus
extern "C" 

{
#endif

/*设备连接接口 成功返回设备句柄，失败返回NULL*/
VBARLIB_API struct vbar_channel *vbar_connectDevice(unsigned long arg);
/*设备号获取接口 成功返回 0 失败返回-1*/
VBARLIB_API int vbar_get_devnum(struct vbar_channel * channel, unsigned char* devnum);
/*补光灯控制接口 成功返回 0 失败返回-1*/
VBARLIB_API int vbar_backlight(struct vbar_channel *channel, bool bswitch);
/*扫描间隔时间设置接口 成功返回 0 失败返回-1*/
VBARLIB_API int vbar_interval(struct vbar_channel *channel, int time);
/*码制添加接口 成功返回 0 失败返回-1*/
VBARLIB_API int vbar_addCodeFormat(struct vbar_channel *channel, unsigned char codeFormat);
/*蜂鸣器控制接口 成功返回 0 失败返回-1*/
VBARLIB_API int vbar_beepControl(struct vbar_channel *channel, unsigned char times);
/*版本号获取接口 成功返回 0 失败返回-1*/
VBARLIB_API int vbar_getVersion(struct vbar_channel *channel, unsigned char *result_buffer, int *result_size);
/*获取扫码结果接口 成功返回 0 失败返回-1*/
VBARLIB_API int vbar_getResultStr(struct vbar_channel *channel, unsigned char *result_buffer, int *result_size, int *result_type);
/*关闭设备接口*/
VBARLIB_API void vbar_disconnectDevice(struct vbar_channel *channel);

#ifdef __cplusplus

}

#endif


#endif // DEVELOP_INTERFACE_H_INCLUDED
