/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-5-20
* Description: 
* History:     
******************************************************************************/
#ifndef __CMD_EXP_H_
#define __CMD_EXP_H_

#include "utl/cmd_exp.h"

#ifdef __cplusplus
    extern "C" {
#endif 





PLUG_API BS_STATUS CMD_CFG_Init();
PLUG_API BS_STATUS CMD_MNG_CmdRestoreByFile(int muc_id, char *pszFileName);
PLUG_API BS_STATUS CMD_MNG_CmdRestoreSysCmd();   

PLUG_API BS_STATUS CMD_EXP_Init();
PLUG_API VOID CMD_EXP_RegNoDbgFunc(IN CMD_EXP_NO_DBG_NODE_S *pstNode);
PLUG_API BS_STATUS CMD_EXP_RegCmd(IN CMD_EXP_REG_CMD_PARAM_S *pstParam);
BS_STATUS CMD_EXP_UnregCmd(IN CMD_EXP_REG_CMD_PARAM_S *pstParam);
BS_STATUS CMD_EXP_RegCmdSimple(char *view, char *cmd,
        PF_CMD_EXP_RUN func, void *ud);
int CMD_EXP_UnregCmdSimple(char *view, char *cmd);
PLUG_API HANDLE CMD_EXP_CreateRunner(UINT type);
PLUG_API BS_STATUS CMD_CFG_RegFunc(char *func_name, PF_CMD_EXP_RUN func);
PLUG_API BS_STATUS CMD_CFG_RegCmd(IN CHAR *pszFileName, IN PLUG_HDL plug, char *save_path);
PLUG_API BS_STATUS CMD_CFG_UnRegCmd(CHAR *pszFileName, char *save_path);
BS_STATUS CMD_EXP_RegSave(char *save_path, CMD_EXP_REG_CMD_PARAM_S *param);
BS_STATUS CMD_EXP_RegEnter(CMD_EXP_REG_CMD_PARAM_S *param);
PLUG_API BS_STATUS CMD_EXP_UnRegSave(char *save_path, char *pcViews);
PLUG_API int CMD_EXP_DoCmd(char *cmd);
PLUG_API int CMD_EXP_CmdSave(UINT ulArgc, CHAR **pArgv, VOID *pEnv);

#ifdef __cplusplus
    }
#endif 

#endif 



