#include "BinTree.h"
#include <iostream>

using namespace std;

BTreeNode::~BTreeNode()
{
	value = NULL;
	left = nullptr;
	right = nullptr;
}

BTreeNode * BTreeNode::rotateRight(BTreeNode * node)
{
	BTreeNode* S = node->left;
	BTreeNode* B = node->right;

	S->right = node;
	node->left = B;
	return S;
}

BTreeNode * BTreeNode::rotateLeft(BTreeNode * node)
{
	BTreeNode* S = node->left;
	BTreeNode* B = node->right;

	S->left = node;
	node->right = B;
	return S;
}

BTreeNode * BTreeNode::rotateRightLeft(BTreeNode * node)
{
	BTreeNode* S = node->right;
	node->right = rotateRight(S);
	return rotateLeft(node);
}

BTreeNode * BTreeNode::rotateLeftRight(BTreeNode * node)
{
	BTreeNode* S = node->left;
	node->left = rotateRight(S);
	return rotateRight(node);
}



void BST::insert(double x, BTreeNode * node)
{
}

void BST::inorder(BTreeNode * node)
{
	if (node == nullptr)
		return;
	inorder(node->left);

	cout << node->value << ' ';

	inorder(node->right);
}

void BST::preorder(BTreeNode * node)
{
	if (node == nullptr)
		return;

	cout << node->value << ' ';

	preorder(node->left);
	preorder(node->right);
}

void BST::postorder(BTreeNode * node)
{
	if (node == nullptr)
		return;

	postorder(node->left);
	postorder(node->right);

	cout << node->value << ' ';
}

int BST::height(BTreeNode * node)
{
	if (node == nullptr)
		return 0;
	else
	{
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
		return 0;
	}
}

