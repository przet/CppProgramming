#include <string>
#include <stack>
#include <cmath>
#include <cstring> // used in tests somewhere

bool isDisarium(int number)
{
    int q = number / 10;
    if (!q)
      return true; 
  
    std::stack<int> stack;
    int origNumber = number;
  
    int r = 0;
    while (q)
    {
        r = number % 10;
        stack.push(r);
        stack.push(q);
        number = q;
        q = number/10;
    }
    
    int count = 1;
    int sum = 0;
  
    while (!stack.empty())
    {
        sum += pow(stack.top(), count++);
        stack.pop();
    }
  
    return sum == origNumber;
}
std::string disariumNumber (int number )
{
    return isDisarium(number) ? "Disarium !!" : "Not !!";
}