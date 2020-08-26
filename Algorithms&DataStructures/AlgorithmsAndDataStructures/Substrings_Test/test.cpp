#include "pch.h"
#include <Substrings.h>
#include <string>

TEST(TestSubstringExists, SpecialCase_target_gt_parent)
{
    std::string parent = "a";
    std::string target = "ab";
    ASSERT_FALSE(substringExists(parent, target));
}
TEST(TestSubstringExists, target_e_parent_diff)
{
    std::string parent = "a";
    std::string target = "b";
    ASSERT_FALSE(substringExists(parent, target));
}
TEST(TestSubstringExists, target_e_parent_same)
{
    std::string parent = "a";
    std::string target = "a";
    ASSERT_TRUE(substringExists(parent, target));
}
TEST(TestSubstringExists, test1)
{
    std::string parent = "abcd";
    std::string target = "abc";
    ASSERT_TRUE(substringExists(parent, target));
}
TEST(TestSubstringExists, test2)
{
    std::string parent = "abcd";
    std::string target = "aabc";
    ASSERT_FALSE(substringExists(parent, target));
}
TEST(TestSubstringExists, test3)
{
    std::string parent = "abcd";
    std::string target = "aaa";
    ASSERT_FALSE(substringExists(parent, target));
}
TEST(TestSubstringExists, test4)
{
    std::string parent = "abcd";
    std::string target = "abcd";
    ASSERT_TRUE(substringExists(parent, target));
}
TEST(TestSubstringExists, test5)
{
    std::string parent = "aabcdx";
    std::string target = "azzabd";
    ASSERT_FALSE(substringExists(parent, target));
}
TEST(TestSubstringExists, test6)
{
    std::string parent = "aabcdx";
    std::string target = "abda";
    ASSERT_TRUE(substringExists(parent, target));
}
TEST(TestSubstringExists, test7)
{
    std::string parent = "aabcdx";
    std::string target = "bada";
    ASSERT_TRUE(substringExists(parent, target));
}
TEST(TestSubstringExists, test8)
{
    std::string parent = "abcdefghijklmnopqrstuvwxyz";
    std::string target = "q";
    ASSERT_TRUE(substringExists(parent, target));
}