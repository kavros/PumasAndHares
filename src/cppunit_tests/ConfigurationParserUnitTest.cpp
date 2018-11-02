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
      ConfigurationParser configParser("./data/configs/config2.json");
      double value = -1.1;
      CPPUNIT_ASSERT(configParser.SetA(value) == -1);
    }


    void TestSetB()
    {
      ConfigurationParser configParser("./data/configs/config.json");
      double value = -1.1;
      CPPUNIT_ASSERT(configParser.SetB(value) == -1);
    }

    void TestSetDt()
    {
      ConfigurationParser configParser("./data/configs/config.json");
      double value = -1.1;
      CPPUNIT_ASSERT(configParser.SetDt(value) == -1);
    }

    void TestSetK()
    {
      ConfigurationParser configParser("./data/configs/config.json");
      double value = -1.1;
      CPPUNIT_ASSERT(configParser.SetK(value) == -1);
    }

    void TestSetL()
    {
      ConfigurationParser configParser("./data/configs/config.json");
      double value = -1.1;
      CPPUNIT_ASSERT(configParser.SetL(value) == -1);
    }

    void TestSetM()
    {
      ConfigurationParser configParser("./data/configs/config.json");
      double value = -1.1;
      CPPUNIT_ASSERT(configParser.SetM(value) == -1);
    }

    void TestSetN()
    {
      ConfigurationParser configParser("./data/configs/config.json");
      int value = -1;
      CPPUNIT_ASSERT(configParser.SetN(value) == -1);
    }

    void TestSetR()
    {
      ConfigurationParser configParser("./data/configs/config.json");
      double value = -1.1;
      CPPUNIT_ASSERT(configParser.SetR(value) == -1);
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION(ConfigurationParserUnitTest);
