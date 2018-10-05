/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ParameterParser.hpp
 * Author: user
 *
 * Created on October 5, 2018, 11:20 PM
 */

#ifndef PARAMETERPARSER_HPP
#define PARAMETERPARSER_HPP
#include <string>
#include <map>

class ParameterParser {
public:

  /*
   Keys:
     r: Birth rate of Hares
     a: Prediation rate at which Pumas eat Hares.
     b: Birth rate of pumas per one hare eaten.
     m: Puma mortality rate
     k: Diffusion rates for Hares
     l: Diffusion rates for Pumas
     t_step: Time step size.

  */
    
    std::map<std::string, double> Dict;

    
    
    ParameterParser(std::string config_file);
    ParameterParser(const ParameterParser& orig);
    virtual ~ParameterParser();
private:
    bool IsDouble(std::string value);
    std::string commentsuffix = "#";

};

#endif /* PARAMETERPARSER_HPP */

