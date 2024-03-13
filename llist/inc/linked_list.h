//
// Created by jm on 2024/3/8.
//

#ifndef DATASTRUCTURE_INCLUDE_LLIST_LINKED_LIST_H_
#define DATASTRUCTURE_INCLUDE_LLIST_LINKED_LIST_H_

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include "list_node.h"

typedef struct LinkedList {
  ListNode *head;
  ListNode *tail;
  int32_t length;
} LinkedList;

LinkedList *CreateLinkedList();

ListStatusCode DestroyLinkedList(LinkedList *list);

ListStatusCode ClearLinkedList(LinkedList *list);

bool ListIsEmpty(LinkedList *list);

int32_t ListSize(LinkedList *list);

ListStatusCode ListPushBack(LinkedList *list, void *data);

ListStatusCode ListPushFront(LinkedList *list, void *data);

ListStatusCode ListPopBack(LinkedList *list);

ListStatusCode ListPopFront(LinkedList *list);

/**
 * 在链表指定位置插入节点
 * @param list 链表
 * @param index 插入的位置（从 0 开始）
 * @param fill 当 index 超过链表大小时是否填充，中间所填充节点中的数据默认为 NULL
 * @param data 存入节点中的数据
 * @return 状态码，详见 ListStatusCode
 */
ListStatusCode ListInsert(LinkedList *list, int32_t index, bool fill, void *data);

ListStatusCode ListRemove(LinkedList *list, int32_t index);

ListStatusCode ListUpdate(LinkedList *list, int32_t index, void *data);

ListStatusCode ListGetElem(LinkedList *list, int32_t index, void **res);

#endif //DATASTRUCTURE_INCLUDE_LLIST_LINKED_LIST_H_
