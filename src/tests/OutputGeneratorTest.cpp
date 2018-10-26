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
#include <vector>
#include <sstream>
#include <stdexcept>

using namespace std;
void InitGrid(LandscapeSquare** grid,Landscape landscape);
void PrintPumasAndHares(Landscape landscape);
void PrintLandscape(Landscape landscape);
LandscapeSquare**  GetLandscapeFromFile(string filePath);
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
        landscape.SetTotalColumns(50);
        landscape.SetTotalRows(50);
        landscape.SetT(10);
        landscape.SetRepetions(500);


       
        
        //InitGrid(grid,landscape);
        LandscapeSquare** grid = GetLandscapeFromFile("./data/landscapes/crete3.dat");
        landscape.SetGrid(grid);
        landscape.AssignRandomPumasAndHares();
        
        //PrintLandscape(landscape);
        //PrintPumasAndHares(landscape);
        
        
        LandscapeSimulation simulation(landscape);
        simulation.Run();
        
        //deallocate array
        for(int i=0; i < landscape.GetTotalRows(); i++)
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

vector<int> GetDimensions(string firstLine)
{

        std::istringstream is( firstLine );
        vector<int> dimensions;
        int n;
        while( is >> n ) {
            // do something with n
            dimensions.push_back(n);
        }
        
        if(dimensions.size() !=2 )
        {
            throw invalid_argument("First line in landscape file is wrong.");
        }
        return dimensions;
}


LandscapeSquare** AllocateSpaceForGrid(int totalRows,int totalColumns)
{
    
    LandscapeSquare** grid= new LandscapeSquare*[totalRows];
    
    for(int i=0; i < totalRows; i++)
    {
        grid[i] = new LandscapeSquare[totalColumns]();
    }
    return grid;
        
}

LandscapeSquare** GetLandscapeFromFile(string filePath)
{
    string line;
    ifstream landscapeFile (filePath);
    int currRow = -1;
    
    LandscapeSquare**  grid = NULL;
    if (landscapeFile.is_open())
    {
        while ( getline (landscapeFile,line) )
        {            
            if(currRow == -1)
            {
                int totalRows,totalColumns;
                vector<int> dimensions=GetDimensions(line);
                totalRows=dimensions.at(0);
                totalColumns=dimensions.at(1);
                
                grid = AllocateSpaceForGrid(totalRows,totalColumns);
                
            }
            else
            {
                ParseRow(grid, line,currRow);   
            }
            
            currRow++;
            
        }
        landscapeFile.close();
    }
    else
    {
        cout << "Unable to open file";
    }
    return grid;
}


void ParseRow(LandscapeSquare**  grid,string line,int currRow)
{
    int currCol=0;
    for(char& c : line) 
    {
        if(c !=' ')
        {
            if(GetGridValue(c)==1 )
            {
                grid[currRow][currCol].SetIsWater(false);
            }
            else
            {
                grid[currRow][currCol].SetIsWater(true);
            }

            currCol++;

        }

    }
    
    
}
int GetGridValue(char& c)
{    
    IsGridValid(c);
    return atoi(&c);    
}


void IsGridValid(char& c)
{
        
    if (isdigit(c))
    {
        int num =atoi(&c);
        
        if(num ==0 || num == 1)
        {
            
        }
        else
        {
            //throw std::invalid_argument("Landscape file is not valid.");
        }
    }
}

void InitGrid(LandscapeSquare** grid,Landscape landscape)
{
     //initialize landscape grid
        for(int row=0; row < landscape.GetTotalRows(); row++)
        {
            for(int col=0; col < landscape.GetTotalColumns();  col++)
            {
                if(col > landscape.GetTotalColumns()/2 )
                {
                    grid[row][col].SetIsWater(true);
                }
                else
                {
                   grid[row][col].SetIsWater(false);
                }
                
                
            }
            
        }
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