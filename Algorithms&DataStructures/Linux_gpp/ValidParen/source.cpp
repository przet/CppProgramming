#include "source.hpp"
#include <stdexcept>
#include <stack>

// Internal Helper Functions
bool openParen(char rParen)
{
    return rParen == '('
        || rParen == '{'
        || rParen == '[';
}

bool parenMatch(char rParenClosed, char rParenOpen)
{
    switch (rParenClosed)
    {
        case ')':
            return rParenOpen == '(';
        case ']':
            return rParenOpen == '[';
        case '}':
            return rParenOpen == '{';
        default:
            throw std::runtime_error
            ("The first arguement is not a valid paren");
    }
}

// Internal Data Structures

// OpenParenStack:
// Restricted STL stack for use with valid open
// parens only
struct OpenParenStack 
{
    void push(const char& val)
    {
        !openParen(val)? throw std::runtime_error("Can only insert open parameters")
        :charStack.push(val);
    }

    auto top() {return charStack.top();}
    auto pop() {return charStack.pop();}
    auto size() {return charStack.size();}

    private:
        std::stack<char> charStack;
};


// API function defintions
bool ValidParens::isValid(std::string& input)
{
    // QuickWins
    long vInputSize = input.size();
    if (!vInputSize)
        return true;

    if(vInputSize % 2 != 0)
        return false;

    if (!openParen(input[0])
       || openParen(input[vInputSize-1])) 
        return false;
    
    OpenParenStack vOpstack;
    vOpstack.push(input[0]);

    int j = 1;

    while (j < vInputSize)
    {
        auto vCurrParen = input[j];
        if (openParen(vCurrParen))
        {
            vOpstack.push(vCurrParen);
            j++;
        }
        else if (vOpstack.size() && parenMatch(vCurrParen, vOpstack.top()))
        {
            vOpstack.pop();
            j++;
        }
        else
            return false;
    }

    return true;
}
