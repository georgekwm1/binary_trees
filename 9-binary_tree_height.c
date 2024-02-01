#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree)
{
    const binary_tree_t *current = tree;
    size_t count = 0;
    if (tree == NULL)
        return (0);
    while (current->left != NULL || current->right != NULL)
    {
        if (current->left != NULL)
        {
            current = current->left;
            count++;
        }
        if (current->right != NULL)
        {
            current = current->right;
            count++;
        }
    }
    return (count);

    
}