//
// Created by jm on 2024/3/10.
//

#include <stdio.h>
#include <stdlib.h>

#define PRINT_METADATA // io_utils.h
#include "inc/common/io_utils.h"
#include "llist/inc/linked_list.h"
#include "inc/minunit/minunit.h"

static LinkedList *g_list;

static void PrintList(const char *const location) {
  PRINT_STRING(location);
  ListNode *cur = g_list->head;
  while (cur) {
    printf("%d%c", *((int *)(cur->data)), cur->next ? ' ' : '\n');
    cur = cur->next;
  }
}

void test_global_setup(void) {
  g_list = CreateLinkedList();
}

void test_global_teardown(void) {
  DestroyLinkedList(g_list);
}

void test_setup(void) {
  PRINTLNF("test_setup");
  // g_list = CreateLinkedList();
}

void test_teardown(void) {
  PRINTLNF("test_teardown");
  // DestroyLinkedList(g_list);
}

MU_TEST(test_create) {
  mu_assert(g_list != NULL, "list create failed: allocate");
}

MU_TEST(test_add) {
  for (int i = 1; i <= 5; ++i) {
    int *t = malloc(sizeof(int));
    int *t1 = malloc(sizeof(int));
    *t = i;
    *t1 = i;
    ListPushFront(g_list, t);
    ListPushBack(g_list, t1);
  }

  mu_assert(10 == ListSize(g_list), "size non-expected value");

  PrintList("==== test_add ====");
}

MU_TEST(test_delete) {
  mu_assert_int_eq(5, *((int *)g_list->head->data));
  mu_assert_int_eq(5, *((int *)g_list->tail->data));

  ListPopFront(g_list);
  ListPopBack(g_list);

  mu_assert_int_eq(4, *((int *)g_list->head->data));
  mu_assert_int_eq(4, *((int *)g_list->tail->data));

  mu_assert(8 == ListSize(g_list), "size non-expected value");

  PrintList("==== test_delete ====");
}

MU_TEST(test_insert) {
  int *t1 = malloc(sizeof(int));
  int *t2 = malloc(sizeof(int));
  *t1 = 111;
  *t2 = 222;
  ListInsert(g_list, 2, false, t1);
  ListInsert(g_list, 7, false, t2);

  int *r1 = NULL, *r2 = NULL;
  ListGetElem(g_list, 2, (void **) &r1);
  ListGetElem(g_list, 7, (void **) &r2);

  mu_assert_int_eq(111, *r1);
  mu_assert_int_eq(222, *r2);

  PrintList("==== test_insert ====");
}

MU_TEST(test_empty) {
  mu_assert(0 == ListSize(g_list), "it is not empty list");
}

MU_TEST(test_update) {
  int *t = malloc(sizeof(int));
  *t = 333;
  ListUpdate(g_list, 2, t);

  int *r1 = NULL;
  ListGetElem(g_list, 2, (void **) &r1);

  PRINT_INT(*r1);

  mu_assert_int_eq(333, *r1);

  PrintList("==== test_update ====");
}

MU_TEST(test_clear) {
  ClearLinkedList(g_list);
  mu_assert(0 == ListSize(g_list), "list clear failed: unemptied completion");
}

MU_TEST_SUITE(test_suite) {
  MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
  MU_RUN_TEST(test_create);
  MU_RUN_TEST(test_add);
  MU_RUN_TEST(test_delete);
  MU_RUN_TEST(test_insert);
  MU_RUN_TEST(test_update);
  MU_RUN_TEST(test_clear);
  MU_RUN_TEST(test_empty);
}

int main(void) {
  test_global_setup();
  MU_RUN_SUITE(test_suite);
  test_global_teardown();
  MU_REPORT();
  return 0;
}

