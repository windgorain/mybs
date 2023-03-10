/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#include "bs.h"

#include "sys/stat.h"
#include "utl/mem_utl.h"
#include "utl/file_utl.h"
#include "utl/txt_utl.h"
#include "utl/cjson.h"
#include "utl/passwd_utl.h"
#include <stdbool.h>

cJSON * FILE_LoadJson(const char *filename, bool is_encrypt)
{
    FILE_MEM_S *filemem = FILE_Mem((char*)filename);
    if (! filemem) {
        return NULL;
    }

    int decrypt_len = filemem->uiFileLen/2 + 1;

    CHAR *decrypt = (CHAR*)filemem->pucFileData;
    CHAR *decrypt_file = MEM_ZMalloc(decrypt_len);
    if (!decrypt_file) {
        FILE_MemFree(filemem);
        return NULL;
    }

    if (is_encrypt) {
        PW_HexDecrypt(decrypt, decrypt_file, decrypt_len);
        decrypt = decrypt_file;
    }

    cJSON *rule = cJSON_Parse(decrypt);

    FILE_MemFree(filemem);
    MEM_Free(decrypt_file);

    return rule;
}
