#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - function that goes through
 *  a binary tree using post-order traversal
 * @tree:  pointer to the root node of the binary tree
 * @func:  function to apply on each visited node
 * Return: Nothing
 * 
*/

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
