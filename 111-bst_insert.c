#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node or null if failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *newNode;

	if (*tree == NULL)
	{
		newNode = (bst_t *)malloc(sizeof(bst_t));
		if (newNode == NULL)
			return (NULL);

		newNode->n = value;
		newNode->left = NULL;
		newNode->right = NULL;
		*tree = newNode;
		return (newNode);
	}
	else if (value < (*tree)->n)
		return (bst_insert(&((*tree)->left), value));
	else if (value > (*tree)->n)
		return (bst_insert(&((*tree)->right), value));
	else
		return (NULL);
}
