#include "binary_trees.h"

/**
 * binary_trees_ancestor - function that checks an ancestor
 * @first: First node
 * @second: Second node
 * Return: the node of the ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	binary_tree_t *l;
	binary_tree_t *q;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}
	if (first == second)
	{
		return ((binary_tree_t *)first);
	}

	l = first->parent;
	q = second->parent;
	if (l == NULL || first == q || (!l->parent && q))
	{
		return (binary_trees_ancestor(first, q));
	}
	else if (q == NULL || l == second || (!q->parent && l))
	{
		return (binary_trees_ancestor(l, second));
	}
	return (binary_trees_ancestor(l, q));
}
