#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_LENGTH 5
#define EMPTY (-1)
#define STACK_EMPTY INT_MIN

typedef struct {
    int values[STACK_LENGTH];
    int top;
} stack;

bool push(stack *mystack, int value) {
    
    if(mystack->top >= STACK_LENGTH - 1)
        return false;

    mystack->top++;
    mystack->values[mystack->top] = value;
    return true;
}

int pop(stack *mystack) {
    
    if(mystack->top == EMPTY)
        return STACK_EMPTY;

    int result = mystack->values[mystack->top];
    mystack->top--;
    return result;
}

int main() {
    stack st1, st2, st3;
    st1.top = EMPTY;
    st2.top = EMPTY;
    st3.top = EMPTY;

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