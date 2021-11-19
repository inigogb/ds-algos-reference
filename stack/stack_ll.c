#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

typedef node * stack;

bool push(stack* mystack, int value) {
    
    node *newnode = malloc(sizeof(node));

    if(newnode == NULL) return false;

    newnode->value = value;
    newnode->next = *mystack;
    *mystack = newnode;

    return true;
}

int pop(stack* mystack) {

    if(*mystack == NULL) return STACK_EMPTY;

    int result = (*mystack)->value;
    node *tmp = *mystack;
    *mystack = (*mystack)->next;
    free(tmp);
    return result;
}

int main() {

    stack st1 = NULL, st2 = NULL, st3 = NULL;

    push(&st1, 55);

    push(&st2, 13);
    push(&st2, 16);
    push(&st2, 65);
    push(&st2, 88);

    push(&st3, 42);

    int t;
    while((t = pop(&st2)) != STACK_EMPTY) {
        printf("t = %d\n", t);
    }
    return 0;
}