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
 * binary_tree_count - Count the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The number of nodes in the tree
 */
size_t binary_tree_count(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_count(tree->left) + binary_tree_count(tree->right));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, count;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	count = binary_tree_count(tree);

	return ((1 << height) - 1 == count);
}
