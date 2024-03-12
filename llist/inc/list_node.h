//
// Created by jm on 2024/3/8.
//

#ifndef DATASTRUCTURE_INCLUDE_LIST_NODE_H_
#define DATASTRUCTURE_INCLUDE_LIST_NODE_H_

#include "status_code.h"

typedef struct ListNode {
  void *data;
  struct ListNode *prev;
  struct ListNode *next;
} ListNode;

ListNode *CreateListNode(void *);

ListStatusCode DestroyListNode(ListNode *);

#endif //DATASTRUCTURE_INCLUDE_LIST_NODE_H_
