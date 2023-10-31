#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:  a pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0 else return height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	while (tree->left || tree->right)
	{
		height++;
		if (tree->left != NULL)
		{
			tree = tree->left;
		}
		else
		{
			tree = tree->right;
		}
	}
	return (height);
}
