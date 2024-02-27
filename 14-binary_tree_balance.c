#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: The balance factor of the tree, or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
        if (tree)
                return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

        return (0);
}
/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0, hright = 0;

	if (tree)
	{
		h_left = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		hright = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((h_left > hright) ? h_left : hright);
	}
	return (0);
}
