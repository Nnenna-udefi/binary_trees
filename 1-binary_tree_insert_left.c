#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to the node to insert the left-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *insertNode;
	
	if (value == '\0')
		return (NULL);
	if (parent == NULL)
		return (NULL);

	insertNode = malloc(sizeof(binary_tree_t));
	if (insertNode == NULL)
		return (NULL);

	insertNode->n = value;
	insertNode->parent = parent;
	insertNode->left = parent->left;
	insertNode->right = NULL;

	if (parent->left != NULL)
		parent->left->parent = insertNode;
	parent->left = insertNode;

	return (insertNode);
}
