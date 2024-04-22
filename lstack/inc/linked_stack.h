//
// Created by jm on 2024/3/14.
//

#ifndef DATA_STRUCTURE_LSTACK_SRC_LINKED_STACK_H_
#define DATA_STRUCTURE_LSTACK_SRC_LINKED_STACK_H_

#include "llist/inc/linked_list.h"

#include <stdlib.h>

#define DEFAULT_CAPACITY 20
#define DEFAULT_ELEM_SIZE 8

typedef struct LinkedStack {
  LinkedList *container;
  size_t capacity;
  size_t size;
  size_t n_size;
} LinkedStack;

LinkedStack *CreateLinkedStack(size_t capacity, size_t n_size);

void DestroyLinkedStack(LinkedStack *stack);

size_t StackSize(LinkedStack *stack);

void StackPush(LinkedStack **stack, void *data);

void *StackPop(LinkedStack *stack);

void *StackPeek(LinkedStack *stack);

#endif //DATA_STRUCTURE_LSTACK_SRC_LINKED_STACK_H_
