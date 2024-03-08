/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _COMP_POLLER_H
#define _COMP_POLLER_H
#include "utl/ob_utl.h"
#include "utl/mypoll_utl.h"
#ifdef __cplusplus
extern "C"
{
#endif

typedef void (*PF_POLLER_TriggerCB)(void *ob);

PLUG_API void * PollerComp_Get(char *name);
PLUG_API void PollerComp_Free(void *ins);
PLUG_API MYPOLL_HANDLE PollerComp_GetMyPoll(void *ins);
PLUG_API void PollerComp_RegOb(void *ins, OB_S *ob);
PLUG_API void PollerComp_UnRegOb(OB_S *ob);
PLUG_API void PollerComp_Trigger(void *ins);

#ifdef __cplusplus
}
#endif
#endif 
