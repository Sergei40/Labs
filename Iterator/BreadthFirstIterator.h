#pragma once

#include "Iterator.h"
#include <queue>

struct TreeNode;

class BreadthFirstIterator : public Iterator
{
public:
	BreadthFirstIterator(TreeNode* node) : currentElement(node) {
		queue.push(node);
	};
	TreeNode* getNext();
	bool hasMore() const;

private:
	TreeNode* currentElement;
	std::queue<TreeNode*> queue;
};

