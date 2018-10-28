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
#include <vector>
#include <sstream>
#include <stdexcept>
#include "../../include/LandscapeParser.hpp"
using namespace std;
void InitGrid(LandscapeSquare** grid,Landscape landscape);
void PrintPumasAndHares(Landscape landscape);
void PrintLandscape(Landscape landscape);

LandscapeSquare** GetLandscapeFromFile(string filePath,Landscape& landscape);
int GetGridValue(char& c);
void IsGridValid(char& c);
LandscapeSquare** AllocateSpaceForGrid(int totalRows,int totalColumns);
void ParseRow(LandscapeSquare**  grid,string line,int currRow);
vector<int> GetDimensions(string firstLine);


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
        
        landscape.SetT(100);
        landscape.SetRepetions(500);

        string landscapeInputFile = "./data/landscapes/crete3.dat";
        Landscape* landscapeRef = &landscape;
        LandscapeParser landscapeParser(landscapeRef,landscapeInputFile); 
        
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