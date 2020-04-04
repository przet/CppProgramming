#include "source.hpp"
#include <gtest/gtest.h>
#include <vector>

// Tests exceptions (i.e if we have non chars in string)

TEST(QuickWins, EmptyInput)
{
    ValidParens vP;
    std::string input1 = "";
    ASSERT_TRUE(vP.isValid(input1));
}
TEST(QuickWins, OddLengthString)
{
    ValidParens vP;
    std::string input1 = "(";
    std::string input2 = "[";
    std::string input3 = "{";
    std::string input4 = "{)[]}";
    std::string input5 = "{))";
    ASSERT_TRUE(!vP.isValid(input1));
    ASSERT_TRUE(!vP.isValid(input1));
    ASSERT_TRUE(!vP.isValid(input3));
    ASSERT_TRUE(!vP.isValid(input4));
    ASSERT_TRUE(!vP.isValid(input5));
}

TEST(QuickWins, ClosedFirstOpenLastParen )
{
    ValidParens vP;
    std::string input1 = ")]";
    std::string input2 = "[(";
    ASSERT_FALSE(vP.isValid(input1));
    ASSERT_FALSE(vP.isValid(input1));
}

TEST(ValidParens, ValidInput)
{
    ValidParens vP;
    std::vector<std::string> inputVec
    {
        "()[]{}",
        "(({[]})())",
        "(({[]}))",
        "(({}{}{(())}))",
        "[[]{}((()))]",
        "{{[][[()]]}}",
        "{(())(()[])}",
        "(([]){})"
    };
    for (std::string& input : inputVec)
        ASSERT_TRUE(vP.isValid(input));

}

TEST(ValidParens, InvalidInput)
{
    ValidParens vP;
    std::vector<std::string> inputVec
    {
        "((})",
        "(}()",
        "({({}(})",
        "{{{)}}}",
    };
    for (std::string& input : inputVec)
        ASSERT_FALSE(vP.isValid(input));

}

int main (int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
