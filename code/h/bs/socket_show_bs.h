/******************************************************************************
* Copyright (C), LiXingang
* Author:      LiXingang  Version: 1.0  Date: 2011-3-24
* Description: 
* History:     
******************************************************************************/

#ifndef __SOCKET_SHOW_BS_H_
#define __SOCKET_SHOW_BS_H_

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */


PLUG_API BS_STATUS SSHOW_ShowAll (IN UINT ulArgc, IN CHAR **argv);
PLUG_API BS_STATUS SSHOW_ShowTcp (IN UINT ulArgc, IN CHAR **argv);
PLUG_API BS_STATUS SSHOW_ShowUdp (IN UINT ulArgc, IN CHAR **argv);
PLUG_API BS_STATUS _sshow_Add(IN INT iSocketId, char *file, int line);
PLUG_API VOID _sshow_Del(IN INT iSocketId);

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__SOCKET_SHOW_BS_H_*/


