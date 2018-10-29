#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <vector>
#include <sstream>
#include <stdexcept>
#include "../../include/LandscapeParser.hpp"
#include "../../include/LandscapeSimulation.hpp"
#include "../../include/Landscape.hpp"
#include "../../include/ConfigurationParser.hpp"
using namespace std;

void PrintPumasAndHares(Landscape landscape);
void PrintLandscape(Landscape landscape);

int main(int argc, char** argv) {
  
    try
    {
        ConfigurationParser parser("./config.json");
        Landscape landscape;
        
        landscape.SetR(parser.GetR());
        landscape.SetA(parser.GetA());
        landscape.SetB(parser.GetB());
        landscape.SetM(parser.GetM());
        landscape.SetK(parser.GetK());
        landscape.SetL(parser.GetL());
        landscape.SetDt(parser.GetN());
        
        landscape.SetT(100);
        landscape.SetRepetions(500);
        
        string landscapeInputFile = "./data/landscapes/qq.dat";

        LandscapeParser landscapeParser(&landscape,landscapeInputFile); 
        
        landscapeParser.ReadLandscapeFromFile();
        landscape.AssignRandomPumaAndHares();
        
        //PrintLandscape(landscape);
        //PrintPumasAndHares(landscape);
        
        LandscapeSimulation simulation(landscape);
        simulation.Run();
         
    }
    catch(std::exception& e )
    {
        
        cout<<e.what()<<std::endl;
    }
    return 0;
    
}

void PrintLandscape(Landscape landscape)
{
    
        //print landscape
        for(int i=0; i < landscape.GetTotalRows(); i++)
        {
            for(int j=0; j < landscape.GetTotalColumns();  j++)
            {
                cout << !landscape.IsSquareWater(i,j)<<" ";
            }
            cout<<std::endl;
        }
       
}

void PrintPumasAndHares(Landscape landscape)
{
        //print  puma and hares
        for(int i=0; i < landscape.GetTotalRows(); i++)
        {
            for(int j=0; j < landscape.GetTotalColumns();  j++)
            {
                if(landscape.IsSquareWater(i,j) == true)
                {
                    cout << "0 ";
                }
                else
                {
                    cout<<"("+std::to_string((double)landscape.GetPumas(i,j))+","+std::to_string( (double)landscape.GetHares(i,j)) +") ";
                }
                
                
            }
            cout<<std::endl;
        }
        printf("\n\n");
    
}