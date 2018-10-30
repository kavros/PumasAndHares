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
    OutputGenerator output;
    double haresNew,pumasNew;
    int nextOutput=landscape.GetT();
    int totalAvgs= landscape.GetRepetitions()/landscape.GetT();
    
    double averageNumbersForPuma[totalAvgs];
    double averageNumbersForHares[totalAvgs];
    
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
        
        for( int row=0; row < landscape.GetTotalRows(); row++)
        {
            for( int col=0; col < landscape.GetTotalColumns(); col++)
            {
                if(landscape.IsSquareWater(row,col) == true)
                {
                    continue;
                }
                //what happens when we call GetPumas(-1,0),getN is unimplemented
                pumasNew=
                        landscape.GetPumas(row,col)+ 
                        landscape.GetDt()*
                        ( 

                            landscape.GetB()*landscape.GetHares(row,col)*landscape.GetPumas(row,col)-
                            landscape.GetM()*landscape.GetPumas(row,col)+
                            landscape.GetL()*( 
                                               (    
                                                    landscape.GetPumas(row-1,col) +
                                                    landscape.GetPumas(row+1,col) +
                                                    landscape.GetPumas(row,col-1) +
                                                    landscape.GetPumas(row,col+1)
                                               )-
                                                landscape.GetN(row,col)*landscape.GetPumas(row,col)
                                            )

                        );

                haresNew=
                        landscape.GetHares(row,col)+
                        landscape.GetDt()*
                        (
                            landscape.GetR()*landscape.GetHares(row,col)-
                            (landscape.GetA()*landscape.GetHares(row,col)*landscape.GetPumas(row,col))+
                            landscape.GetK()*(
                                                ( 
                                                    landscape.GetHares(row-1,col) +
                                                    landscape.GetHares(row+1,col) +
                                                    landscape.GetHares(row,col-1) +
                                                    landscape.GetHares(row,col+1)
                                                )-
                                                landscape.GetN(row,col)*landscape.GetHares(row,col) 
                                            )
                        );

                landscape.SetPumas(row,col,pumasNew);
                landscape.SetHares(row,col,haresNew);
            }

        }  
        
    }
    output.SaveAverages(averageNumbersForPuma,averageNumbersForHares,cnt,landscape.GetOutputPrefix());
    
}

double LandscapeSimulation::GetAverageHares()
{
    double averageHares=0.0f;
    double totalHares =0.0f;
    double totalSquares = landscape.GetTotalRows()*landscape.GetTotalColumns();
    
    for(int i=0; i < landscape.GetTotalRows();i++)
    {
        for(int j=0; j < landscape.GetTotalColumns();j++)
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
    double totalSquares = landscape.GetTotalRows()*landscape.GetTotalColumns();
    
    for(int i=0; i < landscape.GetTotalRows();i++)
    {
        for(int j=0; j < landscape.GetTotalColumns();j++)
        {
            totalPumas += landscape.GetPumas(i,j); 
        }
    }
    averagePumas = totalPumas/totalSquares;
    return averagePumas;
    
}