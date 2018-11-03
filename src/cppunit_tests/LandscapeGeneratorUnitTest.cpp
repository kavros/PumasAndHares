#include <cppunit/extensions/HelperMacros.h>
#include "../../include/LandscapeGenerator.hpp"
#include <cstddef>
#include <iostream>
using namespace std;
/**
 * A class that test functions of LandscapeGenerator class.
 */
class LandscapeGeneratorUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(LandscapeGeneratorUnitTest);
    CPPUNIT_TEST(TestSetTotalRows);
    CPPUNIT_TEST(TestSetTotalColumns);
    CPPUNIT_TEST(TestSetLandPercentage);
    CPPUNIT_TEST(TestSetOutputFileName);
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
    /**
     * This test verifies that if output file name is empty 
     * then our program it will raise an exception.
     */
    void TestSetOutputFileName()
    {
        try
        {
            LandscapeGenerator gen;
            gen.SetOutputFileName("");
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);
        }
    }
    /**
     * This test verifies that if total rows are negative then our program it will raise an 
     * exception.
     */
    void TestSetTotalRows()
    {
        try
        {
            LandscapeGenerator gen;
            gen.SetTotalRows(-1);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if total columns are negative then
     * our program it will raise an exception.
     */
    void TestSetTotalColumns()
    {
        try
        {
            LandscapeGenerator gen;
            gen.SetTotalColumns(-1);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if land percentage is higher than 1 
     * then our program it will raise an exception.
     */
    void TestSetLandPercentage()
    {
        try
        {
            LandscapeGenerator gen;
            gen.SetLandPercentage(1.001);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);
        }
        
    }


};
CPPUNIT_TEST_SUITE_REGISTRATION(LandscapeGeneratorUnitTest);
