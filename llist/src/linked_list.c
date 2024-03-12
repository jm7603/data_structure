//
// Created by 张佳鸣 on 2024/3/8.
//

#include "../inc/linked_list.h"

#include <stdlib.h>

// 用于链表为空时添加第一个元素，代码复用
static void AddFirstElem(LinkedList *list, void *data) {
  list->tail = CreateListNode(data);
  list->head = list->tail;
  list->length++;
}

// 用于链表删除最后一个元素，代码复用
static void RemoveTheLastElem(LinkedList *list) {
  DestroyListNode(list->head);
  list->head = list->tail = NULL;
  list->length = 0;
}

static void FillInsert(LinkedList *list, int32_t index, int32_t length, void *data) {
  int diff = index - length;
  while (diff--) ListPushBack(list, NULL);
  ListPushBack(list, data);
}

// 创建链表，初始化
LinkedList *CreateLinkedList() {
  LinkedList *list = malloc(sizeof(LinkedList));
  list->head = list->tail = NULL;
  list->length = 0;
  return list;
}

// 删除链表中所有元素并销毁链表
ListStatusCode DestroyLinkedList(LinkedList *list) {
  if (!list) return LS_ERR;
  if (ListIsEmpty(list)) {
    free(list);
    return LS_OK;
  }

  ClearLinkedList(list);
  free(list);

  return LS_OK;
}

// 清空链表中的所有元素但不销毁链表
ListStatusCode ClearLinkedList(LinkedList *list) {
  if (!list) return LS_ERR;
  if (ListIsEmpty(list)) return LS_EMPTY;

  ListNode *cur = list->head;
  while (cur) {
    ListNode *to_be_destroy = cur;
    cur = cur->next;
    DestroyListNode(to_be_destroy);
  }

  list->head = list->tail = NULL;
  list->length = 0;

  return LS_OK;
}

// 链表判空
bool ListIsEmpty(LinkedList *list) {
  if (!list) return true;
  return list->length == 0;
}

// 返回链表大小
int32_t ListSize(LinkedList *list) {
  if (!list) return 0;
  return list->length;
}

// 尾插
ListStatusCode ListPushBack(LinkedList *list, void *data) {
  if (!list) return LS_ERR;

  // 链表为空时
  if (ListIsEmpty(list)) {
    AddFirstElem(list, data);
    return LS_OK;
  }

  ListNode *node = CreateListNode(data);
  node->prev = list->tail;
  list->tail->next = node;
  list->tail = node;
  list->length++;

  return LS_OK;
}

// 头插
ListStatusCode ListPushFront(LinkedList *list, void *data) {
  if (!list) return LS_ERR;

  // 链表为空时
  if (ListIsEmpty(list)) {
    AddFirstElem(list, data);
    return LS_OK;
  }

  ListNode *node = CreateListNode(data);
  node->next = list->head;
  list->head->prev = node;
  list->head = node;
  list->length++;

  return LS_OK;
}

// 尾删
ListStatusCode ListPopBack(LinkedList *list) {
  if (!list) return LS_ERR;

  if (ListIsEmpty(list)) {
    return LS_EMPTY;
  }

  // 当链表中只有一个元素的情况
  if (list->length == 1) {
    RemoveTheLastElem(list);
    return LS_OK;
  }

  // 当链表中有两个或两个元素以上的情况（正常情况）
  ListNode *to_be_destroy = list->tail;
  list->tail = list->tail->prev;
  list->tail->next = NULL;
  DestroyListNode(to_be_destroy);
  list->length--;

  return LS_OK;
}

// 头删
ListStatusCode ListPopFront(LinkedList *list) {
  if (!list) return LS_ERR;

  if (ListIsEmpty(list)) {
    return LS_EMPTY;
  }

  // 当链表中只有一个元素的情况
  if (list->length == 1) {
    RemoveTheLastElem(list);
    return LS_OK;
  }

  ListNode *to_be_destroy = list->head;
  list->head = list->head->next;
  list->head->prev = NULL;
  DestroyListNode(to_be_destroy);
  list->length--;

  return LS_OK;
}

ListStatusCode ListInsert(LinkedList *list, int32_t index, bool fill, void *data) {
  if (!list) return LS_ERR;
  if (index < 0) return LS_ERR_INDEX;

  int32_t length = ListSize(list);

  // 不填充但插入位置大于长度的情况
  if (index > length && fill == false) return LS_ERR_INDEX;

  // 当链表为空并且插入的位置就是第一个时
  if (length == 0 && index == 0) {
    AddFirstElem(list, data);
    return LS_OK;
  }

  // 正常插入
  // TODO: 根据 index 判断从尾部遍历还是从头部遍历更快
  if (index <= length) {
    ListNode *node = CreateListNode(data);
    ListNode *cur = list->head;
    for (int i = 0; i < index; ++i) cur = cur->next;
    node->next = cur;
    node->prev = cur->prev;
    node->prev->next = node;
    node->next->prev = node;
    list->length++;
    return LS_OK;
  }

  // 填充插入
  FillInsert(list, index, length, data);

  return LS_OK;
}


