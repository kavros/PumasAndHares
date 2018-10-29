#include "LandscapeParser.hpp"
#include "LandscapeGenerator.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>      
#include <sstream>      // std::istringstream
LandscapeParser::LandscapeParser(Landscape* landscape,std::string filePath)
{
    SetLandscape(landscape);
    SetFilePath(filePath);
}

LandscapeParser::~LandscapeParser() 
{
    DealocateGrid();
}

LandscapeSquare** LandscapeParser::ReadLandscapeFromFile()
{
    
    std::string line;
    std::ifstream landscapeFile (filePath);
    int currRow = -1;
    
    
    if (landscapeFile.is_open())
    {
        while ( getline (landscapeFile,line) )
        {            
            if(currRow == -1)
            {
                int totalRows,totalColumns;
                std::vector<int> dimensions=GetDimensions(line);
                totalRows=dimensions.at(0);
                totalColumns=dimensions.at(1);
                grid = AllocateSpaceForGrid(totalRows,totalColumns);
                
                landscape->SetGrid(grid);
                landscape->SetTotalRows(totalRows);
                landscape->SetTotalColumns(totalColumns);
            
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
        throw std::invalid_argument("Unable to open the file.");
    }
    return grid;
}

int LandscapeParser::GetGridValue(char& c)
{
    IsValid(c);
    return atoi(&c);   
}

void LandscapeParser::IsValid(char& c)
{
    if (isdigit(c))
    {
        int num =atoi(&c);
        
        if(num ==0 || num == 1)
        {
         //valid value   
        }
        else
        {
            throw std::invalid_argument("Landscape file is not valid.");
        }
    }
}

std::vector<int> LandscapeParser::GetDimensions(std::string firstLine)
{
    std::istringstream is( firstLine );
    std::vector<int> dimensions;
    int n;
    while( is >> n ) 
    {
        dimensions.push_back(n);
    }

    if(dimensions.size() !=2 )
    {
        throw std::invalid_argument("First line in landscape file is wrong.");
    }
    return dimensions;

}

LandscapeSquare** LandscapeParser::AllocateSpaceForGrid(int totalRows,int totalColumns)
{
    LandscapeSquare** grid= new LandscapeSquare*[totalRows];
    
    for(int i=0; i < totalRows; i++)
    {
        grid[i] = new LandscapeSquare[totalColumns]();
    }
    return grid;
}

void LandscapeParser::ParseRow(LandscapeSquare** grid, string line, int currRow)
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

void LandscapeParser::DealocateGrid()
{
    //deallocate array
    for(int i=0; i < landscape->GetTotalRows(); i++)
    {
        delete[] grid[i];
    }
    delete grid;
}


LandscapeSquare** LandscapeParser::GetGrid()
{
    return grid;
}

string LandscapeParser::GetFilePath()
{
    return filePath;
}

int LandscapeParser::SetFilePath(string filePath)
{
    this->filePath = filePath;
    return 0;

}

int LandscapeParser::SetLandscape(Landscape* landscape)
{
    this->landscape = landscape;
    return 0;

}
