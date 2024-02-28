#include "binary_trees.h"
#include "limits.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);
int binary_tree_is_avl(const binary_tree_t *tree);
/**
 * height - Computes the height of a binary tree
 * @tree: A pointer to the root node of the tree
 *
 * Return: Height of the tree, -1 if NULL
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}
/**
 * is_avl_helper - helping the binary tree.
 * @tree: pointer to an array tree
 * @lo: an array lo
 * @hi: an array hi
 * Return: 1 when success
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t avgt, rgvgt, dumddiff;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
			return (0);
		avgt = height(tree->left);
		rgvgt = height(tree->right);
		dumddiff = avgt > rgvgt ? avgt - rgvgt : rgvgt - avgt;
		if (dumddiff > 1)
			return (0);
		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}
	return (1);
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: A pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}
