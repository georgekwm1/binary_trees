#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_height-  Calculates the height of a given binary tree.
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
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t left_height;
	size_t right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height == right_height)
	{
		return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
	}

	return (0);
}
