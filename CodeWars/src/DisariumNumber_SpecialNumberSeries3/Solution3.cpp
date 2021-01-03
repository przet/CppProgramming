#include <string>
#include <cmath>
#include <cstring> // used in tests somewhere

bool isDisarium(int number)
{
    int q = number / 10;
    if (!q)
      return true; 
  
    auto numStr = std::to_string(number);
    size_t pos = numStr.size();
    int origNumber = number;
  
    int sum = 0;
    int r = 0;
    while (q)
    {
        r = number % 10;
        sum += pow(r, pos--);
        if (sum > origNumber)
            return false;
      
        number = q;
        q = number/10;
    }
    sum += pow(number, pos);
    
    return sum == origNumber;
}
std::string disariumNumber (int number )
{
    return isDisarium(number) ? "Disarium !!" : "Not !!";
}