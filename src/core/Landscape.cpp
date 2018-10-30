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
#include <time.h>
#include <iostream>
#include <random>
Landscape::Landscape(string configurationFileName,string landscapeFileName)
{
    
}

Landscape::Landscape() 
{

}


Landscape::~Landscape() 
{

}
void Landscape::SetOutputPrefix(string outputPrefix)
{
    this->outputPrefix =outputPrefix;
}

string Landscape::GetOutputPrefix()
{
    return outputPrefix;
}

//setters
void Landscape::SetR(double r)
{
    CheckConfigurationInput(r);
    this->r=r;
}

void Landscape::SetTotalColumns(int width)
{
    CheckConfigurationInput(width);
    this->totalColumns = width;
}

void Landscape::SetTotalRows(int height)
{
    CheckConfigurationInput(height);
    this->totalRows = height;
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

void Landscape::SetT(int T)
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
int Landscape::GetTotalRows()
{
    return totalRows;
}

int Landscape::GetTotalColumns()
{
    return totalColumns;
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
int Landscape::GetT()
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


bool Landscape::IsSquareWater(int row,int col)
{
    
    if(IsHaloSquare(row,col))
    {
        return true;
    }
    CheckArrayIndexes(row,col);
    return grid[row][col].GetIsWater();
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

void Landscape::CheckArrayIndexes(int row,int col)
{
     bool validRange = (row >= 0  && row < totalRows) && (col >= 0 && col< totalColumns);
     assert(validRange==true);
     assert(row<=2000);
     assert(col<=2000);
}

void Landscape::CheckPumasAndHaresValue(double value)
{
    //assert(value>=0);
}

bool Landscape::IsHaloSquare(int row,int col)
{
    bool isRowValid = (row>=0 && row < totalRows);
    bool isColumnValid = (col>=0 && col < totalColumns);
    
    if( (isColumnValid && row==-1)          ||
        (isColumnValid && row==totalRows)      ||
        (isRowValid && col==-1)             ||
        (isRowValid && col==totalColumns )
        )
    {
        return true;
    }
    return false;
}


void Landscape::AssignRandomPumaAndHares()
{
    assert(grid!=NULL);
    

    
    for(int row=0; row < GetTotalRows(); row++)
        {
            for(int col=0; col < GetTotalColumns();  col++)
            {
                grid[row][col].SetHares(GetRandomInRange(0,5));
                grid[row][col].SetPumas( GetRandomInRange(0,5));
                
            }
            
        }
    
}

double Landscape::GetRandomInRange(double lowerBound,double upperBound)
{
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_real_distribution<> dis(lowerBound, upperBound);   
    
    //cout<<dis(gen)<<std::endl;
    
    return dis(gen);
    
}