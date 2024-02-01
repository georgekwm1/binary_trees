#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t left_nodes = 0, right_nodes = 0;

    if (tree == NULL)
        return (0);

    if (tree->left != NULL || tree->right != NULL)
    {
        left_nodes = binary_tree_nodes(tree->left);
        right_nodes = binary_tree_nodes(tree->right);
        return (left_nodes + right_nodes + 1);
    }

    return (0);
}
