#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes:  Number of nodes in a complete binary tree of given height h.
 * @tree: The root node of the binary tree.
 * Returns:  The number of nodes in the binary tree.
*/

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
