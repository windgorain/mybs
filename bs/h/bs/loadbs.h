/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2008-3-17
* Description: 用于给使用bs.dll的应用程序调用,以加载bs.dll
* History:     
******************************************************************************/

#ifndef __LOADBS_UTL_H_
#define __LOADBS_UTL_H_

#ifdef __cplusplus
    extern "C" {
#endif 

PLUG_API void LoadBs_SetArgv(IN UINT uiArgc, IN CHAR **ppcArgv);
PLUG_API void LoadBs_SetMainMode();
PLUG_API int LoadBs_Init();
PLUG_API void LoadBs_Main();

#ifdef __cplusplus
    }
#endif 

#endif 


