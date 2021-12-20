#include "stack.h"

#include <stdlib.h>

Stack createStack() {
    return (Stack) {
        .size = 0,
        .head = NULL,
    };
}

void pushToStack(Stack *stack, void *value) {
    stack->size += 1;
    StackNode *next = stack->head;
    StackNode *node = malloc(sizeof(StackNode));
    node->next = next;
    stack->head = node;
}

void *stackFront(Stack *stack) {
    StackNode *node = stack->head;
    if(node == NULL) {
        return NULL;
    }

    return node->value;
}

void *popFromStack(Stack *stack) {
    StackNode *node = stack->head;

    if(node == NULL) {
        return NULL;
    }

    void *value = node->value;
    stack->head = node->next;
    free(node);
    stack->size -= 1;

    return value;
}
