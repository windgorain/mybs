/*================================================================
*   Created by LiXingang
*   Description: 
*
================================================================*/
#include "bs.h"
#include "utl/num_utl.h"
#include "utl/bit_opt.h"
#include "utl/txt_utl.h"
#include "utl/mem_utl.h"
#include "utl/socket_utl.h"

BOOL_T Socket_IsIPv4(IN CHAR *pcIpOrName)
{
    CHAR *pcTmp = pcIpOrName;
    CHAR *pcSplit;
    UINT ulLen, i, j;

    for (j=0; j<4; j++) {
        /* 最后一节是没有'.' 的，前三节都有'.' */
        if (j < 3) {
            pcSplit = strchr(pcTmp, '.');
            if (pcSplit == NULL) {
                return FALSE;
            }
        } else {
            pcSplit = pcTmp + strlen(pcTmp);
        }
        
        ulLen = (UINT)(pcSplit - pcTmp);
        if (ulLen > 3) {     /* 长度不能超过3 */
            return FALSE;
        }
        for (i=0; i<ulLen; i++) {     /* IP 必须是数字 */
            if (!NUM_IN_RANGE((INT)pcTmp[i], (INT)'0', (INT)'9')) {
                return FALSE;
            }
        }
        if (ulLen == 3) {    /* 不能大于255 */
            if (pcTmp[0] > '2') {
                return FALSE;
            }

            if (pcTmp[0] == '2') {
                if (pcTmp[1] > '5') {
                    return FALSE;
                }

                if (pcTmp[1] == '5') {
                    if (pcTmp[2] > '5') {
                        return FALSE;
                    }
                }
            }

        }
        pcTmp = pcSplit + 1;
    }

    return TRUE;
}

/* 将字符串形式的IP 转换成网络序IP地址 */
UINT Socket_Ipsz2IpNet(char *pcIP)
{
    return inet_addr(pcIP);
}

UINT Socket_Ipsz2IpHost(IN CHAR *pcIP)
{
    UINT uiIp;

    uiIp = Socket_Ipsz2IpNet(pcIP);

    return ntohl(uiIp);
}

