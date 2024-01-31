#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = malloc(sizeof(*new_node));
    if (!new_node)
    {
        fprintf(stderr, "Failed to allocate memory for a new node.\n");
        return NULL;
    }
    new_node->n  = value;
    new_node->left   = NULL;
    new_node->right  = NULL;
    new_node->parent = parent;
    return (new_node);
}