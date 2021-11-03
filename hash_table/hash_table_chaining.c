#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

/*
This is an External Chaining approach to collisions
The index is changed to a linked list and every collision
is added to the list.
*/

typedef struct person {
    char name[MAX_NAME];
    int age;
    struct person *next;
    // may add more fields
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name) {
    int length = strnlen(name, MAX_NAME);
    unsigned int hash_value = 0;

    for(int i = 0;i < length;i++) {
        hash_value += name[i];
        hash_value = ( hash_value * name[i] ) % TABLE_SIZE;
    }
    return hash_value;
}

void init_hash_table() {
    for(int i = 0 ;i < TABLE_SIZE;i++) {
        hash_table[i] = NULL;
    }
}

void print_table() {

    printf("START\n");
    for(int i = 0;i < TABLE_SIZE;i++) {
        if(hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            printf("\t%i\t", i);
            person *tmp = hash_table[i];
            while(tmp != NULL) {
                printf("%s - ", tmp->name);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("END\n");
}

bool hash_table_insert(person *p) {
    if(p == NULL)
        return false;
    int index = hash(p->name);
    p->next = hash_table[index];
    hash_table[index] = p;
    return true;
}

person *hash_table_lookup(char *name) {
    int index = hash(name);

    person *tmp = hash_table[index];
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        tmp = tmp->next;
    }
    return tmp;
}

person *hash_table_delete(char *name) {
    int index = hash(name);

    person *tmp = hash_table[index];
    person *prev = NULL;
    while(tmp != NULL && strncmp(tmp->name, name, MAX_NAME) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }
    if(tmp == NULL) return NULL;
    if(prev == NULL) {
        // deleting the head
        hash_table[index] = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    return tmp;
}

int main() {

    init_hash_table();
    print_table();

    person inigo = { .name = "Inigo", .age = 256};
    person jessica = { .name = "Jessica", .age = 18};
    person morty = { .name = "Morty", .age = 20};
    person rick = { .name = "Rick", .age = 50};
    person inigo2 = { .name = "Jane", .age = 256};
    person jessica2 = { .name = "Maren", .age = 18};
    person morty2 = { .name = "Kate", .age = 20};
    person rick2 = { .name = "Robert", .age = 50};
    person inigo3 = { .name = "Jacob", .age = 256};
    person jessica3 = { .name = "Sarah", .age = 18};
    person morty3 = { .name = "Eliza", .age = 20};
    person rick3 = { .name = "Edna", .age = 50};

    hash_table_insert(&morty3);
    hash_table_insert(&rick3);
    hash_table_insert(&morty);
    hash_table_insert(&rick);
    hash_table_insert(&inigo2);
    hash_table_insert(&jessica2);
    hash_table_insert(&morty2);
    hash_table_insert(&rick2);
    hash_table_insert(&inigo3);
    hash_table_insert(&jessica3);

    print_table();

    person *tmp = hash_table_lookup("BLAHBLAH");

    if(tmp == NULL) {
        printf("NOT FOUND!\n");
    } else {
        printf("FOUND: %s\n", tmp->name);
    }

    tmp = hash_table_lookup("Rick");

    if(tmp == NULL) {
        printf("NOT FOUND!\n");
    } else {
        printf("FOUND: %s\n", tmp->name);
    }

    //hash_table_delete("Rick");

    print_table();

    return 0;
}