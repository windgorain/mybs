/******************************************************************************
* Copyright (C) Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2013-1-8
* Description: 
* History:     
******************************************************************************/

#ifndef __COMP_BS_H_
#define __COMP_BS_H_

#ifdef __cplusplus
    extern "C" {
#endif 

enum {
    COMP_ID_ACL = 0,

    COMP_ID_MAX
};

typedef int (*PF_COMP_FUNC)(int cmd, void *data);

typedef struct {
    PF_COMP_FUNC ioctl_func;
}COMP_NODE_S;

PLUG_API int COMP_Reg(UINT comp_id, COMP_NODE_S *node);
PLUG_API void COMP_Unreg(UINT comp_id);
PLUG_API int COMP_Ioctl(UINT comp_id, int cmd, void *data);

#ifdef __cplusplus
    }
#endif 

#endif 


