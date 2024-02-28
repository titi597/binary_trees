#include "binary_trees.h"

bst_t *inorder_successor(bst_t *root);
bst_t *bst_delete(bst_t *root, bst_t *node);
bst_t *bst_remove_recursive(bst_t *root, bst_t *node, int value);
bst_t *bst_remove(bst_t *root, int value);

/**
 * inorder_successor - Returning the value of a binary tree.
 * @root: A pointer to the root node.
 *
 * Return: The root.
 */
bst_t *inorder_successor(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_delete - Deleting a node from a binary tree.
 * @root: A pointer to ana array node of the BST.
 * @node: A pointer to an array of node delete from the BST.
 *
 * Return: A pointer to the new node after deleting.
 */
bst_t *bst_delete(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *successor = NULL;

	if (node->left == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->right;
		else if (parent != NULL)
			parent->right = node->right;
		if (node->right != NULL)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}
	if (node->right == NULL)
	{
		if (parent != NULL && parent->left == node)
			parent->left = node->left;
		else if (parent != NULL)
			parent->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}
	successor = inorder_successor(node->right);
	node->n = successor->n;

	return (bst_delete(root, successor));
}

/**
 * bst_remove_recursive - Removing a node from a binary tree recursively.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to an array of node in the BST.
 * @value: an array of value to remove from the BST.
 *
 * Return: A pointer to the node after deleting.
 */
bst_t *bst_remove_recursively(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_delete(root, node));
		if (node->n > value)
			return (bst_remove_recursively(root, node->left, value));
		return (bst_remove_recursively(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removing a node from a binary tree.
 * @root: A pointer to the an array of the BST to remove a node from.
 * @value: an array ofThe value to remove in the BST.
 *
 * Return: A pointer to the new node after deleting.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursively(root, root, value));
}
