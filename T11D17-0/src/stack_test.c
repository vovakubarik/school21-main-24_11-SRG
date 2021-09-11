// Copyright 2021 gsherley
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    stack *stk = init();
    printf("Test for push:\n");
    for (int i = 0; i <= 10; i+=2) {
        push(&stk, i);
    }
    printStack(stk);
    if (stk->next != NULL) {
        printf("\nSUCCESS");
    } else {
        printf("\nFAIL");
    }
    printf("\nTest for pop:\n");
    int t = stk->data;
    pop(&stk);
    pop(&stk);
    printStack(stk);
    if (t != stk->data) {
        printf("\nSUCCESS");
    } else {
        printf("\nFAIL");
    }
    printf("\n");

    destroy(&stk);
}
