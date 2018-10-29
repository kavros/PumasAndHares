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
#include <fstream>



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
    
    this->fileName = args::get(filename);
    this->options["r"] = args::get(r);
    this->options["a"] = args::get(a);
    this->options["b"] = args::get(b);
    this->options["m"] = args::get(m);
    this->options["k"] = args::get(k);
    this->options["l"] = args::get(l);
    this->options["d"] = args::get(d);
    this->options["n"] = args::get(n);
    this->jsonString = this->options.dump(4);
}

bool ConfigurationGenerator::WriteToFile(std::string fileName){
    try
    {
        std::ofstream out(fileName);
        out << this->jsonString;
        out.close();
    }
    catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
    
};

