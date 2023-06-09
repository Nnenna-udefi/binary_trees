#include "binary_trees.h"
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is null
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_tree = 0;
	int right_tree = 0;

	if (tree == NULL)
		return (0);

	left_tree = binary_tree_height(tree->left);
	right_tree = binary_tree_height(tree->right);

	if (left_tree == right_tree)
	{
		if ((tree->left == NULL) && (tree->right == NULL))
			return (1);
		else if ((tree->left != NULL) && (tree->right != NULL))
			return (binary_tree_is_perfect(tree->left)
					&& binary_tree_is_perfect(tree->right));
	}
	return (0);
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
