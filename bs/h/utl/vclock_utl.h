/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2008-10-9
* Description: 
* History:     
******************************************************************************/

#ifndef __VCLOCK_UTL_H_
#define __VCLOCK_UTL_H_

#include "utl/mutex_utl.h"
#include "utl/timer_common.h"

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#define _VCLOCK_TIMER_TOTLE_LEVEL 6
#define _VCLOCK_TIMER_SCALE_PER_LEVEL 64


/* structs */
typedef struct
{
    DLL_NODE_S stDllNode;
    UINT ulTick;        /* 定时时间 */
    UINT uiTriggerTick; /* 触发时间 */
    UINT flag;
    PF_TIME_OUT_FUNC pfFunc;
    USER_HANDLE_S stUserHandle;
}VCLOCK_NODE_S;

typedef struct
{
    UINT create_lock:1;
    MUTEX_S lock;
    UINT ulNodeCount;
    UINT uiCurrentTick; /* 当前时间, 每次TickStep时加1  */
    UINT ulCurrentLevelTick[_VCLOCK_TIMER_TOTLE_LEVEL];  /* 当前各个级别所处的时刻 */
    DLL_HEAD_S stTimerLevel[_VCLOCK_TIMER_TOTLE_LEVEL][_VCLOCK_TIMER_SCALE_PER_LEVEL];
}VCLOCK_INSTANCE_S;

typedef VCLOCK_INSTANCE_S* VCLOCK_INSTANCE_HANDLE;
typedef VCLOCK_NODE_S* VCLOCK_HANDLE;

int VCLOCK_InitInstance(OUT VCLOCK_INSTANCE_S *pstVClockInstance, BOOL_T bCreateLock);
void VCLOCK_FiniInstance(VCLOCK_INSTANCE_S *pstVClockInstance);

VCLOCK_INSTANCE_HANDLE  VCLOCK_CreateInstance(BOOL_T bCreateLock);
void VCLOCK_DeleteInstance(VCLOCK_INSTANCE_HANDLE hVClock);

int VCLOCK_AddTimer
(
    VCLOCK_INSTANCE_S *pstVClockInstance,
    VCLOCK_NODE_S *vclock_node,
    UINT first_tick, /* 第一次超时时间 */
    UINT tick,      /* 后续超时时间 */
    UINT flag,
    PF_TIME_OUT_FUNC pfFunc,
    USER_HANDLE_S *pstUserHandle
);
BS_STATUS VCLOCK_DelTimer(VCLOCK_INSTANCE_HANDLE hVClockInstanceId, VCLOCK_NODE_S *vclock_node);

BOOL_T VCLOCK_IsRunning(VCLOCK_NODE_S *vclock_node);

VCLOCK_NODE_S * VCLOCK_CreateTimer
(
    VCLOCK_INSTANCE_HANDLE hVClockInstanceId,
    UINT first_tick, /* 第一次超时时间 */
    UINT tick,      /* 后续超时时间 */
    UINT flag,
    PF_TIME_OUT_FUNC pfFunc,
    USER_HANDLE_S *pstUserHandle
);
void VCLOCK_DestroyTimer(VCLOCK_INSTANCE_S *pstVClockInstance, VCLOCK_NODE_S *hTimer);

BS_STATUS VCLOCK_Pause(VCLOCK_INSTANCE_HANDLE hVClockInstanceId, VCLOCK_NODE_S *hTimerId);
BS_STATUS VCLOCK_Resume(VCLOCK_INSTANCE_HANDLE hVClockInstanceId, VCLOCK_NODE_S *hTimerId, UINT first_tick);
BS_STATUS VCLOCK_GetInfo(VCLOCK_INSTANCE_HANDLE hVClockInstanceId, VCLOCK_NODE_S *hTimerId, OUT TIMER_INFO_S *pstTimerInfo);
BS_STATUS VCLOCK_RestartWithTick(VCLOCK_INSTANCE_HANDLE hVClockInstanceId, VCLOCK_NODE_S *hTimerId, UINT first_tick, UINT tick);
BS_STATUS VCLOCK_Refresh(VCLOCK_INSTANCE_HANDLE hVClockInstanceId, VCLOCK_NODE_S *hTimerId);
UINT VCLOCK_GetTickLeft(VCLOCK_INSTANCE_HANDLE hVClockInstanceId, VCLOCK_NODE_S *hTimerId);

/* 触发一次tick */
BS_STATUS VCLOCK_Step(VCLOCK_INSTANCE_HANDLE hVClockInstanceId);


#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /* __VCLOCK_UTL_H_ */


