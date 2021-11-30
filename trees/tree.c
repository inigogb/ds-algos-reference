#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

treenode *createnode(int value) {
    treenode* result = malloc(sizeof(treenode));

    if(result != NULL) {
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printtabs(int numtabs) {
    for(int i = 0;i < numtabs;i++) {
        printf("\t");
    }
}

void printtree_rec(treenode *root, int level) {
    if(root == NULL) {
        printtabs(level);
        printf("---<empty>---\n");
        return ;
    }
    printtabs(level);
    printf("value = %d\n", root->value);
    printtabs(level);
    printf("left\n");
    printtree_rec(root->left, level+1);
    printtabs(level);
    printf("right\n");
    
    printtree_rec(root->right, level+1);

    printtabs(level);
    printf("DONE\n");
}

void printtree(treenode* root) {
    printtree_rec(root, 0);
}

int main() {

    treenode *n1 = createnode(40);
    treenode *n2 = createnode(32);
    treenode *n3 = createnode(11);
    treenode *n4 = createnode(9);
    treenode *n5 = createnode(78);
    treenode *n6 = createnode(45);
    treenode *n7 = createnode(29);
    treenode *n8 = createnode(1);
    treenode *n9 = createnode(7);

    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;
    n4->left = n6;
    n4->right = n7;
    n2->left = n8;
    n2->right = n9;

    printtree(n1);

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    free(n8);
    free(n9);

    return 0;
}