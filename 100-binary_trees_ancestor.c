#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mo_m, *po_p;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mo_m = first->parent, po_p = second->parent;
	if (first == po_p || !mo_m || (!mo_m->parent && po_p))
		return (binary_trees_ancestor(first, po_p));
	else if (mo_m == second || !po_p || (!po_p->parent && mo_m))
		return (binary_trees_ancestor(mo_m, second));
	return (binary_trees_ancestor(mo_m, po_p));
}
