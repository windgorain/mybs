/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-7-2
* Description: Index从1开始计算.0是无效值
* History:     
******************************************************************************/
/* retcode所需要的宏 */
#define RETCODE_FILE_NUM RETCODE_FILE_NUM_BITMAP

#include "bs.h"

#include "utl/bitmap_utl.h"
#include "utl/bitmap1_utl.h"

static INT64 bitmap_index_to_index1(INT64 index)
{
    return index + 1;
}

INT64 bitmap_index1_to_index(INT64 index_from1)
{
    return index_from1 - 1;
}

/* 获取一个setted位的Index */
UINT BITMAP1_GetASettedBitIndex(IN BITMAP_S *pstBitMap)
{
    return bitmap_index_to_index1(BITMAP_GetBusy(pstBitMap));
}

/* 获取某个指定位置之后的setted位的Index */
UINT BITMAP1_GetBusyFrom(BITMAP_S *pstBitMap, UINT from)
{
    return bitmap_index_to_index1(BITMAP_GetBusyFrom(pstBitMap, bitmap_index1_to_index(from)));
}

/* 获取一个unsetted位的Index */
UINT BITMAP1_GetFree(IN BITMAP_S *pstBitMap)
{
    return bitmap_index_to_index1(BITMAP_GetFree(pstBitMap));
}

/* 环绕形式的获取一个unsetted位的Index */
UINT BITMAP1_GetFreeCycle(IN BITMAP_S *pstBitMap)
{
    return bitmap_index_to_index1(BITMAP_GetFreeCycle(pstBitMap));
}

/* 从两个bitmap中获取都被设置的位的IndexFrom1 */
UINT BITMAP1_2GetBusy(IN BITMAP_S * pstBitMap1, IN BITMAP_S * pstBitMap2)
{
    return bitmap_index_to_index1(BITMAP_2GetSettedIndex(pstBitMap1, pstBitMap2));
}

/* 从两个bitmap中获取都未被设置的位的IndexFrom1 */
UINT BITMAP1_2GetFree(IN BITMAP_S * pstBitMap1, IN BITMAP_S * pstBitMap2)
{
    return bitmap_index_to_index1(BITMAP_2GetUnsettedIndex(pstBitMap1, pstBitMap2));
}

