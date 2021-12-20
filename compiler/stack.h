#ifndef HARRY_POINTER_STACK_H
#define HARRY_POINTER_STACK_H

typedef struct StackNode {
    void *value;
    struct StackNode *next;
} StackNode;

typedef struct {
    int size;
    StackNode *head;
} Stack;

Stack createStack();
void pushToStack(Stack *stack, void *value);
void *stackFront(Stack *stack);
void *popFromStack(Stack *stack);

#endif
