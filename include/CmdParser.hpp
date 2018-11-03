/**
 *  A class that parse command line input using Args library
 */

#ifndef CMDPARSER_HPP
#define CMDPARSER_HPP
#include <string>

class CmdParser {
public:
    /**
     * Reads command line input and updates member variables using setters.
     * @param argc
     * @param argv
     */
    CmdParser(int argc, char** argv);
    /**
     * Second constructor usable from the unit tests.
     */
    CmdParser();
    /**
     * Sets input file name.
     * @throws invalid_argument exception if input file name is empty.
     * @param inputFile
     */
    void SetInputFilePath(std::string inputFile);
    /**
     * Sets configuration  file name.
     * @throws invalid_argument exception if file name is empty or in case that does not contain json word.
     * @param configFilePath
     */
    void SetConfigFilePath(std::string configFilePath);
    /**
     * Sets output file prefix.
     * @param outputFilePrefix
     */
    void SetOutputFilePrefix(std::string outputFilePrefix);
    
    /**
     * Returns landscape .dat file.
     * @return a string with input file path.
     */
    std::string GetInputFilePath();
    /**
     * Returns json configuration file.
     * @return a string with configuration file path.
     */
    std::string GetConfigFilePath();
    /**
     * Returns prefix for image file.
     * @return  a string with output prefix file path.
     */
    std::string GetOutputFilePrefix();
    
    
    virtual ~CmdParser();
private:
    std::string landscapeFilePath;
    std::string outputFilePrefix;
    std::string configFilePath;
};

#endif /* CMDPARSER_HPP */

