#include <cppunit/extensions/HelperMacros.h>

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
    void testOutput() {
      int result = 1;
      CPPUNIT_ASSERT_EQUAL(1, result);
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(OutputGeneratorUnitTest);

