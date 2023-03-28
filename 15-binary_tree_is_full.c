#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is null
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_tree = 0;
	int right_tree = 0;

	if (tree == NULL)
		return (0);

	left_tree = binary_tree_is_full(tree->left);
	right_tree = binary_tree_is_full(tree->right);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);

	if ((tree->left != NULL) && (tree->right != NULL))
		return (left_tree && right_tree);

	return (0);
}
