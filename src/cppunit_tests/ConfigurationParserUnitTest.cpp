#include <cppunit/extensions/HelperMacros.h>
#include "ConfigurationParser.hpp"
#include <cstddef>
#include <iostream>
#include <map>

using namespace std;

class ConfigurationParserUnitTest:public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ConfigurationParserUnitTest);
    CPPUNIT_TEST(TestReadConfigurationFromFile);
    CPPUNIT_TEST(TestSetA);
    CPPUNIT_TEST(TestSetB);
    CPPUNIT_TEST(TestSetDt);
    CPPUNIT_TEST(TestSetK);
    CPPUNIT_TEST(TestSetL);
    CPPUNIT_TEST(TestSetM);
    CPPUNIT_TEST(TestSetN);
    CPPUNIT_TEST(TestSetR);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp()
    {
    }

    /* Clean up test suite - no-op. */
    void tearDown()
    {
    }
    /**
     * This test verifies that if the configuration file does not exist then our
     * program it will raise an exception.
     */
    void TestReadConfigurationFromFile()
    {
      try
      {
        ConfigurationParser configParserTestRead("../../data/configs/inexistentfile.json");
        CPPUNIT_ASSERT(1==0);
      }
      catch(exception& e)
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
      ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetA(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
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
        ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetB(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
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
        ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetDt(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
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
        ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetK(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
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
        ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetL(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
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
        ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetM(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);
        }
    }

    /**
     * This test verifies that if n is negative then our program it will raise an 
     * exception.
     */
    void TestSetN()
    {
        ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetN(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if r is negative then our program it will raise an 
     * exception.
     */
    void TestSetR()
    {
        ConfigurationParser configParserTestRead;
        try
        {
            configParserTestRead.SetR(-10);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);
        }
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION(ConfigurationParserUnitTest);
