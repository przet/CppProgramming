#include <cppunit/extensions/HelperMacros.h>
#include "Game.hpp"

class TestBowlingGame : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestBowlingGame);
    CPPUNIT_TEST(Test1);
    CPPUNIT_TEST_SUITE_END();

    public:
        void Test1()
        {
            Game game;
            CPPUNIT_ASSERT_EQUAL(0,game.getScore());
        }
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestBowlingGame);
