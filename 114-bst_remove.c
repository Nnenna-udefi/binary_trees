#include "binary_trees.h"
bst_t *bst_find_min(bst_t *node);
bst_t *bst_remove_node(bst_t *node, int value);

/**
 * bst_remove -  function that removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after
 * removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_node(root, value));
}

/**
 * bst_find_min - find minimum value of bst
 * @node: node to be checked
 * Return: node
 */
bst_t *bst_find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove_node - function to remove the node
 * @node: node to be emoved
 * @value: value to remove in the tree
 * Return: node
 */
bst_t *bst_remove_node(bst_t *node, int value)
{
	bst_t *temp;

	if (node == NULL)
		return (node);
	else if (value < node->n)
		node->left = bst_remove_node(node->left, value);
	else if (value > node->n)
		node->right = bst_remove_node(node->right, value);
	else
	{
		if (node->left == NULL)
		{
			temp = node->right;
			free(node);
			return (temp);
		}
		else if (node->right == NULL)
		{
			temp = node->left;
			free(node);
			return (temp);
		}
		else
		{
			temp = bst_find_min(node->right);
			node->n = temp->n;
			node->right = bst_remove_node(node->right, temp->n);
		}
	}
	return (node);
}
