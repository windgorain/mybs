/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2008-3-17
* Description: 用于给使用bs.dll的应用程序调用,以加载bs.dll
* History:     
******************************************************************************/

#ifndef __LOADBS_UTL_H_
#define __LOADBS_UTL_H_

#include "utl/types.h"

#ifdef __cplusplus
    extern "C" {
#endif 

PLUG_API void LoadBs_SetArgv(IN UINT uiArgc, IN CHAR **ppcArgv);
PLUG_API void LoadBs_SetMainMode();
PLUG_API int LoadBs_Init();
PLUG_API void LoadBs_Main();
PLUG_API int LoadBs_Load(int argc, char **argv, char *conf_path);

typedef int (*PF_LoadBs_Load)(int argc, char **argv, char *conf_path);

static inline int LoadBs_LoadSo(char *so_file, int argc, char **argv, char *conf_path)
{
    PF_LoadBs_Load func;

    void *plug = PLUG_RAW_LOAD(so_file);
    if (! plug) {
        return -1;
    }

    func = PLUG_GET_FUNC_BY_NAME(plug, "LoadBs_Load");
    if (! func) {
        PLUG_RAW_FREE(plug);
        return -1;
    }

    func(argc, argv, "conf_dft");

    return 0;
}

#ifdef __cplusplus
    }
#endif 

#endif 


