/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      Xingang.Li  Version: 1.0  Date: 2007-8-18
* Description: 
* History:     
******************************************************************************/
#ifndef _AES_UTL_H
#define _AES_UTL_H
#ifdef __cplusplus
extern "C"
{
#endif

#define AES_IV_SIZE 128 /* aes 1k. 如果大于1k，还需要继续扩大 */

/* 根据明文长度计算aes加密后的密文长度 */
#define AES_CIPHER_LEN(clear_len) NUM_UP_ALIGN(clear_len, 128)
#define AES_CIPHER_PAD_LEN(clear_len) NUM_ALIGN_DIFF(clear_len, 128)

void * AES_GetSysKey();
void * AES_GetSysIv();
int AES_Cipher128(UCHAR *key, UCHAR *iv, UCHAR *in, int in_size, UCHAR *out, int out_size, int do_encrypt);
int AES_Cipher256(UCHAR *key, UCHAR *iv, UCHAR *in, int in_size, UCHAR *out, int out_size, int do_encrypt);

#ifdef __cplusplus
}
#endif
#endif //AES_UTL_H_
