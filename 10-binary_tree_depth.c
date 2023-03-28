#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 * Return: 0, if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;
	const binary_tree_t *current;

	if (tree == NULL)
		return (0);

	depth = 0;
	current = tree;

	while (current->parent != NULL)
	{
		current = current->parent;
		depth++;
	}
	return (depth);
}
