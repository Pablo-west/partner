#include "binary_trees.h"
/**
 * bst_insert - insert nodes in order to create a BST tree
 * @tree: tree to create with type BST
 * @value: value of node to insert
 * Return: BST tree
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new;
	bst_t *temp_n;
	binary_tree_t *aux;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux = binary_tree_node((binary_tree_t *)(*tree), value);
		new = (bst_t *)aux;
		*tree = new;
	}
	else
	{
		temp_n = *tree;
		if (value < temp_n->n)
		{
			if (temp_n->left)
				new = bst_insert(&temp_n->left, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)temp_n, value);
				new = temp_n->left = (bst_t *)aux;
			}
		}
		else if (value > temp_n->n)
		{
			if (temp_n->right)
				new = bst_insert(&temp_n->right, value);
			else
			{
				aux = binary_tree_node((binary_tree_t *)temp_n, value);
				new = temp_n->right = aux;
			}
		}
		else
			return (NULL);
	}
	return (new);
}
