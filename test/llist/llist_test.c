//
// Created by jm on 2024/3/10.
//

#include <stdio.h>
#include <stdlib.h>

//#define PRINT_METADATA // io_utils.h
#include "inc/common/io_utils.h"
#include "llist/inc/linked_list.h"

int main(void) {
  LinkedList *list = CreateLinkedList();

  // 使用 ListInsert 进行头插
  int *a = malloc(sizeof(int));
  *a = 999;
  ListInsert(list, 0, false, a);

  for (int i = 0; i < 10; ++i) {
    int *data = malloc(sizeof(int));
    *data = i + 1;

    // 尾插
    ListPushBack(list, data);

    // 头插
    //ListPushFront(list, data);
  }

  // 从头到尾遍历
  ListNode *cur = list->head;
  while (cur) {
    PRINT_INT(*((int *) cur->data));
    cur = cur->next;
  }

  // 尾删
  ListPopBack(list);
  ListPopBack(list);
  ListPopBack(list);

  PRINTLNF("============");

  // 从尾到头遍历
  //cur = list->tail;
  //while (cur) {
  //  PRINT_INT(*((int *) cur->data));
  //  cur = cur->prev;
  //}

  // 填充插入
  int *d = malloc(sizeof(int));
  *d = 99;
  ListInsert(list, 9, true, d);

  cur = list->head;
  while (cur) {
    if (cur->data)
      PRINT_INT(*((int *) cur->data));
    else
      PRINTLNF("NULL");
    cur = cur->next;
  }

  PRINTLNF("list head: %d", *((int *) list->head->data));
  PRINTLNF("list tail: %d", *((int *) list->tail->data));

  DestroyLinkedList(list);
  return 0;
}

