#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *tm_p;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	tm_p = pivot->left;
	pivot->left = tree;
	tree->right = tm_p;
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
