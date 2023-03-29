#include "binary_trees.h"
int binary_tree_is_ancestor(const binary_tree_t *ancestor,
		const binary_tree_t *node);
/**
 * binary_trees_ancestor - function that finds the lowest common ancestor
 * of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *ancestor;

	if (first == NULL || second == NULL)
		return (NULL);
	ancestor = (binary_tree_t *) second;
	while (ancestor != NULL)
	{
		if (binary_tree_is_ancestor(ancestor, first))
			return (ancestor);
		ancestor = ancestor->parent;
	}
	return (NULL);
}

/**
 * binary_tree_is_ancestor - checks if a given node is an ancestor of
 * another node
 * @ancestor: pointer to the node to check
 * @node: pointer to the node to check against
 * Return: 1 if ancestor is an ancestor of node, 0 otherwise
 */
int binary_tree_is_ancestor(const binary_tree_t *ancestor,
		const binary_tree_t *node)
{
	while (node != NULL)
	{
		if (node == ancestor)
			return (1);
		node = node->parent;
	}
	return (0);
}
