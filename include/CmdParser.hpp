#ifndef CMDPARSER_HPP
#define CMDPARSER_HPP
#include <string>

class CmdParser {
public:
    CmdParser(int argc, char** argv);
    CmdParser();
    void SetInputFilePath(std::string inputFile);
    void SetConfigFilePath(std::string configFilePath);
    void SetOutputFilePrefix(std::string outputFilePrefix);
    
    std::string GetInputFilePath();
    std::string GetConfigFilePath();
    std::string GetOutputFilePrefix();
    
    
    virtual ~CmdParser();
private:
    std::string landscapeFilePath;
    std::string outputFilePrefix;
    std::string configFilePath;
};

#endif /* CMDPARSER_HPP */

