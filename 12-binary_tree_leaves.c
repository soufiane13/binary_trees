#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the leaves.
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leave_s = 0;

	if (tree)
	{
		leave_s += (!tree->left && !tree->right) ? 1 : 0;
		leave_s += binary_tree_leaves(tree->left);
		leave_s += binary_tree_leaves(tree->right);
	}
	return (leave_s);
}
