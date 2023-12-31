#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: a pointer to the node to find the sibling
 *
 * Return: NULL or sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent->left == node)
	{
		return (node->parent->right);
	}

	return (node->parent->left);
}


/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: a pointer to the node to find the uncle
 *
 * Return: NULL or uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	return (binary_tree_sibling(node->parent));
}
