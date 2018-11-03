#include <cppunit/extensions/HelperMacros.h>
#include "../../include/Landscape.hpp"
#include "../../include/ErrorValues.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

class LandscapeUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(LandscapeUnitTest);
    CPPUNIT_TEST(TestSetR);
    CPPUNIT_TEST(TestSetK);
    CPPUNIT_TEST(TestSetM);
    CPPUNIT_TEST(TestSetL);
    CPPUNIT_TEST(TestSetDt);
    CPPUNIT_TEST(TestSetT);
    CPPUNIT_TEST(TestSetA);
    CPPUNIT_TEST(TestSetB);
    CPPUNIT_TEST(TestSetRepetions);
    CPPUNIT_TEST(TestSetPumas);
    CPPUNIT_TEST(TestSetHares);
    CPPUNIT_TEST(TestSetIsWater);
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
     * This test verifies that if r is negative then our program it will raise an 
     * exception.
     */
    void TestSetR() 
    {
        Landscape landscape;
        try
        {
            landscape.SetR(-1);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
        /**
     * This test verifies that if k is negative then our program it will raise an 
     * exception.
     */
    void TestSetK() 
    {
        Landscape landscape;
        try
        {
            landscape.SetK(-1);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    /**
     * This test verifies that if m is negative then our program it will raise an 
     * exception.
     */
    void TestSetM() 
    {
        Landscape landscape;
        try
        {
            landscape.SetM(-12);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if l is negative then our program it will raise an 
     * exception.
     */
    void TestSetL() 
    {
        Landscape landscape;
        try
        {
            landscape.SetL(-10);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if dt is negative then our program it will raise an 
     * exception.
     */
    void TestSetDt() 
    {
        Landscape landscape;
        try
        {
            landscape.SetDt(0);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    /**
     * This test verifies that if t is negative then our program it will raise an 
     * exception.
     */    
    void TestSetT() 
    {
        Landscape landscape;
        try
        {
            landscape.SetT(0);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if a is negative then our program it will raise an 
     * exception.
     */
    void TestSetA() 
    {
        Landscape landscape;
        try
        {
            landscape.SetA(0);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if b is negative then our program it will raise an 
     * exception.
     */
    void TestSetB() 
    {
        Landscape landscape;
        try
        {
            landscape.SetB(0);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if repetitions are zero then our program it will raise an 
     * exception.
     */
    void TestSetRepetions() 
    {
        Landscape landscape;
        try
        {
            landscape.SetRepetions(0);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if (i,j) is out of range then our program it will raise an 
     * exception.
     */
    void TestSetPumas()
    {
        Landscape landscape;
        landscape.SetTotalColumns(100);
        landscape.SetTotalRows(100);
        try
        {
            landscape.SetPumas(103,100,5);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
            CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if  (i,j) is out of range  then our program it will raise an 
     * exception.
     */
    void TestSetHares()
    {
        Landscape landscape;
        landscape.SetTotalColumns(150);
        landscape.SetTotalRows(100);
        try
        {
            landscape.SetHares(-10,100,5);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
            CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if  (i,j) is out of range  then our program it will raise an 
     * exception.
     */
    void TestSetIsWater()
    {
        Landscape landscape;
        landscape.SetTotalColumns(150);
        landscape.SetTotalRows(100);
        try
        {
            landscape.SetIsWater(10,1000,true);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
            CPPUNIT_ASSERT(1==1);
        }
        
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION(LandscapeUnitTest);
