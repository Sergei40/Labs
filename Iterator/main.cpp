#include <iostream>
#include "TreeCollection.h"

int main()
{
    TreeCollection myTree{};
	myTree.insert(50);
	myTree.insert(25);
	myTree.insert(75);
    myTree.insert(12);
	myTree.insert(37);
	myTree.insert(62);
	myTree.insert(85);
	//       50
	//      /  \
	//     /    \
	//	  /		 \
    //   25      75
	//  /  \    /  \
	// 12  37  62  85
    Iterator* iterator; 

    std::cout << "\nBreath-first iterator:\n";
    iterator = myTree.getBreadthIterator();
    while (iterator->hasMore())
    {
        std::cout << iterator->getNext()->data << " ";
    }
    
    
	std::cout << "\n\nDepth-first iterator:\n";
    iterator = myTree.getDepthIterator();
	while (iterator->hasMore())
	{
		std::cout << iterator->getNext()->data << " ";
	}
}