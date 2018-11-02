#include <cppunit/extensions/HelperMacros.h>
#include "../../include/ConfigurationGenerator.hpp"
#include <cstddef>
#include <cstdlib>
#include <iostream>

char* av[18];

using namespace std;

class ConfigurationGeneratorUnitTest:public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ConfigurationGeneratorUnitTest);
    CPPUNIT_TEST(TestWriteConfigurationToFile);
    CPPUNIT_TEST(TestSetJsonString);
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
      av[0]=(char*)"./build/bin/configurationGeneratorMain";
      av[1]=(char*)"./data/configs/config8.json";
      av[2]=(char*)"-r";
      av[3]=(char*)"0.08";
      av[4]=(char*)"-a";
      av[5]=(char*)"0.04";
      av[6]=(char*)"-b";
      av[7]=(char*)"0.02";
      av[8]=(char*)"-m";
      av[9]=(char*)"0.06";
      av[10]=(char*)"-k";
      av[11]=(char*)"0.2";
      av[12]=(char*)"-l";
      av[13]=(char*)"0.2";
      av[14]=(char*)"-n";
      av[15]=(char*)"100";
      av[16]=(char*)"-d";
      av[17]=(char*)"0.9";
    }

    /* Clean up test suite - no-op. */
    void tearDown()
    {
      // No-op.
    }

    /* Test output. */
    void TestWriteConfigurationToFile()
    {
      ConfigurationGenerator configGeneratorTestWrite(18,av);
      try
      {
        configGeneratorTestWrite.WriteToFile("./data/configs/config8.json");
        CPPUNIT_ASSERT(1==1);
      }
      catch(exception& e)
      {
        cout << e.what() << endl;
        CPPUNIT_ASSERT(1==0);
      }

    }

    void TestSetJsonString()
    {
      ConfigurationGenerator configGenerator(18,av);
      std::string jsonStr = "{\"a\": 0.04,\"b\": 0.02,\"d\": 0.4,\"k\": 0.2,\"l\": 0.2,\"m\": 0.06,\"n\": 100,\"r\": 0.08}";
      CPPUNIT_ASSERT(configGenerator.SetJsonString(jsonStr) == 0);
    }

    void TestSetA()
    {
      ConfigurationGenerator configGenerator(18,av);
      double value = -1.1;
      CPPUNIT_ASSERT(configGenerator.SetA(value) == -1);
    }

    void TestSetB()
    {
      ConfigurationGenerator configGenerator(18,av);
      double value = -1.1;
      CPPUNIT_ASSERT(configGenerator.SetB(value) == -1);
 
    }

    void TestSetDt()
    {
      ConfigurationGenerator configGenerator(18,av);
      double value = -1.1;
      CPPUNIT_ASSERT(configGenerator.SetDt(value) == -1);
 
    }

    void TestSetK()
    {
      ConfigurationGenerator configGenerator(18,av);
      double value = -1.1;
      CPPUNIT_ASSERT(configGenerator.SetK(value) == -1);
 
    }
    void TestSetL()
    {
      ConfigurationGenerator configGenerator(18,av);
      double value = -1.1;
      CPPUNIT_ASSERT(configGenerator.SetL(value) == -1);
 
    }

    void TestSetM()
    {
      ConfigurationGenerator configGenerator(18,av);
      double value = -1.1;
      CPPUNIT_ASSERT(configGenerator.SetM(value) == -1);
 
    }

    void TestSetN()
    {
      ConfigurationGenerator configGenerator(18,av);
      int value = -1;
      CPPUNIT_ASSERT(configGenerator.SetN(value) == -1);
 
    }
    void TestSetR()
    {
      ConfigurationGenerator configGenerator(18,av);
      double value = -1.1;
      CPPUNIT_ASSERT(configGenerator.SetR(value) == -1);
 
    } 
};
CPPUNIT_TEST_SUITE_REGISTRATION(ConfigurationGeneratorUnitTest);
