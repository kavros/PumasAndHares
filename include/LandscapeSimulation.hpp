/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeSimulation.hpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:39 PM
 */

#ifndef LANDSCAPESIMULATION_HPP
#define LANDSCAPESIMULATION_HPP
#include "../include/Landscape.hpp"
#include "../include/OutputGenerator.hpp"

class LandscapeSimulation {
public:
    LandscapeSimulation(Landscape landscape);
    LandscapeSimulation();
    virtual ~LandscapeSimulation();
    
    Landscape GetLandscape();
    Landscape SetLandscape();
    void Run();
    
private:
    Landscape landscape;
    OutputGenerator outputGenerator;
    double GetAverageHares();
    double GetAveragePumas();
    
};

#endif /* LANDSCAPESIMULATION_HPP */

