/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeSimulationTest.cpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:12 PM
 */

#include <cstdlib>
#include <iostream>
#include "../../include/LandscapeSimulation.hpp"
#include "../../include/Landscape.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    LandscapeSimulation simulation;
    simulation.Run();
    
    Landscape landscape;
    cout<< landscape.GetHeight()<<endl;
    return 0;
}

