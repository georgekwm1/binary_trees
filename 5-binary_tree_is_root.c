#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
* binary_tree_is_root - Function to  checks if a given node is a root 
* @node: integer that represents the value of the new node.
* Return: 0 or 1
*/

int binary_tree_is_root(const binary_tree_t *node)
{
    if (node == NULL)
    {
        return (0);
    }
        
    if (node->parent == NULL)
    {
        return (1);
    }
    return(0);
}