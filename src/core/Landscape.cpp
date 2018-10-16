/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Landscape.cpp
 * Author: alex
 * 
 * Created on October 9, 2018, 8:49 PM
 */

#include "../../include/Landscape.hpp"
#include <iostream>
#include <stdexcept>
#include <assert.h>  

Landscape::Landscape(string configurationFileName,string landscapeFileName)
{
    
}

Landscape::Landscape() 
{

}


Landscape::~Landscape() 
{

}

//setters
void Landscape::SetR(double r)
{
    CheckConfigurationInput(r);
    this->r=r;
}

void Landscape::SetWidth(int width)
{
    CheckConfigurationInput(width);
    this->width = width;
}

void Landscape::SetHeight(int height)
{
    CheckConfigurationInput(height);
    this->height = height;
}

void Landscape::SetM(double m)
{
    CheckConfigurationInput(m);
    this->m=m;
}

void Landscape::SetK(double k)
{
    CheckConfigurationInput(k);
    this->k=k;       
}

void Landscape::SetL(double l)
{
    CheckConfigurationInput(l);
    this->l=l;
}

void Landscape::SetDt(double dt)
{
    CheckConfigurationInput(dt);
    this->dt=dt;
}

void Landscape::SetT(double T)
{
    CheckConfigurationInput(T);
    this->T=T;
}

void Landscape::SetA(double a)
{
    CheckConfigurationInput(a);
    this->a=a;
}

void Landscape::SetB(double b)
{
    CheckConfigurationInput(b);
    this->b=b;    
}

void Landscape::SetGrid(LandscapeSquare** grid )
{
    this->grid = grid;
}

void Landscape::SetIsWater( int i, int j,bool value)
{
    CheckArrayIndexes(i,j);
    this->grid[i][j].SetIsWater(value);
   
}


void Landscape::SetPumas( int i,  int j, double value) 
{
    CheckArrayIndexes(i,j);
    CheckPumasAndHaresValue(value);
    this->grid[i][j].SetPumas(value);
    
}

void Landscape::SetHares( int i,  int j, double value)
{
    CheckArrayIndexes(i,j); 
    CheckPumasAndHaresValue(value);
    this->grid[i][j].SetHares(value);   
}

void Landscape::SetRepetions(int rep)
{
    this->rep =rep;
}


//getters
int Landscape::GetHeight()
{
    return height;
}

int Landscape::GetWidth()
{
    return width;
}

double Landscape::GetR()
{
    return this->r;
}
double Landscape::GetM()
{
    return this->m;
}
double Landscape::GetK()
{
    return this->k;
}
double Landscape::GetL()
{
    return this->l;
}
double Landscape::GetDt()
{
    return this->dt;
}
double Landscape::GetT()
{
    return this->T;
}
double Landscape::GetA()
{
    return this->a;
}
double Landscape::GetB()
{
    return this->b;
}

double Landscape::GetPumas( int i,  int j)
{
    
    if(IsHaloSquare(i,j))
    {
        return 0;
    }
    
    CheckArrayIndexes(i,j);
    return this->grid[i][j].GetPumas();
}


unsigned int Landscape::GetN( int i,  int j) 
{
    CheckArrayIndexes(i,j);
    return IsSquareLand(i-1,j)+
           IsSquareLand(i,j-1)+
           IsSquareLand(i+1,j)+
           IsSquareLand(i,j+1);
}

double Landscape::GetHares( int i,int j)
{
    
    if(IsHaloSquare(i,j))
    {
        return 0;
    }
    CheckArrayIndexes(i,j);
    return this->grid[i][j].GetHares();
}

int Landscape::GetRepetitions()
{
    return this->rep;
}


bool Landscape::IsSquareWater(int i,int j)
{
    
    if(IsHaloSquare(i,j))
    {
        return true;
    }
    CheckArrayIndexes(i,j);
    return grid[i][j].GetIsWater();
}


bool Landscape::IsSquareLand( int i, int j)
{
    
    if(IsHaloSquare(i,j))
    {
        return false;
    }
    CheckArrayIndexes(i,j);
    return !(grid[i][j].GetIsWater());
}



//exception
void Landscape::CheckConfigurationInput(double value)
{
    if(value <= 0 )
    {
        throw invalid_argument("Configuration values can not be negative or zero.");
    }
}

void Landscape::CheckArrayIndexes(int i,int j)
{
     bool validRange = (i >= 0  && i < width) && (j >= 0 && j< height);
     assert(validRange==true);
     assert(i<2000);
     assert(j<2000);
}

void Landscape::CheckPumasAndHaresValue(double value)
{
    assert(value>=0);
}

bool Landscape::IsHaloSquare(int i,int j)
{
    bool isRowValid = (i>=0 && i < width);
    bool isColumnValid = (j>=0 && j < height);
    
    if( (isColumnValid && i==-1)        ||
        (isColumnValid && i==width)     ||
        (isRowValid && j==-1)    ||
        (isRowValid && j==height )
        )
    {
        return true;
    }
    return false;
}
