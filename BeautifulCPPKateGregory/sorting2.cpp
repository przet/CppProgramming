#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector <int> numlist = {1,5,3,5,2,6,4};
    std::cout << "\n\n";
    std::cout <<"Original List: " << std::endl;
    std::for_each(begin(numlist),end(numlist),[](auto elem){std::cout << elem << ", "; });
    std::cout << "\n\n";

    std::cout << "\n\n";
    std::cout <<"Sorted List (<): " << std::endl;
    std::sort(begin(numlist),end(numlist),[](auto elem1, auto elem2){return elem1 < elem2;});
    std::for_each(begin(numlist),end(numlist),[](auto elem){std::cout << elem << ", "; });
    std::cout << "\n\n";
    return 0;
}
    


