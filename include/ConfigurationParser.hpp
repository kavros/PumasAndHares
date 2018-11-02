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
    void SetR(double r);

    double GetA();
    void SetA(double a);

    double GetB();
    void SetB(double b);

    double GetM();
    void SetM(double m);

    double GetK();
    void SetK(double k);

    double GetL();
    void SetL(double l);

    double GetDt();
    void SetDt(double d);

    int GetN();
    void SetN(int n);

    ConfigurationParser(std::string configurationFileName);
    ConfigurationParser();

private:
    void CheckSign(double var, std::string varname);
    void CheckSign(int var, std::string varname);
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
