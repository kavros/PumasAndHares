#include <cppunit/extensions/HelperMacros.h>
#include "../../include/OutputGenerator.hpp"
#include <cstddef>
#include <iostream>
using namespace std;
/**
 * Test class for OutputGenerator
 */
class OutputGeneratorUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(OutputGeneratorUnitTest);
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
      double avgPumas[3]= {1,2,3};
      double avgHares[3]= {1,2,3};
      
      OutputGenerator output;
      CPPUNIT_ASSERT_EQUAL(output.SaveAverages(avgPumas,avgHares,-10),-1);
      
      
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(OutputGeneratorUnitTest);

