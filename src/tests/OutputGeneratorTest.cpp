/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OutputGenerator.cpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:51 PM
 */

#include <cstdlib>
#include "../../include/OutputGenerator.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "../../include/LandscapeSimulation.hpp"
#include "../../include/Landscape.hpp"
#include "../../include/LandscapeSquare.hpp"
#include <time.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
  
    try
    {
        Landscape landscape;
        landscape.SetR(0.08f);
        landscape.SetA(0.04f);
        landscape.SetB(0.02f);
        landscape.SetM(0.06f);
        landscape.SetK(0.2f);
        landscape.SetL(0.2f);
        landscape.SetDt(0.4f);
        landscape.SetWidth(100);
        landscape.SetHeight(100);
        landscape.SetT(100);
        landscape.SetRepetions(500);

        //allocate space for test landscape grid
        LandscapeSquare** grid = new LandscapeSquare*[landscape.GetHeight()];
        for(int i=0; i < landscape.GetHeight(); i++)
        {
            grid[i] = new LandscapeSquare[landscape.GetWidth()]();
        }

        /* initialize random seed: */
        srand (time(NULL));

        
        //initialize landscape grid
        for(int i=0; i < landscape.GetHeight(); i++)
        {
            for(int j=0; j < landscape.GetWidth();  j++)
            {
                if(j > landscape.GetWidth()/2 )
                {
                    grid[i][j].SetIsWater(true);
                    grid[i][j].SetHares(0);
                    grid[i][j].SetPumas(0);
                }
                else
                {
                    
                    double hares = rand() % 50;
                    hares=hares/100;
                    
                    double pumas = rand() % 50;
                    pumas=pumas/100;
                    
                    grid[i][j].SetIsWater(false);
                    grid[i][j].SetHares(hares);
                    grid[i][j].SetPumas(pumas);
                }
                
            }
            
        }
        landscape.SetGrid(grid);
        
        
       /* 
        //print landscape
        for(int i=0; i < landscape.GetHeight(); i++)
        {
            for(int j=0; j < landscape.GetWidth();  j++)
            {
                cout << !landscape.IsSquareWater(i,j)<<" ";
            }
            cout<<std::endl;
        }
        
        //print  puma and hares
        for(int i=0; i < landscape.GetHeight(); i++)
        {
            for(int j=0; j < landscape.GetWidth();  j++)
            {
                if(landscape.IsSquareWater(i,j) == true)
                {
                    cout << "0,"<<" ";
                }
                else
                {
                    cout<<"("+std::to_string((double)landscape.GetPumas(i,j))+","+std::to_string( (double)landscape.GetHares(i,j)) +"), ";
                }
                
                
            }
            cout<<std::endl;
        }
        printf("\n\n");
        
*/
        
        LandscapeSimulation simulation(landscape);
        simulation.Run();
        
        //OutputGenerator output = OutputGenerator();
        //output.CreatePPMFile(landscape);
        /*
        //print puma and hares
        for(int i=0; i < landscape.GetHeight(); i++)
        {
            for(int j=0; j < landscape.GetWidth();  j++)
            {
                if(landscape.IsSquareWater(i,j) == true)
                {
                    cout << "0,"<<" ";
                }
                else
                {
                    cout<<"("+std::to_string((double)landscape.GetPumas(i,j))+","+std::to_string( (double)landscape.GetHares(i,j)) +"), ";
                }
                
                
            }
            cout<<std::endl;
        }
        
          */  
        //deallocate array
        for(int i=0; i < landscape.GetHeight(); i++)
        {
            delete[] grid[i];
        }
        delete grid;

    }
    catch(std::exception& e )
    {
        
        cout<<e.what()<<std::endl;
    }
    return 0;
    
}