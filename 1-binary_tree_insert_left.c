#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *current;
    binary_tree_t *new_node = malloc(sizeof(binary_tree_t));
    new_node->n  = value;
    new_node->right = NULL;
    new_node->left = NULL;
    if (parent == NULL)
    {
        parent = new_node;
        parent->parent = NULL;
    }
    current = parent;
    while (current->left != NULL)
    {
        current = current->left;
    }
    new_node->left = current->left;
    current->left = new_node;

    return (new_node);
}