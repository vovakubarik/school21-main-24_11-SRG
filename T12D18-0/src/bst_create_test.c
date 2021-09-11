// Copyright 2021 gsherley
#include <stdio.h>
#include "bst.h"

int main() {
    t_btree *root = NULL;
    root = bstree_create_node(2);
    printf("%d\n", root->item);
    freemem(root);
    root = bstree_create_node(4);
    printf("%d\n", root->item);
    freemem(root);
    return 0;
}
