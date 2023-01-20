#include "DepthFirstIterator.h"
#include "TreeCollection.h"
#include <iostream>

TreeNode* DepthFirstIterator::getNext()
{
	if (!hasMore())
	{
		std::cout << "no more elements\n";
		return nullptr;
	}
	
	// pop a node from the stack and print it
	currentElement = stack.top();
	stack.pop();

	// push the right child of the popped node into the stack
	if (currentElement->right) {
		stack.push(currentElement->right);
	}

	// push the left child of the popped node into the stack
	if (currentElement->left) {
		stack.push(currentElement->left);
	}

	// the right child must be pushed first so that the left child
	// is processed first (LIFO order)
	
	return currentElement;
}

bool DepthFirstIterator::hasMore() const
{
	return !stack.empty();
}
