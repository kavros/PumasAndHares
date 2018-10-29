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
