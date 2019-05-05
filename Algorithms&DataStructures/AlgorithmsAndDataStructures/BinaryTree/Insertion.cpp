#ifndef __INSERTION__H
#define __INSERTION__H
#include "Insertion.h"
#endif
//#include "Insertion.h"

namespace PreOrderInsertion
{
    void /*PreOrderInsertion::*/Insert(/*int data,*/
        std::vector<TreeNode>& nodeStore, std::vector<int>& inputArr, int numClosetElem, int tgtIdx)
    {

        const int k = numClosetElem;
        const int tgt_idx = tgtIdx;

        // Create a root node 
        TreeNode root(tgt_idx);

        // We start at one since we include the target index
        int count = 1;

        // Naming indicies of the input array, and operations
        int firstIdx = 0;
        int lastIdx = inputArr.size() - 1;
        int leftMove, rightMove;

        nodeStore.push_back(root);

        while (count < k) {
            
            if (count == 1)
            {
                leftMove = tgt_idx - count;
                rightMove = tgt_idx + count;
            }

            // Compensate for overshoot
            // TODO: find a way to not need this compensation. 
            else
            {
                leftMove = tgt_idx - count + 1;
                rightMove = tgt_idx + count -1;
            }

            if (leftMove >= firstIdx)
            {
                root.left = &TreeNode(leftMove);
                ++count;
            }

            if (rightMove <= lastIdx)
            {
                root.right = &TreeNode(rightMove);
                ++count;
            }
            nodeStore.push_back(root.left->data);
            nodeStore.push_back(root.right->data);
            root = TreeNode(root.left->data);
        }
    }

}

