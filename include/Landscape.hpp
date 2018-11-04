#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP
#define MAX_WIDTH 2000
#define MAX_HEIGHT 2000
#include <string>
#include "LandscapeSquare.hpp"
using namespace std;
/**
 * A class that holds the data structure of landscape.
 * We use a 2d array/grid which every position is a LandscapeSquare object.
 * A LandscapeSquare object holds: the density of hares, the density of pumas
 * and a boolean variable isWater.
 */
class Landscape 
{
public:
    /**
     * Constructor of landscape.
     */        
    Landscape();
    /**
     * Destructor of landscape.
     */
    virtual ~Landscape();
    
    /**
     * Return total columns of the landscape. 
     * @return total columns of the landscape. 
     */
    int GetTotalColumns();
    /**
     * Return total rows of the landscape. 
     * @return total rows of the landscape.
     */
    int GetTotalRows();
    
    /**
     * Returns the number of "dry" neighbors out of
     * four neighboring the square(i,j)
     * if the square i,j has less than four neighbors then returns
     * only the the number of them. 
     * @param i index for rows.
     * @param j index for columns.
     * @return returns the number of "dry" neighbors.
     */
    unsigned int GetN( int i, int j);
    /**
     * Return the density of pumas.
     * @param i index for rows.
     * @param j index for columns.
     * @return  the density of pumas.
     */
    double GetPumas( int i, int j);
    /**
     * Return the density of hares
     * @param i index for rows.
     * @param j index for columns.
     * @return  the density of hares.
     */
    double GetHares( int i, int j);
    /**
     * Returns 2d array/grid of LandscapeSquares which is our data structure for the landscape.
     * (animals density and land/water).
     * @return our landscape.
     */
    LandscapeSquare** GetGrid();
    /**
     * Returns hare birth rate.
     * @return hare birth rate.
     */    
    double GetR();
    /**
     * Return puma mortality rate.
     * @return puma mortality rate.
     */    
    double GetM(); 
    /**
     * Return diffusion rate of hare.
     * @return diffusion rate of hare.
     */
    double GetK();
    /**
     * Return diffusion rate of pumas.
     * @return diffusion rate of pumas.
     */
    double GetL();
    /**
     * Return time step size.
     * @return time step size.
     */
    double GetDt();
    /**
     * Return the number of steps between the outputs
     * @return the number of steps between the outputs
     */
    int GetT();
    /**
     * Return predation rate
     * @return predation rate
     */
    double GetA();
    /**
     * Return puma birth rate per eaten hare.
     * @return puma birth rate per eaten hare.
     */
    double GetB();
    /**
     * Return the total repetitions of the simulation.
     * @return the total repetitions of the simulation
     */
    int GetRepetitions();
    /**
     * Returns true if the landscape square (i,j) is water. 
     * @param i index for rows.
     * @param j index for columns.
     * @return true if the landscape square (i,j) is water. 
     */
    bool IsSquareWater( int i, int j);
    
    /**
     * Sets member variable r which is hare birth rate.
     * @throws invalid_argument exception if r is below 0.
     * @param r
     */
    void SetR(double r);
    /**
     * Sets member variable m which is mortality rate.
     * @throws invalid_argument exception if m is below 0.  
     * @param m
     */
    void SetM(double m); 
    /**
     * Sets member variable k which is diffusion rate of hares.
     * @throws invalid_argument exception if k is below 0.  
     * @param k
     */
    void SetK(double k);
    /**
     * Sets member variable l which is diffusion rate of pumas.
     * @throws invalid_argument exception if l is below 0.  
     * @param l
     */
    void SetL(double l);
    /**
     * Sets member variable d which is time step size.
     * @throws invalid_argument exception if d is below 0.  
     * @param d
     */
    void SetDt(double dt);
    /**
     * Sets the number of steps between outputs.
     * @throws invalid_argument exception if d is below 0 or higher than 500.  
     * @param T number of steps between outputs
     */
    void SetT(int T);
    /**
     * Return puma birth rate per eaten hare.
     * @return puma birth rate per eaten hare.
     */
    void SetA(double a);
    /**
     * Sets member variable b which is rate per eaten hare.
     * @throws invalid_argument exception if b is below 0.  
     * @param b
     */
    void SetB(double b);
    /**
     * Sets the total repetitions which is static 500.
     * @param rep
     */
    void SetRepetions(int rep);
    /**
     * Sets the density of pumas in cell (i,j).
     * @param i index for rows.
     * @param j index for columns.
     * @param value density of pumas.
     */
    void SetPumas( int i,  int j,double value);
    /**
     *  Sets the density of hares in cell (i,j). 
     * @param i index for rows.
     * @param j index for columns.
     * @param value density of hares
     */
    void SetHares( int i,  int j,double value);
    /**
     * Set true if grid (i,j) is water.
     * @param i index for rows.
     * @param j index for columns.
     * @param value true if is water or false if is land.
     */
    void SetIsWater( int i, int j,bool value);
    
    /**
     * Return total columns.
     * @throws invalid_argument exception if total columns is below 0 or 0.  
     * @param width number of columns.
     */
    void SetTotalColumns(int width);
    /**
     * Sets number of total rows. 
     * @throws invalid_argument exception if total rows is below 0 or 0.  
     * @param height number of total rows.
     */
    void SetTotalRows(int height);
    
    /**
     * Initialize  landscape with random values between 0 and 5.
     */
    void AssignRandomPumaAndHares();

    /**
     * Assign the grid.
     * @param grid 2d landscape array.
     */
    void SetGrid(LandscapeSquare** grid);
    /**
     * Sets the profix for images and averages
     * @param outputPrefix
     */
    void SetOutputPrefix(string outputPrefix);
    /**
     * Return prefix for images and averages.
     * @return 
     */
    string GetOutputPrefix();

    

private:
    int totalColumns;
    int totalRows;
    double r,a,b,m,k,l,dt; //variables that help us to calculate the square(i,j)
    int T;  //the number of steps between the outputs
    double rep;  //number of times that our simulation is going to run
    LandscapeSquare** grid;//2d array
    string outputPrefix;
    /**
     * Checks that configuration values are valid.
     * @throws invalid_argument exception if confValue is below 0 or 0.  
     * @param confValue
     */
    void CheckConfigurationInput(double confValue);
    /**
     * @throws invalid_argument exception if i,j are outside of the array.  
     * @param i
     * @param j
     */
    void AreArrayIndexesValid(int i,int j);
    /**
     * Return true if (i,j) is a halo position.
     * @param i
     * @param j
     * @return 
     */
    bool IsHaloSquare(int i,int j);
    /**
     * Return true if (i,j) is a land square.
     * @param i
     * @param j
     * @return 
     */
    bool IsSquareLand( int i,  int j);
    /**
     * Returns a double random number in given range.
     * @param lowerBound
     * @param upperBound
     * @return 
     */
    double GetRandomInRange(double lowerBound,double upperBound);

};

#endif /* LANDSCAPE_HPP */

