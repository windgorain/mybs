/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#ifndef _PROCESS_KEY_H
#define _PROCESS_KEY_H
#ifdef __cplusplus
extern "C"
{
#endif

PLUG_API void ProcessKey_SetKey(char *key);
PLUG_API char * ProcessKey_GetKey();
PLUG_API void ProcessKey_SetIndex(int index);
PLUG_API int ProcessKey_GetIndex();
PLUG_API int ProcessKey_ShowStatus();

#ifdef __cplusplus
}
#endif
#endif 
