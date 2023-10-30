#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node
 *
 * @parent: A pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 * Return: A pointer to the new node, or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	parent = malloc(sizeof(binary_tree_t));

	if (parent != NULL)
	{
		parent->left = NULL;
		parent->right = NULL;
		parent->n = value;
	}
	return (parent);
}
