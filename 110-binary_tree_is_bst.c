#include "binary_trees.h"
#include <limits.h>
int is_bst_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - function that checks if a binary tree is a valid
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 * if tree is null, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * is_bst_helper - helper function for binary_tree_is_bst
 * @tree: pointer to the root node of the tree to check
 * @min: the minimum value a node in the subtree rooted at tree can have
 * @max: the maximum value a node in the subtree rooted at tree can have
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst_helper(tree->left, min, tree->n - 1) &&
			is_bst_helper(tree->right, tree->n + 1, max));
}
