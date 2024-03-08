/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      lixingang  Version: 1.0  Date: 2007-2-3
* Description: 
* History:     
******************************************************************************/
#ifndef __SPLX_H_
#define __SPLX_H_
	
#ifdef __cplusplus
	extern "C" {
#endif 

PLUG_API BS_STATUS SPLX_Display();

PLUG_API VOID _SPLX_P (IN CHAR *pcFilename, IN UINT uiLine);
PLUG_API VOID SPLX_V ();

#define SPLX_P() _SPLX_P(__FILE__, __LINE__)


#ifdef __cplusplus
}
#endif 

#endif 

