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
    this->SetD(j["d"].get<double>());
    this->SetN(j["n"].get<int>());
}

double ConfigurationParser::GetR()
{
  return this->r;
};
int ConfigurationParser::SetR(double r)
{
  this->r = r;
  return CheckSign(this->r, "r");
};




double ConfigurationParser::GetA()
{
  return this->a;
};
int ConfigurationParser::SetA(double a)
{
  this->a = a;
  return CheckSign(this->a, "a");
};




double ConfigurationParser::GetB()
{
  return this->b;
};
int ConfigurationParser::SetB(double b)
{
  this->b = b;
  return CheckSign(this->b,"b");
};




double ConfigurationParser::GetM()
{
  return this->m;
};
int ConfigurationParser::SetM(double m)
{
  this->m = m;
  return CheckSign(this->m,"m");
};





double ConfigurationParser::GetK()
{
  return this->k;
};
int ConfigurationParser::SetK(double k)
{
  this->k = k;
  return CheckSign(this->k, "k");
};





double ConfigurationParser::GetL()
{
  return this->l;
};
int ConfigurationParser::SetL(double l)
{
  this->l = l;
  return CheckSign(this->l,"l");
};





double ConfigurationParser::GetD()
{
  return this->d;
};
int ConfigurationParser::SetD(double d)
{
  this->d = d;
  return CheckSign(this->d, "d");
};




int ConfigurationParser::GetN()
{
  return this->n;
};
int ConfigurationParser::SetN(int n)
{
  this->n = n;
  return CheckSign(this->n, "n");
};




ConfigurationParser::ConfigurationParser(const ConfigurationParser& orig) {
}

ConfigurationParser::~ConfigurationParser() {
}


int ConfigurationParser::CheckSign(double var, std::string varname)
{
  if(var > 0.0)
  {
    return 0;
  }
  else
  {
    std::cout << "Configuration error: variable '" << varname << "' has the wrong sign." << std::endl;
    return -1;
  }
};

int ConfigurationParser::CheckSign(int var, std::string varname)
{
  if(var > 0)
  {
    return 0;
  }
  else
  {
    std::cout << "Configuration error: variable '" << varname << "' has the wrong sign." << std::endl;
    return -1;
  }
};
