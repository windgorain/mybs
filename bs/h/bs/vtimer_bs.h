/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-8-17
* Description: 
* History:     
******************************************************************************/

#ifndef __VTIMER_BS_H_
#define __VTIMER_BS_H_

#ifdef __cplusplus
    extern "C" {
#endif 

PLUG_API BS_STATUS VTimer_Create
(
    IN UINT ulTime, 
    IN UINT flag,
    IN PF_TIME_OUT_FUNC pfFunc,
    IN USER_HANDLE_S *pstUserHandle,
    OUT HANDLE *phVTimerID
);
PLUG_API BS_STATUS VTimer_Delete(IN HANDLE hVTimerID);
PLUG_API BS_STATUS VTimer_Pause(IN HANDLE hVTimerID);
PLUG_API BS_STATUS VTimer_Resume(IN HANDLE hVTimerID);
PLUG_API BS_STATUS VTimer_GetInfo(IN HANDLE hVTimerID, OUT TIMER_INFO_S *pstTimerInfo);
PLUG_API BS_STATUS VTimer_ReSetTime(IN HANDLE hVTimerID, IN UINT ulTime);

#ifdef __cplusplus
    }
#endif 

#endif 


