#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a BST.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL .
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *cur_r, *ne_w;

	if (tree != NULL)
	{
		cur_r = *tree;

		if (cur_r == NULL)
		{
			ne_w = binary_tree_node(cur_r, value);
			if (ne_w == NULL)
				return (NULL);
			return (*tree = ne_w);
		}

		if (value < cur_r->n) /* insert in left subtree */
		{
			if (cur_r->left != NULL)
				return (bst_insert(&cur_r->left, value));

			ne_w = binary_tree_node(cur_r, value);
			if (ne_w == NULL)
				return (NULL);
			return (cur_r->left = ne_w);
		}
		if (value > cur_r->n) /* insert in right subtree */
		{
			if (cur_r->right != NULL)
				return (bst_insert(&cur_r->right, value));

			ne_w = binary_tree_node(cur_r, value);
			if (ne_w == NULL)
				return (NULL);
			return (cur_r->right = ne_w);
		}
	}
	return (NULL);
}
