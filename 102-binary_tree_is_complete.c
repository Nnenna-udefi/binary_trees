#include "binary_trees.h"
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 0, if tree is null
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size, i;
	const binary_tree_t **queue = NULL;

	if (tree == NULL)
		return (0);

	/* queue holds all the nodes in the tree */
	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (queue == NULL)
		return (0);

	/* add the root node of the tree into the queue */
	queue[0] = tree;

	for (i = 0; (size = 1, i < size); ++i)
	{
		if (queue[i]->left)
		{
			/* flag indicates there is a missing node in tree */
			if (size == binary_tree_size(tree))
			{
				free(queue);
				return (0);
			}
			queue[size++] = queue[i]->left;
		}

		if (queue[i]->right)
		{
			if (size == binary_tree_size(tree))
			{
				free(queue);
				return (0);
			}
			queue[size++] = queue[i]->right;
		}
	}

	free(queue);
	return (1);
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
