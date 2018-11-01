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

    double GetDt();
    int SetDt(double d);

    int GetN();
    int SetN(int n);

    std::string GetFileName();
    int SetFileName(std::string fileNameStr);

    std::string GetJsonString();
    int SetJsonString(std::string jsonStr);
    
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
  std::string fileName;
  json options;
  std::string jsonString;

};

#endif /* CONFIGURATIONGENERATOR_HPP */
