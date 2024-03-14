//
// Created by jm on 2024/3/14.
//

#include <stdio.h>
#include <stdlib.h>

#include "inc/common/io_utils.h"
#include "lstack/inc/linked_stack.h"

int main() {
  LinkedStack *stack = CreateLinkedStack(10);

  // 入栈
  for (int i = 0; i < 5; ++i) {
    int *t = malloc(sizeof(int));
    *t = i + 1;
    StackPush(&stack, t);
  }

  // 打印栈的大小和容量
  PRINTLNF("size: %zd", StackSize(stack));
  PRINTLNF("capacity: %zd", stack->capacity);

  // 获取栈顶元素
  int *top_value = StackPeek(stack);
  PRINT_INT(*top_value);

  // 出栈
  while (stack->size > 0) {
    void *data = StackPop(stack);
    PRINT_INT(*((int *) data));
  }

  return 0;
}
