#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tm_p;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	tm_p = pivot->right;
	pivot->right = tree;
	tree->left = tm_p;
	if (tm_p != NULL)
		tm_p->parent = tree;
	tm_p = tree->parent;
	tree->parent = pivot;
	pivot->parent = tm_p;
	if (tm_p != NULL)
	{
		if (tm_p->left == tree)
			tm_p->left = pivot;
		else
			tm_p->right = pivot;
	}

	return (pivot);
}
