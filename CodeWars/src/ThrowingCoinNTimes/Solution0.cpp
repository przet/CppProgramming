#include <vector>
#include <string>
std::string coin(int n)
{
    if (n == 1)
    {
        return std::string("H,T");
      
    }
    std::vector<std::string> vec;
    for (int i = 0; i < n; ++i)
    {
        std::vector<std::string> newVec;
        if (std::size(vec) == 0)
        {
            newVec.push_back("H");
            newVec.push_back("T");
        }
        else
        {
            for (std::string elem : vec)
            {
                elem.insert(0,1,'H');
                newVec.push_back(elem);
            }
            for (std::string elem : vec)
            {
                elem.insert(0,1,'T');
                newVec.push_back(elem);
            }
        }
        vec = newVec;
    }
    std::string result;
    int count = 0;
    for (auto elem : vec)
    {
        if (count++ != std::size(vec) - 1)
          result += elem + ",";
        else
          result += elem;
        
        
    }
    return result;
}
