/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _POLLER_BS_H
#define _POLLER_BS_H

#include "utl/mypoll_utl.h"
#include "utl/ob_utl.h"

#ifdef __cplusplus
extern "C"
{
#endif

void PollerBs_SetMainMode();
void PollerBs_Run();

typedef void (*PF_POLLERBS_TriggerCB)();

PLUG_API MYPOLL_HANDLE PollerBS_GetPoller();
PLUG_API void PollerBS_RegOb(OB_S *ob);
PLUG_API void PollerBS_UnRegOb(OB_S *ob);
PLUG_API void PollerBS_Trigger();

#ifdef __cplusplus
}
#endif
#endif 
