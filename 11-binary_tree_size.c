#include "binary_trees.h"

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
