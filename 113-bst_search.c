#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search for in the tree
 * Return: Pointer to the node containing the value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);
	while (tree != NULL)
	{
		if (value == tree->n) /* Found the value */
			return ((bst_t *)tree);
		else if (value < tree->n) /* Search in the left subtree */
			tree = tree->left;
		else /* Search in the right subtree */
			tree = tree->right;
	}
	/* Value not found */
	return (NULL);
}
