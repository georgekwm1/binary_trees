#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling:  Get the sibling of a given node in a binary tree.
 * @node:   The node to get the sibling from.
 * Returns:  A pointer to the sibling of the given node, or NULL if there is no
*/

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return NULL;
	if (node->parent->left == node)
		return node->parent->right;
	return node->parent->left;
}
