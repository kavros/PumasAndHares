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
