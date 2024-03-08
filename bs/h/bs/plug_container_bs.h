/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-8-24
* Description: 
* History:     
******************************************************************************/

#ifndef __PLUG_CONTAINER_BS_H_
#define __PLUG_CONTAINER_BS_H_

#include "utl/plug_mgr.h"

#ifdef __cplusplus
    extern "C" {
#endif 



BS_STATUS PLUGCT_Init();

BS_STATUS PLUGCT_LoadPlug(IN UINT uiArgc, IN CHAR **ppcArgv);
PLUG_API int PLUGCT_ShowPlug(UINT argc, char **argv);

UINT PLUGCT_GetLoadStage();

#ifdef __cplusplus
    }
#endif 

#endif 


