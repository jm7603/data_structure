//
// Created by jm on 2024/3/8.
//

#include "../inc/list_node.h"

#include <stdlib.h>

// 创建节点并初始化
ListNode *CreateListNode(void *data) {
  ListNode *node = malloc(sizeof(ListNode));
  node->data = data;
  node->prev = NULL;
  node->next = NULL;
  return node;
}

// 销毁节点中的数据并销毁节点
ListStatusCode DestroyListNode(ListNode *node) {
  if (!node) return LS_ERR;
  if (node->data) free(node->data);
  free(node);
  return LS_OK;
}
