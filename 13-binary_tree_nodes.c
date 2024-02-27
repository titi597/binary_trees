#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in binary tree
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: The number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t ahab = 0;

	if (tree)
	{
		ahab += (tree->left || tree->right) ? 1 : 0;
		ahab += binary_tree_nodes(tree->left);
		ahab += binary_tree_nodes(tree->right);
	}
	return (ahab);
}
