#include <string>
#include <cmath>
#include <cstring> // used in tests somewhere

bool isDisarium(int number)
{
    if (number < 10)
        return true;
    if (!(number % 10))
        return false;
  
    auto numStr = std::to_string(number);
    size_t pos = numStr.size();
  
    int origNumber = number;
    int sum = 0;
    int r = 0;
  
    do 
    {
        sum += pow(number % 10, pos--);
        if (sum > origNumber)
            return false;
      
    } while (number /= 10);
    
    return sum == origNumber;
}
std::string disariumNumber (int number )
{
    return isDisarium(number) ? "Disarium !!" : "Not !!";
}