/**
 * A class that generates json configurations.
 * This class uses an external library called Json for modern c++ v3.3
 * and we use command line input to pass the parameters to the class.
 */
#ifndef CONFIGURATIONGENERATOR_HPP
#define CONFIGURATIONGENERATOR_HPP

#include "Json.hpp"
#include <string>
#include <map>

using json = nlohmann::json;

class ConfigurationGenerator {
public:

    /**
     * Reads command line input and updates member variables using setters.
     * @param ac
     * @param av
     */
    ConfigurationGenerator(int ac, char*av[]);
    /**
     * Writes json file.
     * @param fileName
     * @return 
     */
    int WriteToFile(std::string fileName);

    /**
     * Returns hare birth rate.
     * @return hare birth rate.
     */
    double GetR();
    /**
     * Sets member variable r which is hare birth rate.
     * @throws invalid_argument exception if r is below 0.
     * @param r
     */
    void SetR(double r);

    /**
     * Return predation rate
     * @return predation rate
     */
    double GetA();
    /**
     * Sets member variable a which is predation rate.
     * @throws invalid_argument exception if a is below 0. 
     */
    void SetA(double a);
    /**
     * Return puma birth rate per eaten hare.
     * @return puma birth rate per eaten hare.
     */
    double GetB();
    /**
     * Sets member variable b which is rate per eaten hare.
     * @throws invalid_argument exception if b is below 0.  
     * @param b
     */
    void SetB(double b);
    /**
     * Return puma mortality rate.
     * @return puma mortality rate.
     */
    double GetM();
    /**
     * Sets member variable m which is mortality rate.
     * @throws invalid_argument exception if m is below 0.  
     * @param m
     */
    void SetM(double m);

    /**
     * Return diffusion rate of hare.
     * @return diffusion rate of hare.
     */
    double GetK();
    /**
     * Sets member variable k which is diffusion rate of hares.
     * @throws invalid_argument exception if k is below 0.  
     * @param k
     */
    void SetK(double k);

    /**
     * Return diffusion rate of pumas.
     * @return diffusion rate of pumas.
     */
    double GetL();
    /**
     * Sets member variable l which is diffusion rate of pumas.
     * @throws invalid_argument exception if l is below 0.  
     * @param l
     */
    void SetL(double l);

    /**
     * Return time step size.
     * @return time step size.
     */
    double GetDt();
    /**
     * Sets member variable d which is time step size.
     * @throws invalid_argument exception if d is below 0.  
     * @param d
     */
    void SetDt(double d);
    
    /**
     * Return number of time steps.
     * @return number of time steps.
     */
    int GetN();
    /**
     * Sets member variable n which is number of time steps.
     * @throws invalid_argument exception if n is below 0.  
     * @param n
     */
    void SetN(int n);

    /**
     * Return json file name.
     * @return json file name.
     */
    std::string GetFileName();
    /**
     * Sets member variable fileName.
     * @throws invalid_argument exception if filename is empty.  
     * @param fileNameStr
     */
    void SetFileName(std::string fileNameStr);

    /**
     * Return json content.
     * @return json content.
     */
    std::string GetJsonString();
    /**
     * Sets member variable jsonStr.
     * @param jsonStr
     */
    void SetJsonString(std::string jsonStr);

private:
    /**
     * Setters call this function in order to check if the input value is valid.
     * @throws invalid_argument exception if var is below 0.  
     * @param var
     * @param varname
     */
    void CheckSign(double var, std::string varname);
    
    /**
     * Setters call this function in order to check if the input value is valid.
     * @throws invalid_argument exception if var is below 0.  
     * @param var
     * @param varname
     */
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
