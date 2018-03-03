#include <cppunit/extensions/HelperMacros.h>
#include "header.hpp"
#include <iostream>

class TestSource : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestSource);
    CPPUNIT_TEST(isMemberSet);
    CPPUNIT_TEST_SUITE_END();
    
    public:
        void isMemberSet()
        {
            MyClass myclass;
            
            CPPUNIT_ASSERT_EQUAL(2,myclass.get_a());
            std::cout << myclass.get_a() << std::endl;
        }

};

CPPUNIT_TEST_SUITE_REGISTRATION(TestSource);
        
