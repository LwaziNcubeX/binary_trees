#include "binary_trees.h"
/**
  * binary_tree_is_complete - checks if a binary tree is complete
  * @tree: a pointer to the root node of the tree to check
  *
  * Return: 1 if the binary tree is complete, 0 otherwise
  *         If tree is NULL, return 0
  **/
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size, index = 0;

	if (tree == NULL)
		return (0);

	size = binary_tree_size(tree);

	return (binary_tree_check_complete(tree, index, size));
}

/**
  * binary_tree_check_complete - checks if a binary tree is
  *                                 complete recursively
  * @tree: a pointer to the root node of the tree to check
  * @index: the index of the current node in the complete binary tree
  * @size: the size of the complete binary tree
  *
  * Return: 1 if the binary tree is complete, 0 otherwise
  **/
int binary_tree_check_complete(const binary_tree_t *tree, int index, int size)
{
	if (tree == NULL)
		return (1);


	if (index >= size)
		return (0);


	return (binary_tree_check_complete(tree->left, 2 * index + 1, size) &&
		binary_tree_check_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: The depth of the node, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
