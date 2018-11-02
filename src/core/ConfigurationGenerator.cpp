/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ConfigurationGenerator.cpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:43 PM
 */

#include "../../include/ConfigurationGenerator.hpp"
#include "../../include/Args.hpp"
#include "../../include/Json.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>



ConfigurationGenerator::ConfigurationGenerator(int ac, char *av[]) {
    args::ArgumentParser parser("Pumas And Hares Configuration File Generator.","");
    args::HelpFlag help(parser, "help", "Display this help message", {'h',"help"});
    args::ValueFlag<double> r(parser,"r", "The birth rate of hares.", {'r'});
    args::ValueFlag<double> a(parser, "a", "The predation rate at which pumas eat hares.",{'a'});
    args::ValueFlag<double> b(parser, "b", "The birth rate of pumas per one hare eaten", {'b'});
    args::ValueFlag<double> m(parser, "m", "The puma mortality rate.", {'m'});
    args::ValueFlag<double> k(parser, "k", "The diffusion rate for hares.", {'k'});
    args::ValueFlag<double> l(parser, "l", "The diffusion rate for pumas.", {'l'});
    args::ValueFlag<double> d(parser, "d", "The size of the time step.", {'d'});
    args::ValueFlag<int> n(parser, "n", "The number of time steps between outputs.", {'n'});
    args::Positional<std::string> filename(parser,"filename","Filename for the JSON configuration file.");
    try
    {
        parser.ParseCLI(ac, av);
    }

    catch(args::Help){
        std::cout << parser;
    }

    catch(args::ParseError e){
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
    }


    this->SetFileName(args::get(filename));
    this->SetR(args::get(r));
    this->SetA(args::get(a));
    this->SetB(args::get(b));
    this->SetM(args::get(m));
    this->SetK(args::get(k));
    this->SetL(args::get(l));
    this->SetDt(args::get(d));
    this->SetN(args::get(n));
    this->SetJsonString(this->options.dump(4));
}

std::string ConfigurationGenerator::GetFileName()
{
  return this->fileName;
}

void ConfigurationGenerator::SetFileName(std::string fileNameStr)
{

    this->fileName = fileNameStr;
}

std::string ConfigurationGenerator::GetJsonString()
{
  return this->jsonString;
};

void ConfigurationGenerator::SetJsonString(std::string jsonStr)
{
    this->jsonString = jsonStr;
  
};

double ConfigurationGenerator::GetR()
{
  return this->r;
};

void ConfigurationGenerator::SetR(double r)
{
    CheckSign(r,"r") ;
    this->r = r;
};




double ConfigurationGenerator::GetA()
{
  return this->a;
};
void ConfigurationGenerator::SetA(double a)
{
    CheckSign(a,"a");
    this->a = a;
};




double ConfigurationGenerator::GetB()
{
  return this->b;
};
void ConfigurationGenerator::SetB(double b)
{
    
    CheckSign(b,"b");
    this->b = b;
};




double ConfigurationGenerator::GetM()
{
  return this->m;
};
void ConfigurationGenerator::SetM(double m)
{
    CheckSign(m,"m");
    this->m = m;
};





double ConfigurationGenerator::GetK()
{
  return this->k;
};
void ConfigurationGenerator::SetK(double k)
{
  CheckSign(k,"k");
    this->k = k;
};





double ConfigurationGenerator::GetL()
{
  return this->l;
};
void ConfigurationGenerator::SetL(double l)
{
    CheckSign(l,"l");
    this->l = l;
};





double ConfigurationGenerator::GetDt()
{
    return this->d;
};
void ConfigurationGenerator::SetDt(double d)
{
    CheckSign(d,"d");
    this->d = d;
};




int ConfigurationGenerator::GetN()
{
  return this->n;
};
void ConfigurationGenerator::SetN(int n)
{
    CheckSign(n,"N");
    
    this->n = n;
};




void ConfigurationGenerator::CheckSign(double var, std::string varname)
{
    if(var < 0) 
    {
        std::string msg = std::string("Configuration error: variables cannot be negative -> ");
        std::string var=std::string(varname);   
        throw std::invalid_argument(msg+var);
    }
};

void ConfigurationGenerator::CheckSign(int var, std::string varname)
{
    if(var < 0)

    {
        std::string msg = std::string("Configuration error: variables cannot be negative -> ");
        std::string var=std::string(varname);   
        throw std::invalid_argument(msg+var);
    }
    
 
};


int ConfigurationGenerator::WriteToFile(std::string fileName){
    try
    {
        std::ofstream out(fileName);
        out << this->jsonString;
        out.close();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;

};
