#include <cppunit/extensions/HelperMacros.h>
#include "../../include/LandscapeParser.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

class LandscapeParserUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(LandscapeParserUnitTest);
    CPPUNIT_TEST(testOutput);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp() 
    {
      // No-op.
    }

    /* Clean up test suite - no-op. */
    void tearDown() 
    {
      // No-op.
    }

    /* Test output. */
    void testOutput() 
    {
      
      
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION(LandscapeParserUnitTest);
