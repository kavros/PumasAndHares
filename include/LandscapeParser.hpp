/**
 * A class that reads a landscape.dat file and returns a data structure
 * that represents our landscape.
 */
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
    /**
     * Contractor of Landscape parser use setters to  assign membervariables.
     * @param landscape
     * @param filePath
     */
    LandscapeParser(Landscape* landscape,string filePath);
    /**
     * Destructor of landscape parser.
     */
    virtual ~LandscapeParser();
    /**
     * A function that reads a landscape form a file
     * @throws invalid_argument exception if dimensions are negative or zero.
     * @throws invalid_argument exception if dat file rows are less or more than it should be.
     * @throws invalid_argument exception if dat file columns are less or more than it should be.
     * @throws invalid_argument exception if landscape content inside dat file contains a char that is not 0 or 1 or space or enter.
     * @throws invalid_argument exception if file does not exists.
     * @return a 2d array of the landscape.
     */
    LandscapeSquare** ReadLandscapeFromFile();
    /**
     * Return a 2d array of the landscape.
     * @return 
     */
    LandscapeSquare** GetGrid();
    /**
     * Return file name and path of landscape file.
     * @return 
     */
    string GetFilePath();
    /**
     * Sets file path and name to member variable.
     * @throws invalid_argument exception if path is empty.
     * @param filePath
     * @return 
     */
    void SetFilePath(string filePath);
    /**
     * Sets member variable of landscape.
     * @param landscape
     * @return 
     */
    void SetLandscape(Landscape* landscape);
    
    
private:
    /**
     * Return a number using a char.
     * @throws invalid_argument exception if number is not 0 or 1.
     * @param c
     * @return 
     */
    int GetGridValue(char& c);
    /**
     * Validates the number.
     * @throws invalid_argument exception if number is not 0 or 1.
     * @param c
     */
    void IsValid(char& c);
    /**
     * Return the dimensions of landscape file using the first row of dat file.
     * @throws invalid_argument exception if the format of the first row is not correct.
     * @param firstLine
     * @return 
     */
    std::vector<int> GetDimensions(std::string firstLine);
    /**
     * Allocate space for grid based on the first row of dat file.
     * @param totalRows
     * @param totalColumns
     * @return 
     */
    LandscapeSquare** AllocateSpaceForGrid(int totalRows,int totalColumns);
    /**
     * Assign values in to landscape based on dat file.
     * @throws invalid_argument exception if the format of the column is not correct.
     * @param grid
     * @param line
     * @param currRow
     */
    void ParseRow(LandscapeSquare**  grid,string line,int currRow);
    
    Landscape* landscape;
    string filePath;
    LandscapeSquare** grid;
};

#endif /* LANDSCAPEPARSER_HPP */

