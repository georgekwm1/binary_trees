#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *current = tree;
	size_t count = 0;

	if (current == NULL)
		return (0);
	if (current->parent == NULL)
		return (0);

	while (current->parent != NULL)
	{
		current = current->parent;
		count++;
	}
	return (count);


}
