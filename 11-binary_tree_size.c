#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t count = 0;
	if (tree == NULL)
		return (0);
	count = 1;
	if (tree->left != NULL)
		count += binary_tree_size(tree->left);
	if (tree->right != NULL)
		count += binary_tree_size(tree->right);
	return (count);
}
