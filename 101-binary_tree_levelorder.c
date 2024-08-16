#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
void free_queue(levelorder_queue_t *head);
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop(levelorder_queue_t **head);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_node - Creates a new levelorder_queue_t node.
 * @node: The binary tree node for the new node to contain.
 *
 * Return: If an error occurs, NULL.
 *         Otherwise, a pointer to the new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *new;

	new = malloc(sizeof(levelorder_queue_t));
	if (new == NULL)
		return (NULL);

	new->node = node;
	new->next = NULL;

	return (new);
}

/**
 * free_queue - Frees the levelorder_queue_t queue.
 * @head: A pointer to the head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tm_p;

	while (head != NULL)
	{
		tm_p = head->next;
		free(head);
		head = tm_p;
	}
}

/**
 * pint_push - Runs a function on a given binary tree node and
 *             pushes its children into a levelorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @head: A double pointer to the head of the queue.
 * @tail: A double pointer to the tail of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void pint_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *ne_w;

	func(node->n);
	if (node->left != NULL)
	{
		ne_w = create_node(node->left);
		if (ne_w == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = ne_w;
		*tail = ne_w;
	}
	if (node->right != NULL)
	{
		ne_w = create_node(node->right);
		if (ne_w == NULL)
		{
			free_queue(head);
			exit(1);
		}
		(*tail)->next = ne_w;
		*tail = ne_w;
	}
}

/**
 * pop - Pops the head of a levelorder_queue_t queue.
 * @head: A double pointer.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tm_p;

	tm_p = (*head)->next;
	free(*head);
	*head = tm_p;
}

/**
 * binary_tree_levelorder - Traverses a BT using level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *hea_d, *tai_l;

	if (tree == NULL || func == NULL)
		return;

	hea_d = tai_l = create_node((binary_tree_t *)tree);
	if (hea_d == NULL)
		return;

	while (hea_d != NULL)
	{
		pint_push(hea_d->node, hea_d, &tai_l, func);
		pop(&hea_d);
	}
}
