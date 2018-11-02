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
    int WriteToFile(std::string fileName);

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

    std::string GetFileName();
    void SetFileName(std::string fileNameStr);

    std::string GetJsonString();
    void SetJsonString(std::string jsonStr);

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
  std::string fileName;
  json options;
  std::string jsonString;

};

#endif /* CONFIGURATIONGENERATOR_HPP */
