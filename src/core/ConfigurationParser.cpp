/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConfigurationParser.cpp
 * Author: alex
 * 
 * Created on October 9, 2018, 6:42 PM
 */

#include "../../include/ConfigurationParser.hpp"
#include "../../include/Json.hpp"
#include <string>
#include <fstream>
#include <iostream>
ConfigurationParser::ConfigurationParser(std::string configurationFileName) {
    std::ifstream i(configurationFileName);
    json j;
    i >> j;
    this->r = j["r"].get<double>();
    this->a = j["a"].get<double>();
    this->b = j["b"].get<double>();
    this->m = j["m"].get<double>();
    this->k = j["k"].get<double>();
    this->l = j["l"].get<double>();
    this->d = j["d"].get<double>();
    this->n = j["n"].get<int>();
}

ConfigurationParser::ConfigurationParser(const ConfigurationParser& orig) {
}

ConfigurationParser::~ConfigurationParser() {
}