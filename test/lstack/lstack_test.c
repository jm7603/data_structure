//
// Created by jm on 2024/3/14.
//

#include <stdio.h>
#include <stdlib.h>

#define PRINT_METADATA // io_utils.h

#include "inc/common/io_utils.h"
#include "lstack/inc/linked_stack.h"
#include "inc/minunit/minunit.h"

static LinkedStack *g_stack;

void test_setup(void) {
  PRINTLNF("test_setup");
  g_stack = CreateLinkedStack(0, 4);
  // 入栈
  for (int i = 0; i < 5; ++i) {
    int *t = malloc(sizeof(int));
    *t = i + 1;
    StackPush(&g_stack, t);
  }
}

void test_teardown(void) {
  PRINTLNF("test_teardown");
  DestroyLinkedStack(g_stack);
}

MU_TEST(test_init) {
  mu_check(g_stack);
  mu_assert(5 == StackSize(g_stack), "初始化入栈有误");
  mu_assert(4 == g_stack->n_size, "初始化元素大小有误");
  mu_assert(DEFAULT_CAPACITY == g_stack->capacity, "初始化容量有误");
}

MU_TEST(test_push) {
  int *t = malloc(sizeof(int));
  *t = 66;
  StackPush(&g_stack, t);
  mu_assert(6 == StackSize(g_stack), "入栈大小有误");
  mu_assert_int_eq(66, *((int *) StackPeek(g_stack)));
}

MU_TEST(test_pop) {
  int *removed = StackPop(g_stack);
  mu_assert_int_eq(5, *removed);
  mu_assert(4 == StackSize(g_stack), "出栈大小有误");
  mu_assert_int_eq(4, *((int *) StackPeek(g_stack)));
}

MU_TEST_SUITE(test_suite_stack) {
  MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
  MU_RUN_TEST(test_init);
  MU_RUN_TEST(test_push);
  MU_RUN_TEST(test_pop);
}

int main() {
  MU_RUN_SUITE(test_suite_stack);
  MU_REPORT();

  return 0;
}
