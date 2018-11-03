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


    /**
     * This test verifies that if a is negative then our program it will raise an 
     * exception.
     */
    void TestSetA()
    {
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetA(value);
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
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetB(value);
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
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetDt(value);
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
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetK(value);
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
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetL(value);
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
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetM(value);
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
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetN(value);
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
        ConfigurationGenerator configGenerator(18,av);
        double value = -1.1;
        try
        {
            configGenerator.SetR(value);
            CPPUNIT_ASSERT(1==0);
        }
        catch(exception& e)
        {
            CPPUNIT_ASSERT(1==1);

        }
    }
    
    
};
CPPUNIT_TEST_SUITE_REGISTRATION(ConfigurationGeneratorUnitTest);
