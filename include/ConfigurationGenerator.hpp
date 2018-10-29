/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConfigurationGenerator.hpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:43 PM
 */

#ifndef CONFIGURATIONGENERATOR_HPP
#define CONFIGURATIONGENERATOR_HPP

#include "Json.hpp"
#include <string>
#include <map>

using json = nlohmann::json;

class ConfigurationGenerator {
public:

    ConfigurationGenerator(int ac, char *av[]);
    bool WriteToFile(std::string fileName);

    std::string fileName;
    json options;
    std::string jsonString;
private:
    

};

#endif /* CONFIGURATIONGENERATOR_HPP */

