#include "binary_trees.h"

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 * @tree: Pointer to the root node of the tree to count the leaves
 *
 * Return: The number of leaves in the tree, or 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t amababi = 0;

	if (tree)
	{
		amababi += (!tree->left && !tree->right) ? 1 : 0;
		amababi += binary_tree_leaves(tree->left);
		amababi += binary_tree_leaves(tree->right);
	}
	return (amababi);
}
