/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-5-13
* Description: 
* History:     
******************************************************************************/

#ifndef __UTL_SYSCFG_H_
#define __UTL_SYSCFG_H_

#include "utl/cff_utl.h"

#ifdef __cplusplus
    extern "C" {
#endif 

typedef VOID (*PF_SYSCFG_WALK_KEY)(IN CHAR *pcMarkName, IN CHAR *pcKeyName, IN CHAR *pcValueName, IN VOID *pUserHandle);

CHAR * SYSCFG_GetConfigFileName();
CFF_HANDLE SYSCFG_GetCffHandle();
BS_STATUS SYSCFG_GetKeyValueAsUint(IN CHAR *pucMarkName, IN CHAR *pucKeyName, OUT UINT *pulKeyValue);
BS_STATUS SYSCFG_GetKeyValueAsInt(IN CHAR *pucMarkName, IN CHAR *pucKeyName, OUT INT *plKeyValue);
BS_STATUS SYSCFG_GetKeyValueAsString(IN CHAR *pucMarkName, IN CHAR *pucKeyName,  OUT CHAR **ppucKeyValue);
BS_STATUS SYSCFG_WalkKey(IN CHAR *pcMarkName, IN PF_SYSCFG_WALK_KEY pfFunc, IN VOID *pUserHandle);

#ifdef __cplusplus
    }
#endif 

#endif 


