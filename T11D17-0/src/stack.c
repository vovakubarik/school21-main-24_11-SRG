// Copyright 2021 gsherley
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack *init() {
    stack* temp = NULL;
    return temp;
}

void printStack(stack *head) {
    printf("stack > ");
    stack *p = head;
    while (p) {
        printf("%d", p->data);
        if (p->next != NULL) printf(" ");
        p = p->next;
    }
}

void push(stack **head, int val) {
    stack *tmp = (stack*)malloc(sizeof(stack));
    tmp->data = val;
    if (*head == NULL) {
        *head = tmp;
    } else {
        tmp->next = *head;
        *head = tmp;
    }
}

void pop(stack **head) {
    stack *del = (*head)->next;
    free(*head);
    *head = del;
}
void destroy(stack **head) {
    while (*head != NULL) {
        stack* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
