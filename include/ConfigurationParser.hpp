/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ConfigurationParser.hpp
 * Author: B049401
 *
 * Created on October 9, 2018, 6:42 PM
 */

#ifndef CONFIGURATIONPARSER_HPP
#define CONFIGURATIONPARSER_HPP
#include "Json.hpp"
#include <string>

using json = nlohmann::json;

class ConfigurationParser
{
public:
    double GetR();
    int SetR(double r);

    double GetA();
    int SetA(double a);

    double GetB();
    int SetB(double b);

    double GetM();
    int SetM(double m);

    double GetK();
    int SetK(double k);

    double GetL();
    int SetL(double l);

    double GetD();
    int SetD(double d);

    int GetN();
    int SetN(int n);

    ConfigurationParser(std::string configurationFileName);
    ConfigurationParser(const ConfigurationParser& orig);
    virtual ~ConfigurationParser();

private:
  int CheckSign(double var, std::string varname);
  int CheckSign(int var, std::string varname);
  json j;
  double r; // Hare birth rate.
  double a; // Predation rate.
  double b; // Puma birth rate per eaten hare.
  double m; // Puma mortality rate.
  double k; // Diffusion rate for hares.
  double l; // Diffusion rate for pumas.
  double d; // Time step size.
  int n; // Number of time steps.
};

#endif /* CONFIGURATIONPARSER_HPP */
