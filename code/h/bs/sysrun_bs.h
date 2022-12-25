/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2008-11-2
* Description: 
* History:     
******************************************************************************/

#ifndef __SYSRUN_BS_H_
#define __SYSRUN_BS_H_

#include "utl/sysrun_utl.h"

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

PLUG_API VOID SysrunBs_Exit(INT lExitNum);
PLUG_API BS_STATUS SysrunBs_RegExitNotifyFunc(PF_SYSRUN_EXIT_NOTIFY_FUNC pfFunc,
        IN USER_HANDLE_S *pstUserHandle/* 可以为NULL */);

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__SYSRUN_BS_H_*/


