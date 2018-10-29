
#ifndef LANDSCAPEPARSER_HPP
#define LANDSCAPEPARSER_HPP
#include<string>
#include <iostream>
#include <vector>
#include "../include/LandscapeSquare.hpp"
#include "../include/Landscape.hpp"
class LandscapeParser 
{
public:
    LandscapeParser(Landscape* landscape,string filePath);
    virtual ~LandscapeParser();
    
    LandscapeSquare** ReadLandscapeFromFile();
    
    LandscapeSquare** GetGrid();
    string GetFilePath();
    int SetFilePath(string filePath);
    int SetLandscape(Landscape* landscape);
    
    
private:
    int GetGridValue(char& c);
    void IsValid(char& c);
    std::vector<int> GetDimensions(std::string firstLine);
    LandscapeSquare** AllocateSpaceForGrid(int totalRows,int totalColumns);
    void DealocateGrid();
    void ParseRow(LandscapeSquare**  grid,string line,int currRow);
    
    Landscape* landscape;
    string filePath;
    LandscapeSquare** grid;
};

#endif /* LANDSCAPEPARSER_HPP */

