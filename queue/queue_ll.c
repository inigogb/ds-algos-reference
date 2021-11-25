#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define QUEUE_LENGTH 5
#define EMPTY (-1)
#define QUEUE_EMPTY INT_MIN

typedef struct node {
    int value;
    struct node *next;
} node;

typedef struct {
    node *head;
    node *tail;
} queue;

void init_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool enqueue(queue* q, int value) {

    // create a new node
    node *newnode = malloc(sizeof(node));
    newnode->value = value;
    newnode->next = NULL;

    if(newnode == NULL) {
        return false;
    }

    // if there's a tail, connect the tail to the newnode 
    if(q->tail != NULL) {
        q->tail->next = newnode;
    }
    q->tail = newnode;
    if(q->head == NULL) {
        q->head = newnode;
    }
    return true;
}

int dequeue(queue* q) {

    // check if queue is empty
    if(q->head == NULL) {
        return QUEUE_EMPTY;
    }

    // save the head of the queue
    node *tmp = q->head;
    //save result to return
    int result = tmp->value;
    q->head = q->head->next;

    if(q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
    return result;
}

int main() {

    queue q1, q2, q3;

    init_queue(&q1);
    init_queue(&q2);
    init_queue(&q3);

    enqueue(&q1, 66);
    enqueue(&q1, 12);
    enqueue(&q1, 90);
    enqueue(&q2, 62);
    enqueue(&q2, 26);
    enqueue(&q2, 54);
    enqueue(&q3, 96);
    enqueue(&q3, 10);
    enqueue(&q3, 8);

    int t;
    while((t = dequeue(&q2)) != QUEUE_EMPTY) {
        printf("t = %d\n", t);
    }
    return 0;
}