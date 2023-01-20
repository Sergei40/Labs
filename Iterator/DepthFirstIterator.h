#pragma once

#include "Iterator.h"
#include <stack>

struct TreeNode;

class DepthFirstIterator : public Iterator
{
public:
	DepthFirstIterator(TreeNode* node) : currentElement(node) {
		stack.push(node);
	};
	TreeNode* getNext();
	bool hasMore() const;

private:
	TreeNode* currentElement;
	std::stack<TreeNode*> stack;
};

