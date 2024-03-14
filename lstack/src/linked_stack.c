//
// Created by jm on 2024/3/14.
//

#include "lstack/inc/linked_stack.h"

#include <string.h>

static void *GetTopElem(LinkedStack *stack) {
  size_t n_size = sizeof(stack->container->head->data);
  void *data = malloc(n_size);
  memcpy(data, stack->container->head->data, n_size);
  return data;
}

LinkedStack *CreateLinkedStack(size_t capacity) {
  LinkedStack *stack = malloc(sizeof(LinkedStack));
  stack->capacity = capacity > 0 ? capacity : DEFAULT_CAPACITY;
  stack->size = 0;
  stack->container = CreateLinkedList();
  return stack;
}

void DestroyLinkedStack(LinkedStack *stack) {
  if (!stack) return;
  if (stack->container) DestroyLinkedList(stack->container);
  free(stack);
}

size_t StackSize(LinkedStack *stack) {
  if (!stack) return 0;
  if (!stack->container) return 0;
  return stack->capacity;
}

void StackPush(LinkedStack **stack, void *data) {
  if (!stack) return;
  if (!(*stack)) *stack = CreateLinkedStack(DEFAULT_CAPACITY);
  if ((*stack)->size == (*stack)->capacity) return;
  ListPushFront((*stack)->container, data);
  (*stack)->size++;
}

void *StackPop(LinkedStack *stack) {
  if (!stack) return NULL;
  if (!stack->container) return NULL;
  if (stack->size == 0) return NULL;
  void *data = GetTopElem(stack);
  ListPopFront(stack->container);
  stack->size--;
  return data;
}

void *StackPeek(LinkedStack *stack) {
  if (!stack) return NULL;
  if (!stack->container) return NULL;
  if (stack->size == 0) return NULL;
  return GetTopElem(stack);
}
