/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeSimulation.cpp
 * Author: alex
 * 
 * Created on October 9, 2018, 6:40 PM
 */

#include "../../include/LandscapeSimulation.hpp"
#include "../../include/OutputGenerator.hpp"
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <cstddef>

using namespace std;
LandscapeSimulation::LandscapeSimulation(Landscape landscape)
{
    //assert(landscape!=NULL);
    this->landscape = landscape;
}

LandscapeSimulation::LandscapeSimulation() 
{
    
}


LandscapeSimulation::~LandscapeSimulation()
{
    
}
void LandscapeSimulation::Run()
{
    OutputGenerator output = OutputGenerator();
    double haresNew,pumasNew;
    int nextOutput=landscape.GetT();
    
    double averageNumbersForPuma[landscape.GetT()];
    double averageNumbersForHares[landscape.GetT()];
    int cnt=0;
    
    for(int rep = 1; rep <= landscape.GetRepetitions(); rep++)
    {
        if(rep == nextOutput)
        {
            
            nextOutput=nextOutput+landscape.GetT();
            
            //save average numbers in order to write them
            //in file once at the of the simulation
            averageNumbersForHares[cnt] = GetAverageHares();
            averageNumbersForPuma[cnt] = GetAveragePumas();
            
            output.CreatePPMFile(landscape);
            cnt++;
        }
        for( int i=0; i < landscape.GetWidth(); i++)
        {
            for( int j=0; j < landscape.GetHeight(); j++)
            {
                if(landscape.IsSquareWater(i,j) == true)
                {
                    continue;
                }
                //what happens when we call GetPumas(-1,0),getN is unimplemented
                pumasNew=
                        landscape.GetPumas(i,j)+ 
                        landscape.GetDt()*
                        ( 

                            landscape.GetB()*landscape.GetHares(i,j)*landscape.GetPumas(i,j)-
                            landscape.GetM()*landscape.GetPumas(i,j)+
                            landscape.GetL()*( 
                                               (    
                                                    landscape.GetPumas(i-1,j) +
                                                    landscape.GetPumas(i+1,j) +
                                                    landscape.GetPumas(i,j-1) +
                                                    landscape.GetPumas(i,j+1)
                                               )-
                                                landscape.GetN(i,j)*landscape.GetPumas(i,j)
                                            )

                        );

                haresNew=
                        landscape.GetHares(i,j)+
                        landscape.GetDt()*
                        (
                            landscape.GetR()*landscape.GetHares(i,j)-
                            (landscape.GetA()*landscape.GetHares(i,j)*landscape.GetPumas(i,j))+
                            landscape.GetK()*(
                                                ( 
                                                    landscape.GetHares(i-1,j) +
                                                    landscape.GetHares(i+1,j) +
                                                    landscape.GetHares(i,j-1) +
                                                    landscape.GetHares(i,j+1)
                                                )-
                                                landscape.GetN(i,j)*landscape.GetHares(i,j) 
                                            )
                        );

                landscape.SetPumas(i,j,pumasNew);
                landscape.SetHares(i,j,haresNew);
            }

        }  
    }
    output.PrintAverageHaresAndPumas(averageNumbersForPuma,averageNumbersForHares,cnt);
}

double LandscapeSimulation::GetAverageHares()
{
    double averageHares=0.0f;
    double totalHares =0.0f;
    double totalSquares = landscape.GetHeight()*landscape.GetWidth();
    
    for(int i=0; i < landscape.GetHeight();i++)
    {
        for(int j=0; j < landscape.GetWidth();j++)
        {
            totalHares += landscape.GetHares(i,j);
        }
    }
    averageHares = totalHares/totalSquares;
    return averageHares;
}

double LandscapeSimulation::GetAveragePumas()
{
    double averagePumas=0.0f;
    double totalPumas = 0.0f;
    double totalSquares = landscape.GetHeight()*landscape.GetWidth();
    
    for(int i=0; i < landscape.GetHeight();i++)
    {
        for(int j=0; j < landscape.GetWidth();j++)
        {
            totalPumas += landscape.GetPumas(i,j); 
        }
    }
    averagePumas = totalPumas/totalSquares;
    return averagePumas;
    
}