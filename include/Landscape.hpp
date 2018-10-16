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
    unsigned int GetN(unsigned int i,unsigned int j);
    double GetPumas(unsigned int i,unsigned int j);
    double GetHares(unsigned int i,unsigned int j);
    LandscapeSquare** GetLandscape();
    double GetR();
    double GetM(); 
    double GetK();
    double GetL();
    double GetDt();
    double GetT();
    double GetA();
    double GetB();
    
    double SetR(double r);
    double SetM(double m); 
    double SetK(double k);
    double SetL(double l);
    double SetDt(double dt);
    double SetT(double t);
    double SetA(double a);
    double SetB(double b);
    
    void SetPumas(unsigned int i, unsigned int j,double value);
    void SetHares(unsigned int i, unsigned int j,double value);
    
    
private:
    unsigned int width;
    unsigned int height;
    double r,a,b,m,k,l,dt; //variables that help us to calculate the square(i,j)
    double T;  //the number of steps between the outputs
    double t;  //number of times that our simulation is going to run
    LandscapeSquare** landscape;//2d array
    void SetLandscape(unsigned int** val);
    
};

#endif /* LANDSCAPE_HPP */

