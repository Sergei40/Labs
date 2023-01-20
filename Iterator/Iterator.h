#pragma once

struct TreeNode;

class Iterator
{
public:

	virtual TreeNode* getNext() = 0;

	virtual bool hasMore() const = 0;
};
