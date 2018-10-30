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
#include "../../include/CmdParser.hpp"

using namespace std;
void PrintPumasAndHares(Landscape landscape);
void PrintLandscape(Landscape landscape);

int main(int argc, char** argv) {
    
    try
    {
        //parse command line arguments
        CmdParser cmdLineParser(argc,argv);
        
        //parse configuration
        ConfigurationParser configParser(cmdLineParser.GetConfigFilePath());
        
        //add values from configuration to landscape.
        Landscape landscape;
        landscape.SetR(configParser.GetR());
        landscape.SetA(configParser.GetA());
        landscape.SetB(configParser.GetB());
        landscape.SetM(configParser.GetM());
        landscape.SetK(configParser.GetK());
        landscape.SetL(configParser.GetL());
        landscape.SetDt(configParser.GetDt());
        landscape.SetT(configParser.GetN());
        landscape.SetRepetions(500);
        
        //initialize land and water based on input file.
        LandscapeParser landscapeParser(&landscape,cmdLineParser.GetInputFilePath());
        landscapeParser.ReadLandscapeFromFile();
        
        //assign random puma and hares inside landscape
        landscape.AssignRandomPumaAndHares();
        landscape.SetOutputPrefix(cmdLineParser.GetOutputFilePrefix());
        
        clock_t tStart = clock();
        //run simulation 
        LandscapeSimulation simulation(landscape);
        simulation.Run();
        clock_t tEnd = clock();
        double totalTime=(double)(tEnd - tStart)/CLOCKS_PER_SEC;
        cout<< "-total time for the simulation is: "+std::to_string(totalTime)<<" secs"<<endl;
        

    }
    catch(std::exception& e )
    {

        cout<<e.what()<<std::endl;
    }
    return 0;

}

//Debug Functions
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
