#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (first == NULL || second == NULL)
		return (NULL);
	while (first != NULL)
	{
		if (first->n == second->n)
			return ((binary_tree_t *)first);
		first = first->parent;
	}
	return (NULL);
}
