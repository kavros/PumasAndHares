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
#include "../../include/LandscapeSquare.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    Landscape landscape;
    landscape.SetR(0.08f);
    landscape.SetA(0.04f);
    landscape.SetB(0.02f);
    landscape.SetM(0.06f);
    landscape.SetK(0.2f);
    landscape.SetL(0.2f);
    landscape.SetDt(0.4f);
    landscape.SetWidth(7);
    landscape.SetHeight(7);

    
    //allocate space for test landscape grid
    LandscapeSquare** grid = new LandscapeSquare*[landscape.GetHeight()];
    for(int i=0; i < landscape.GetHeight(); i++)
    {
        grid[i] = new LandscapeSquare[landscape.GetWidth()]();
    }
            
    //initialize landscape grid
    for(int i=0; i < landscape.GetHeight(); i++)
    {
        for(int j=i; j < landscape.GetWidth();  j++)
        {
            grid[i][j].SetIsWater(true);
            grid[i][j].SetHares(0);
            grid[i][j].SetPumas(0);
        }
    }
    landscape.SetGrid(grid);
    
   
    
    LandscapeSimulation simulation(landscape);
    simulation.Run();
    
    //deallocate array
    for(int i=0; i < landscape.GetHeight(); i++)
    {
        delete[] grid[i];
    }
    delete grid;
    
    return 0;
}

