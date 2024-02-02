#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height -  Calculates the height of a given binary tree.
 * @tree: The root node of the binary tree.
 * Return:  The height of the binary tree.
 * 
*/

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
