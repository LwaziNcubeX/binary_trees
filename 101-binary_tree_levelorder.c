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
 * binary_tree_levelorder - Goes through a binary tree using
 *				level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **array = calloc(binary_tree_height(tree) + 1,
			sizeof(*array));
	int front = 0, rear = 0;

	if (tree == NULL || func == NULL)
	{
		return;
	}

	if (array == NULL)
	{
		return;
	}

	array[rear] = (binary_tree_t *)tree;

	while (array[front] != NULL)
	{
		binary_tree_t *node = array[front];

		func(node->n);

		if (node->left != NULL)
		{
			rear++;
			array[rear] = node->left;
		}

		if (node->right != NULL)
		{
			rear++;
			array[rear] = node->right;
		}

		front++;
	}

	free(array);
}
