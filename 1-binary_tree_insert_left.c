#include "binary_trees.h"
/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 * @parent: A pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 *
 * Return: A pointer to the new node, or NULL on failure
 *          or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL || parent == NULL)
	{
		return (NULL);
	}
	else
	{
		new_node->n = value;
		new_node->left = parent->left;
		new_node->right = NULL;
		new_node->parent = parent;

		if (parent->left != NULL)
		{
			parent->left->parent = new_node;
		}

		parent->left = new_node;
	}

	return (new_node);
}
