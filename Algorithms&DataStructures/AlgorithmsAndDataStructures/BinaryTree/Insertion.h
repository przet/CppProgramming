#pragma once
#include <vector>
#include <iostream>

// Binary tree node
// TODO data is a bad variable name - gave me lots of trouble to figure out
// what it meant after coming back to this after a couple of weeks away from it.
struct TreeNode {
    int data;
    TreeNode* left, *right;

    TreeNode(int idx) {
        data = idx;
        left = nullptr;
        right = nullptr;

    }
};

namespace PreOrderInsertion
{
    
	//** Static to avoid linker error (multiple definitions) TODO: 
	// This did not work as I wanted - nodeStore was not populated in the 
	// calling program (the driver program)... 
	// multiple copies of nodeStore were made for each obj file, I wonder
	// how this affects things...

    //static std::vector<TreeNode> nodeStore;

    //void Insert(int data, std::vector<int>& inputArr, int numClosetElem, int tgtIdx);
    void Insert(std::vector<TreeNode>& nodeStore, std::vector<int>& inputArr, int numClosetElem, int tgtIdx);
}
