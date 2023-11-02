#include "binary_trees.h"
/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: The depth of the node, or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->parent)
	{
		depth = binary_tree_depth(tree->parent) + 1;
	}

	return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to first node
 * @second: Pointer to second node
 *
 * Return: Pointer to the lowest common ancestor node, or NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	if (!first || !second)
	{
		return (NULL);
	}

	if (first == second || first == second->parent ||
	    second == first->parent)
	{
		return ((binary_tree_t *)first);
	}

	if (binary_tree_depth(first) > binary_tree_depth(second))
	{
		return (binary_trees_ancestor(first->parent, second));
	}
	else if (binary_tree_depth(first) < binary_tree_depth(second))
	{
		return (binary_trees_ancestor(first, second->parent));
	}

	return (binary_trees_ancestor(first->parent, second->parent));
}
