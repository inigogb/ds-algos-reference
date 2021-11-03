#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node * next;
    struct node * prev;
};
typedef struct node node_t;

void print_list(node_t *head) {

    node_t * temporary = head;

    while(temporary != NULL) {
        printf("%d - ", temporary->value);
        temporary = temporary->next;
    }
    printf("\n");
}

node_t *create_new_node(int value) {

    // we statically allocate new nodes in the heap
    node_t * newnode = malloc(sizeof(node_t)); 
    newnode->value = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert) {
    node_to_insert->next = *head;
    if(*head != NULL) {
        (*head)->prev = node_to_insert;
    }
    *head = node_to_insert;
    node_to_insert->prev = NULL;
    return node_to_insert;
}

node_t *find_node(node_t *head, int value) {
    
    node_t *tmp = head;
    while(tmp != NULL) {
        if(tmp->value == value) return tmp;
        tmp = tmp->next; 
    }

    return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode) {
    newnode->next = node_to_insert_after->next;
    if(newnode->next != NULL) {
        newnode->next->prev = newnode;
    }
    newnode->prev = node_to_insert_after;
    node_to_insert_after->next = newnode;
}

void remove_node(node_t **head, node_t *node_to_remove) {
    if(*head == node_to_remove) {
        *head = node_to_remove->next;
        if(*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {

        node_to_remove->prev->next = node_to_remove->next;
        if(node_to_remove->next != NULL) {
            node_to_remove->next->prev = node_to_remove->prev;
        }
    }
    node_to_remove->next = NULL;
    node_to_remove->prev = NULL;
    return;
}

int main() {

    node_t * head = NULL;
    node_t * tmp;

    for(int i = 0;i < 30;i++) {
        tmp = create_new_node(i);
        insert_at_head(&head, tmp);
    }

    tmp = find_node(head, 13);
    printf("found node with value %d\n", tmp->value);

    insert_after_node(tmp, create_new_node(75));

    print_list(head);

    remove_node(&head, tmp);
    remove_node(&head, head);

    print_list(head);

    return 0;
}