#include "binary_trees.h"

/**
 * binary_tree_leaves - function that counts the leaf in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: 0 if tree is null
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
