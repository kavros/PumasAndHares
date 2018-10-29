#include <cppunit/extensions/HelperMacros.h>
#include "../../include/OutputGenerator.hpp"
#include <cstddef>
#include <iostream>
#include "../../include/ErrorValues.hpp"
using namespace std;
/**
 * Test class for OutputGenerator
 */
class OutputGeneratorUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(OutputGeneratorUnitTest);
    CPPUNIT_TEST(TestSaveAverages);
    CPPUNIT_TEST(TestCreatePPMFile);
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

    void TestSaveAverages() 
    {
        OutputGenerator output;
        int totalAvgs = 10;
        CPPUNIT_ASSERT (output.SaveAverages(NULL,NULL,totalAvgs)==FAILED);
        double a[2] = {1.2,1.3};
        double b[2] = {1.2,1.3};
        totalAvgs =-10;
        CPPUNIT_ASSERT (output.SaveAverages(a,b,totalAvgs)==FAILED);
    }
    
    void TestCreatePPMFile()
    {
        OutputGenerator output;
        Landscape landscape;
        landscape.SetGrid(NULL);
        CPPUNIT_ASSERT(output.CreatePPMFile(landscape) == FAILED);
    }

};

CPPUNIT_TEST_SUITE_REGISTRATION(OutputGeneratorUnitTest);

