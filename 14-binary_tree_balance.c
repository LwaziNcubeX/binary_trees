#include "binary_trees.h"
/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 or The balance factor of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_avail = tree && tree->left;
	int right_avail = tree && tree->right;
	int x = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (left_avail && right_avail)
	{
		x = 2;
	}
	else if (left_avail || right_avail)
	{
		x = -1;
	}
	return (x);
}
