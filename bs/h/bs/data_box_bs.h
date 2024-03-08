/*********************************************************
*   Copyright (C) LiXingang
*   Description: 
*
********************************************************/
#ifndef _DATA_BOX_BS_H
#define _DATA_BOX_BS_H

#ifdef __cplusplus
extern "C"
{
#endif

#define DB_BS_MAX 32

extern void * g_databox_bs[DB_BS_MAX];

static inline void DB_Set(int id, void *d) {
    BS_DBGASSERT(id < DB_BS_MAX);
    g_databox_bs[id] = d;
}

static inline void * DB_Get(int id) {
    BS_DBGASSERT(id < DB_BS_MAX);
    return g_databox_bs[id];
}

#ifdef __cplusplus
}
#endif
#endif 
