/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-12-3
* Description: 
* History:     
******************************************************************************/

#ifndef __FUNCTBL_BS_H_
#define __FUNCTBL_BS_H_

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

#define FUNCTBL_AddFunc(func,ulRetType,pszFmt)  FUNCTBL_Add(#func, func, ulRetType, pszFmt)
#define FUNCTBL_DelFunc(func)  FUNCTBL_Del(#func)

#define FUNCTBL_RET_VOID        0
#define FUNCTBL_RET_SEQUENCE    1      /* CHAR *字符串,不能是动态内存,因为没有人会释放它 */
#define FUNCTBL_RET_STRING      2      /* STRING */
#define FUNCTBL_RET_UINT32      3
#define FUNCTBL_RET_BOOL        4
#define FUNCTBL_RET_BS_STATUS   FUNCTBL_RET_UINT32


typedef U64 (*PF_FUNCTBL_FUNC_X)(U64 p1, U64 p2, U64 p3, U64 p4, U64 p5, U64 p6, U64 p7, U64 p8, U64 p9, U64 p10);

PLUG_API void * FUNCTBL_GetFunc(IN CHAR *pszFuncName, OUT UINT *pulRetType, OUT CHAR *pszFmt);

/*
* pszFmt 表明注册的这个函数所需要的参数
* u:输入型UINT
* p:输出型UINT, 也可以输入
* b: 输入型CHAR *字符串
* s:输入型STRING
* o:输出型STRING, 也可以输入
*/
PLUG_API BS_STATUS FUNCTBL_Add(CHAR *pszFuncName, void *pfFunc, UINT ulRetType, CHAR *pszFmt);
PLUG_API BS_STATUS FUNCTBL_Del(IN CHAR *pszFuncName);
PLUG_API HANDLE FUNCTBL_Call(IN CHAR *pszFuncName, IN UINT ulArgsCount, ...);


#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__FUNCTBL_BS_H_*/


