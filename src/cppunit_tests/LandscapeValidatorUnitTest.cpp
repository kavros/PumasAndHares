#include <cppunit/extensions/HelperMacros.h>
#include "../../include/LandscapeValidator.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

class LandscapeValidatorUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(LandscapeValidatorUnitTest);
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
CPPUNIT_TEST_SUITE_REGISTRATION(LandscapeValidatorUnitTest);