#pragma once

#include "BreadthFirstIterator.h"
#include "DepthFirstIterator.h"

struct TreeNode {
	int data;
	
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data) : data(data), left(nullptr), right(nullptr) {}
};

class TreeCollection
{
public:
	// constructors
	TreeCollection() : root(nullptr) {}
	TreeCollection(TreeNode* rootNode) : root(rootNode) {}

	void insert(int val);

	DepthFirstIterator* getDepthIterator();
	BreadthFirstIterator* getBreadthIterator();

private:
	void insert(int val, TreeNode*& node);

	TreeNode* root;
};

