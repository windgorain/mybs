/*********************************************************
*   Copyright (C) LiXingang
*   Description: 
*
********************************************************/
#ifndef _ELF_DEF_H
#define _ELF_DEF_H
#ifdef __cplusplus
extern "C"
{
#endif

typedef struct {
    char *sec_name;
    char *func_name;
    UINT sec_offset; /* sec在progs中的offset, 字节为单位. 一个sec中可能有多个prog. 如.text sec */
    UINT prog_offset; /* prog整个progs中的offset, 字节为单位 */
    UINT size; /* prog 大小, 字节为单位 */
    int  sec_id; /* 在elf中的sec id */
}ELF_PROG_INFO_S;

#ifdef __cplusplus
}
#endif
#endif //ELF_DEF_H_
