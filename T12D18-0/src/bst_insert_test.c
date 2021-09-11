// Copyright 2021 gsherley
#include <stdio.h>
#include "bst.h"

int main() {
    t_btree *root = NULL;
    root = bstree_create_node(2);
    printf("2 == %d\n", root->item);
    bstree_insert(&root, 47, Cmp);
    printf("47 == %d\n", root->right->item);
    bstree_insert(&root, 1, Cmp);
    printf("1 == %d\n", root->left->item);
    freemem(root);
    return 0;
}
