/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParameterParser.hpp
 * Author: user
 *
 * Created on October 5, 2018, 4:18 PM
 */

#ifndef PARAMETERPARSER_HPP
#define PARAMETERPARSER_HPP
#include <string>
#include <map>

class ParameterParser {
public:
    std::map<std::string, double> Options;
    ParameterParser();
    ParameterParser(const ParameterParser& orig);
    virtual ~ParameterParser();
private:

};

#endif /* PARAMETERPARSER_HPP */

