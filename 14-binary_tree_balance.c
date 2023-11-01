#include "binary_trees.h"
/**
 * max - Finds the maximum of two integers
 *
 * @a: First integer
 * @b: Second integer
 *
 * Return: The maximum value between @a and @b
 */
int max(int a, int b)
{
	return ((a > b) ? a : b);
}
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:  a pointer to the root node of the tree
 *
 * Return: if tree is NULL, return 0 else return height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right, height;

	if (tree == NULL)
	{
		return (0);
	}

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	height = max(left, right) + 1;

	return (height);
}



/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 *
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the binary tree.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height, x, y;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	x = left_height - right_height >= 2;
	y = left_height - right_height <= -2;

	return ((x || y) ? left_height - right_height : left_height - right_height);
}
