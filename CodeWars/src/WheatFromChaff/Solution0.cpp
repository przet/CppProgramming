#include <vector>
#include <stack>
#include <assert.h>

using namespace std ; 

vector <long long int> wheatFromChaff (vector <long long int> values)
{
    // In one pass, find number of negatives in values, and also add thier indicies to a stack
    // Since we are traversing from index 0 to end, the topmost element of stack will be the largest, 
    // and we need that.
    long long numNeg = 0;
    std::stack<long long int> negIndicies;
    long long numValues = std::size(values);
    for (int i = 0; i < numValues; ++i) 
    {
        if (values[i] < 0)
        {
            ++numNeg;
            negIndicies.push(i);
        }
    }
    assert(numNeg <= numValues);
    assert(numNeg == negIndicies.size());
  
    // Now go through values to find the first positive
    // when we find one, pop the negIndex stack and swap the value at that index, with
    // the current value.
    // Increment the count (we go until we are greater than numberOfNegValues), and go to next Values element
    // we don't need any bounds check as we are going to numberOfNegValues which will always be <= size of Values
  
    // TODO feels like we can optimise this (as we are returning to values, even though we have already been there above...)
    
    for (int i = 0; i < numNeg; ++i)
    {
        if (values[i] > 0)
        {
            long long temp = values[i];
            values[i] = values[negIndicies.top()];
            values[negIndicies.top()] = temp;
            negIndicies.pop();
        }
    }
  
    return values;
  
    
  
  
  

  
}
