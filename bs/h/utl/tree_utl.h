/******************************************************************************
* Copyright (C), Xingang.Li
* Author:      LiXingang  Version: 1.0  Date: 2010-1-13
* Description: 
* History:     
******************************************************************************/

#ifndef __TREE_UTL_H_
#define __TREE_UTL_H_

#ifdef __cplusplus
    extern "C" {
#endif /* __cplusplus */

typedef HANDLE TREE_HANDLE;

typedef struct TREE_NODE_ST
{
    DLL_NODE_S stLinkNode;  /* 兄弟节点 */
    DLL_HEAD_S stChildNode; /* 孩子结点 */
}TREE_NODE_S;

typedef struct {
    TREE_NODE_S root;
}TREE_CTRL_S;


#define TREE_IS_LEAF(pstNode)   (DLL_COUNT(&((pstNode)->stChildNode)) == 0 ? TRUE : FALSE)
#define TREE_IS_ROOT(pstNode)   (DLL_GET_HEAD(pstNode) == NULL ? TRUE : FALSE)
#define TREE_SCAN_SUBNODE(pstRoot, pstNode)  DLL_SCAN(&((pstRoot)->stChildNode), (pstNode))
#define TREE_SAFE_SCAN_SUBNODE(pstRoot, pstNode,pstNodeTmp)  DLL_SAFE_SCAN(&((pstRoot)->stChildNode), (pstNode),(pstNodeTmp))

typedef int (*PF_TREE_DepthScanNode)(IN TREE_NODE_S *pstNode, IN UINT ulDeepth, IN VOID *pUserHandle);
typedef int (*PF_TREE_DepthWalkNode)(IN TREE_NODE_S *pstNode, IN UINT ulDeepth, IN BOOL_T bIsBack, IN VOID * pUserHandle);

TREE_HANDLE Tree_Create();
void TREE_NodeInit(IN TREE_NODE_S *pstNode);
int TREE_AddNode(IN TREE_NODE_S *pstParent, IN TREE_NODE_S *pstChildNode);
int TREE_RemoveNode(IN TREE_NODE_S *pstNode);
TREE_NODE_S * TREE_GetParent(IN TREE_NODE_S *pstNode);

/* 深度优先遍历. 父优先. root节点也遍历 */
int TREE_DepthParentFirstWalk(TREE_NODE_S *pstRoot, PF_TREE_DepthScanNode pfFunc, VOID *pUserHandle);

/* 深度优先遍历. 子优先.root 节点也遍历 */
int TREE_DepthChildFirstWalk(TREE_NODE_S *pstRoot, PF_TREE_DepthScanNode pfFunc, VOID *pUserHandle);

/* 
就像走路一样,经过每个节点，有去有回。
 不像是深度遍历只取不回的跳跃遍历.
 root节点也遍历.每个节点都有来回两次.
 */
int TREE_DepthBackWalk(TREE_NODE_S *pstRoot, PF_TREE_DepthWalkNode pfFunc, VOID *pUserHandle);

#ifdef __cplusplus
    }
#endif /* __cplusplus */

#endif /*__TREE_UTL_H_*/


