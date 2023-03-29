#include "binary_trees.h"
int binary_tree_balance(const binary_tree_t *tree);

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


/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: is a pointer to the root node of the tree to measure the height
 * Return: 0, if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t leftHeight = 0;
	size_t rightHeight = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		leftHeight = 1 + binary_tree_height(tree->left);

	if (tree->right)
		rightHeight = 1 + binary_tree_height(tree->right);

	if (leftHeight > rightHeight)
		return (leftHeight);
	else
		return (rightHeight);
}
