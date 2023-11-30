#include "binary_trees.h"

/**
 * array_to_avl - turns an array to a avl tree
 * @array: array to turns to AVL tree
 * @size: size of array
 * Return: AVL tree from array
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i = 0;
	size_t k = 0;
	avl_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (i = 0; i < size; i++)
	{
		for (k = 0; k < i; k++)
		{
			if (array[k] == array[i])
				break;
		}
		if (k == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (root);
}
