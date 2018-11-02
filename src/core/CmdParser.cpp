#include "CmdParser.hpp"
#include <exception>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include "../../include/Args.hpp"
using namespace std;

CmdParser::CmdParser()
{
    
}

CmdParser::CmdParser(int argc, char** argv) 
{

    if(argc <= 1)
    {
        throw std::invalid_argument( "No arguments passed, use -h for help.");
    }

    args::ArgumentParser parser("Command Parser","A program to simulate Puma and Hare populations across a grid.");
    args::HelpFlag help(parser, "help", "Display this help prompt.", {'h', "help"});
    args::ValueFlag<string> configFile(parser, "filename", "JSON-format configuration file for the simulation.",{'c', "config"});
    args::ValueFlag<string> inputFile(parser,"filename","Landscape input file to perform the simulation on.",{'i',"input"});
    args::ValueFlag<string> outputPrefix(parser,"prefix","Prefix for each generated output file.",{'p',"prefix"});

    try
    {
        parser.ParseCLI(argc,argv);
        SetConfigFilePath(configFile.Get());
        SetInputFilePath(inputFile.Get());
        SetOutputFilePrefix(outputPrefix.Get());


    }
    catch (args::Help)
    {
      cout << parser;
      exit(-1);
    }
    catch (args::ParseError e)
    {
      cerr << e.what() << endl;
      exit(-1);
    }
    catch (args::ValidationError e)
    {
      cerr << e.what() << endl;
      exit(-1);
    }
}

void CmdParser::SetInputFilePath(std::string inputFile)
{
    if(inputFile.empty())
    {
        throw std::invalid_argument("Input File name cannot be empty");
    }
    this->landscapeFilePath = inputFile;
}

void CmdParser::SetConfigFilePath(std::string configFilePath)
{
    if(configFilePath.empty() )
    {
        throw std::invalid_argument("Configuration file name cannot be empty.");
    }
    
    if( configFilePath.find(".json") ==string::npos)
    {
        throw std::invalid_argument("Configuration file must be json.");
    }
    this->configFilePath = configFilePath;
}

void CmdParser::SetOutputFilePrefix(std::string outputFilePrefix)
{
    this->outputFilePrefix = outputFilePrefix;
}

std::string CmdParser::GetInputFilePath()
{
    return landscapeFilePath;
}

std::string CmdParser::GetConfigFilePath()
{
    return configFilePath;
}

std::string CmdParser::GetOutputFilePrefix()
{
    return outputFilePrefix;
}


CmdParser::~CmdParser() 
{
    
}

