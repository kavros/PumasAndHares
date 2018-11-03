#include <cppunit/extensions/HelperMacros.h>
#include "../../include/CmdParser.hpp"
#include <cstddef>
#include <iostream>
using namespace std;

class CmdParserUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(CmdParserUnitTest);
    CPPUNIT_TEST(TestSetInputFilePath);
    CPPUNIT_TEST(TestSetConfigFilePath);
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
     * This test verifies that if the file path for the landscape is empty then
     * our program it will raise an exception. 
     */
    void TestSetInputFilePath()
    {
        CmdParser parser;
        try
        {
            parser.SetInputFilePath("");
            CPPUNIT_ASSERT(0==1);
        }
         catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    /**
     * This test verifies that if the file path for the configuration is not type .json
     * then our program it will raise an exception. 
     */
    void TestSetConfigFilePath()
    {
        CmdParser parser;
        try
        {
            parser.SetConfigFilePath("test.jsoin");
            CPPUNIT_ASSERT(0==1);
        }
         catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }

};
CPPUNIT_TEST_SUITE_REGISTRATION(CmdParserUnitTest);
