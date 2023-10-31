#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:  a pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0 else return height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	while (tree)
	{
		if (tree->left)
		{
			height++;
			tree = tree->left;
		}
		else if (tree->right)
		{
			height++;
			tree = tree->right;
		}
		else
		{
			return (height);
		}
	}
	return (height);
}
