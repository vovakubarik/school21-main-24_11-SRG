#ifndef SRC_STACK_H_
#define SRC_STACK_H_

typedef struct my_stack {
    int data;
    struct my_stack *next;
} stack;

stack *init();
void printStack(stack *head);
void push(stack **head, int val);
void pop(stack **head);
void destroy(stack **head);

#endif  // SRC_STACK_H_
