#include "TreeCollection.h"
#include <iostream>
#include <set>
void TreeCollection::insert(int val)
{
	this->insert(val, this->root);
}

void TreeCollection::insert(int val, TreeNode*& node)
{
	if (node == nullptr) {
		// Case: node is a nullptr
		// Make a new TreeNode for it to point to
		node = new TreeNode(val);
	}
	else {
		if (val < node->data) {
			// Case: val is < node's data
			this->insert(val, node->left);
		}
		else if (val > node->data) {
			// Case: val is > node's data
			this->insert(val, node->right);
		}
		else {
			// Case: val is equal to node's data
			std::cout << "Warning: Value already exists, so nothing will be done." << std::endl;
		}
	}
}

DepthFirstIterator* TreeCollection::getDepthIterator()
{
	return new DepthFirstIterator(root);
}

BreadthFirstIterator* TreeCollection::getBreadthIterator()
{
	return new BreadthFirstIterator(root);
}
