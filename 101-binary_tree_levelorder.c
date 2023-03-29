#include "binary_trees.h"
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - function that goes through a binary tree using
 * level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 * Do nothing, if tree or func is null
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **level_order = NULL;
	size_t i, size, front = 0, back = 0;
	const binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;

	size = binary_tree_size(tree);
	level_order = malloc(sizeof(binary_tree_t *) * size);
	if (level_order == NULL)
		return;

	level_order[back++] = (binary_tree_t *)tree;

	while (front < back)
	{
		node = level_order[front++];

		func(node->n);
		if (node->left)
			level_order[back++] = (binary_tree_t *)node->left;
		if (node->right)
			level_order[back++] = (binary_tree_t *)node->right;
	}

	for (i = 0; i < size; i++)
		level_order[i] = NULL;

	free(level_order);
}

/**
 * binary_tree_size - function that measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: 0, if tree is null
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_subtree;
	size_t right_subtree;

	if (tree == NULL)
		return (0);
	left_subtree = binary_tree_size(tree->left);
	right_subtree = binary_tree_size(tree->right);

	return (1 + left_subtree + right_subtree);
}
