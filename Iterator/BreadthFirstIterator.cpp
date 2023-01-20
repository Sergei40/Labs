#include "BreadthFirstIterator.h"
#include "TreeCollection.h"
#include <iostream>

TreeNode* BreadthFirstIterator::getNext()
{
	if (!hasMore())
	{
		std::cout << "no more elements\n";
		return nullptr;
	} 
	// Print front of queue and remove it from queue
	currentElement = queue.front();
	//cout << node->data << " ";
	queue.pop();

	/* Enqueue left child */
	if (currentElement->left)
		queue.push(currentElement->left);

	/*Enqueue right child */
	if (currentElement->right)
		queue.push(currentElement->right);

	return currentElement;
}

bool BreadthFirstIterator::hasMore() const
{
	return !queue.empty();
}
