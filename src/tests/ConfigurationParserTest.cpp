/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ConfiurationParserTest.cpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:13 PM
 */

#include <iostream>
#include "../../include/ConfigurationParser.hpp"
#include "../../include/Args.hpp"

/*
 * 
 */
int main(int argc, char** argv) {
    args::ArgumentParser parser("Pumas And Hares Configuration File Parser Test.","");
    args::HelpFlag help(parser, "help", "Display this help message", {'h',"help"});
    args::Positional<std::string> filename(parser,"filename","Filename for the JSON configuration file.");
    try
    {
        parser.ParseCLI(argc, argv);
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
    
    
    std::string configFile = args::get(filename);
    ConfigurationParser cp(configFile);
    std::cout << "Reading configuration file: " << configFile << std::endl;
    std::cout.precision(2);
    std::cout << 
            "a is: " << cp.a << std::endl <<
            "b is: " << cp.b << std::endl <<
            "d is: " << cp.d << std::endl <<
            "k is: " << cp.k << std::endl <<
            "l is: " << cp.l << std::endl <<
            "m is: " << cp.m << std::endl <<
            "n is: " << cp.n << std::endl <<
            "r is: " << cp.r << std::endl;
    return 0;
}

