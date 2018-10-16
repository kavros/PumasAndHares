/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Landscape.hpp
 * Author: alex
 *
 * Created on October 9, 2018, 8:49 PM
 */
#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP
#define MAX_WIDTH 2000
#define MAX_HEIGHT 2000
#include <string>
#include "LandscapeSquare.hpp"
using namespace std;
class Landscape {
public:
    
    /**
     * Landscape constructor will use classes LadscapeParser and 
     * ConfigurationParse in order to initialize landscape array 
     * and configuration variables
     * @param configurationFileName
     * @param landscapeFileName
     */
    Landscape(string configurationFileName,string landscapeFileName);
    Landscape();
    virtual ~Landscape();
    
    //LandscapeSquare[] GetLandscape();
    unsigned int GetWidth();
    unsigned int GetHeight();
    
    /**
     * Returns the number of "dry" neighbors out of
     * four neighboring the square(i,j)
     * if the square i,j has less than four neighbors then returns
     * only the the number of them. 
     * @param i
     * @param j
     * @return 
     */
    unsigned int GetN( int i, int j);
    double GetPumas( int i, int j);
    double GetHares( int i, int j);
    LandscapeSquare** GetLandscape();
    double GetR();
    double GetM(); 
    double GetK();
    double GetL();
    double GetDt();
    double GetT();
    double GetA();
    double GetB();
    int GetRepetitions();
    bool IsSquareWater( int i, int j);
    
    
    void SetR(double r);
    void SetM(double m); 
    void SetK(double k);
    void SetL(double l);
    void SetDt(double dt);
    void SetT(double T);
    void SetA(double a);
    void SetB(double b);
    void SetRepetions(int rep);
    
    void SetPumas( int i,  int j,double value);
    void SetHares( int i,  int j,double value);
    void SetIsWater( int i, int j,bool value);
    
    void SetWidth(int width);
    void SetHeight(int height);
    
    
    void SetGrid(LandscapeSquare** grid);    //remove this function after tests
  
    

private:
    unsigned int width;
    unsigned int height;
    double r,a,b,m,k,l,dt; //variables that help us to calculate the square(i,j)
    double T;  //the number of steps between the outputs
    double rep;  //number of times that our simulation is going to run
    LandscapeSquare** grid;//2d array
    
    void CheckConfigurationInput(double confValue);
    void CheckArrayIndexes(int i,int j);
    void CheckPumasAndHaresValue(double value);
    bool IsHaloSquare(int i,int j);
    bool IsSquareLand( int i,  int j);

};

#endif /* LANDSCAPE_HPP */

