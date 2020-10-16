#pragma once
#include <iostream>

using namespace std;

class BTreeNode
{
public:
	BTreeNode(double x)
	{
		value = x;
		left = nullptr;
		right = nullptr;
	}
	~BTreeNode();
private:
	double value;
	BTreeNode *left, *right;
	BTreeNode * rotateRight(BTreeNode * node);
	BTreeNode * rotateLeft(BTreeNode * node);
	BTreeNode * rotateRightLeft(BTreeNode * node);
	BTreeNode * rotateLeftRight(BTreeNode * node);
	BTreeNode * balance(BTreeNode * node);
	
	friend class BST;
};

class BST
{
private:
	void insert(double x, BTreeNode * node); // NEEDS balance to be integrated
	void inorder(BTreeNode * node);
	void preorder(BTreeNode * node);
	void postorder(BTreeNode * node);
	int height(BTreeNode * node);
	BTreeNode * tree;

public:
	void insert(double x) { insert(x, tree); }
	void inorder() { inorder(tree); }
	void preorder() { preorder(tree); }
	void postorder() { postorder(tree); }

};