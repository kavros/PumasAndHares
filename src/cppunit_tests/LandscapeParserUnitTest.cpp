#include <cppunit/extensions/HelperMacros.h>
#include "../../include/LandscapeParser.hpp"
#include "../../include/ErrorValues.hpp"
#include "../../include/Landscape.hpp"
#include <cstddef>
#include <iostream>
using namespace std;
/**
 * A class that test functions of LandscapeParser class.
 */
class LandscapeParserUnitTest:public CppUnit::TestFixture 
{
    CPPUNIT_TEST_SUITE(LandscapeParserUnitTest);
    CPPUNIT_TEST(TestReadLandscapeFromFile);
    CPPUNIT_TEST(TestSetLandscape);
    CPPUNIT_TEST(TestSetFilePath);
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
     * This test verifies that if output file not exist
     * then our program it will raise an exception.
     */
    void TestReadLandscapeFromFile()
    {
        Landscape landscape;
        LandscapeParser landscapeParser(&landscape,"blabla.txt");
        try
        {
            landscapeParser.ReadLandscapeFromFile();
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
     /**
     * This test verifies that if landscape is null
     * then our program it will raise an exception.
     */
    void TestSetLandscape()
    {
        Landscape landscape;
        try
        {
            string filePath="aaa.txt";
            LandscapeParser landscapeParser(NULL,filePath);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             CPPUNIT_ASSERT(1==1);
        }
    }
    
     /**
     * This test verifies that if file path is empty 
     * then our program it will raise an exception.
     */
    void TestSetFilePath()
    {
         Landscape landscape;
        try
        {
            string filePath="";
            LandscapeParser landscapeParser(&landscape,filePath);
            CPPUNIT_ASSERT(0==1);
        }
        catch(std::exception& e )
        {
             //empty file path throws exception
             CPPUNIT_ASSERT(1==1);
        }
    }
    
    
    
};
CPPUNIT_TEST_SUITE_REGISTRATION(LandscapeParserUnitTest);
