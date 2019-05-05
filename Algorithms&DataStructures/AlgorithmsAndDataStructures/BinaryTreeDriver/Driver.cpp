#ifndef __INSERTION__H
#define __INSERTION__H
#include <Insertion.h>

#endif // !__INSERTION__H

#include <cassert>
#include <iostream>

int main()
{
    // Typedefs
    typedef std::vector<int> vec;

    

    // Test 1
    vec vec1{1,2,3,4,5,6,7};
    std::vector<TreeNode> nodeStore;

    PreOrderInsertion::Insert(nodeStore, vec1, 5, 3);

    for (auto elem : /*PreOrderInsertion::*/nodeStore)
        std::cout << vec1[elem.data] << std::endl;



    

    return 0;
}



