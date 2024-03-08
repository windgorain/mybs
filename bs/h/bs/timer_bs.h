/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-8-16
* Description: 定时器模块. 这个定时器精确度较高,要求回调函数执行时间较短。
*                  直接创建的Timer越少, 则Timer精确度越高,所以,
*                  如果对时间精确度没有特别高的要求，请使用VTimer或MTimer。
* History:     
******************************************************************************/
#ifndef __TIMER_BS_H_
#define __TIMER_BS_H_

#include "utl/timer_utl.h"
#include "utl/timer_single.h"

#ifdef __cplusplus
    extern "C" {
#endif 


PLUG_API HANDLE Timer_Create
(
    IN UINT ulTime, 
    IN UINT flag,
    IN PF_TIME_OUT_FUNC pfFunc,
    IN USER_HANDLE_S *pstUserHandle 
);
PLUG_API BS_STATUS Timer_Delete(IN HANDLE timer);
PLUG_API BS_STATUS Timer_Pause(IN HANDLE timer);
PLUG_API BS_STATUS Timer_Resume(IN HANDLE timer);
PLUG_API BS_STATUS Timer_ReSetTime(IN HANDLE timer, IN UINT ulTime);
PLUG_API BS_STATUS Timer_GetInfo(IN HANDLE timer, OUT TIMER_INFO_S *pstTimerInfo);


#ifdef __cplusplus
    }
#endif 

#endif 


