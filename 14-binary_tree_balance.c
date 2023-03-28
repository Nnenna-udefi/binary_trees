#include "binary_trees.h"

/**
 * binary_tree_balance - function that measures the balance factor of a binary
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: 0, if tree is null
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_Height = 0;
	size_t right_Height = 0;

	if (tree == NULL)
		return (0);

	left_Height = binary_tree_height(tree->left);
	right_Height = binary_tree_height(tree->right);

	return (left_Height - right_Height);
}
