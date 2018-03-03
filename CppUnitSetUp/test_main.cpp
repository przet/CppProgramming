#include "include/cppunit/extensions/TestFactoryRegistry.h"
#include "include/cppunit/ui/text/TextTestRunner.h"

int main (int argc, int **argv)
{
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
    CppUnit::TextTestRunner runner;
    runner.addTest(registry.makeTest());
    runner.run("",true);
    return 0;
}

