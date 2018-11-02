/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ConfigurationParser.cpp
 * Author: B049401
 *
 * Created on October 9, 2018, 6:42 PM
 */

#include "../../include/ConfigurationParser.hpp"
#include "../../include/Json.hpp"
#include <string>
#include <fstream>
#include <iostream>

ConfigurationParser::ConfigurationParser()
{
    
}

ConfigurationParser::ConfigurationParser(std::string configurationFileName)
{
    std::ifstream i(configurationFileName);
    i >> this->j;
    this->SetR(j["r"].get<double>());
    this->SetA(j["a"].get<double>());
    this->SetB(j["b"].get<double>());
    this->SetM(j["m"].get<double>());
    this->SetK(j["k"].get<double>());
    this->SetL(j["l"].get<double>());
    this->SetDt(j["d"].get<double>());
    this->SetN(j["n"].get<int>());
}

double ConfigurationParser::GetR()
{
    assert(r>=0);
    return this->r;
};

void ConfigurationParser::SetR(double r)
{
    CheckSign(r,"r");
    this->r = r;
};




double ConfigurationParser::GetA()
{
    assert(a>=0);
    return this->a;
};
void ConfigurationParser::SetA(double a)
{
    CheckSign(a,"a");
    this->a = a;
};




double ConfigurationParser::GetB()
{
    assert(b>=0);
    return this->b;
};
void ConfigurationParser::SetB(double b)
{
    CheckSign(b,"b");
    this->b = b;

};




double ConfigurationParser::GetM()
{
    assert(m>=0);
    return this->m;
};
void ConfigurationParser::SetM(double m)
{
    CheckSign(m,"m");
    this->m = m;
  
};





double ConfigurationParser::GetK()
{
    assert(k >=0);
    return this->k;
};
void ConfigurationParser::SetK(double k)
{
    CheckSign(k,"k");
    this->k = k;
 
};





double ConfigurationParser::GetL()
{
    assert(l>=0);
    return this->l;
};
void ConfigurationParser::SetL(double l)
{
    CheckSign(l,"l");
    this->l = l;
 
};





double ConfigurationParser::GetDt()
{
    assert(d>=0);
    return this->d;
};
void ConfigurationParser::SetDt(double d)
{
    CheckSign(d,"d");
    this->d = d;
 
};




int ConfigurationParser::GetN()
{
    assert(n>=0);
    return this->n;
};
void ConfigurationParser::SetN(int n)
{
    CheckSign(n,"n");
    this->n = n;
 
};


void ConfigurationParser::CheckSign(double var, std::string varname)
{
    if(var < 0) 
    {
        std::string msg = std::string("Configuration error: variables cannot be negative -> ");
        std::string var=std::string(varname);   
        throw std::invalid_argument(msg+var);
    }
};

void ConfigurationParser::CheckSign(int var, std::string varname)
{
    if(var < 0) 
    {
        std::string msg = std::string("Configuration error: variables cannot be negative -> ");
        std::string var=std::string(varname);   
        throw std::invalid_argument(msg+var);
    }
};
