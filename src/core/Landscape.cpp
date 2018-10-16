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
    CheckInputValue(r);
    this->r=r;
}


void Landscape::SetWidth(int width)
{
    CheckInputValue(width);
    this->width = width;
}

void Landscape::SetHeight(int height)
{
    CheckInputValue(height);
    this->height = height;
}


void Landscape::SetM(double m)
{
    CheckInputValue(m);
    this->m=m;

    
}

void Landscape::SetK(double k)
{
    CheckInputValue(k);
    this->k=k;
        
}

void Landscape::SetL(double l)
{
    CheckInputValue(l);
    this->l=l;
}

void Landscape::SetDt(double dt)
{
    CheckInputValue(dt);
    this->dt=dt;
}

void Landscape::SetT(double t)
{
    CheckInputValue(t);
    this->t=t;
}

void Landscape::SetA(double a)
{
    CheckInputValue(a);
    this->a=a;
}

void Landscape::SetB(double b)
{
    CheckInputValue(b);
    this->b=b;
    
}

void Landscape::SetGrid(LandscapeSquare** grid )
{
    this->grid = grid;
}

void Landscape::SetIsWater(unsigned int i,unsigned int j,bool value)
{
    //TODO::check input i,j,value and throw exception
    this->grid[i][j].SetIsWater(value);
}


void Landscape::SetPumas(unsigned int i, unsigned int j, double value) 
{
    //TODO::check input i,j,value and throw exception
    this->grid[i][j].SetPumas(value);
    
}

void Landscape::SetHares(unsigned int i, unsigned int j, double value)
{
    //TODO::check input i,j,value and throw exception    
    this->grid[i][j].SetHares(value);
    
}

//getters
unsigned int Landscape::GetHeight()
{
    return height;
}

unsigned int Landscape::GetWidth()
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

double Landscape::GetPumas(unsigned int i, unsigned int j)
{
    return this->grid[i][j].GetPumas();
}


unsigned int Landscape::GetN(unsigned int i, unsigned int j) 
{
    return 0;
}

double Landscape::GetHares(unsigned int i, unsigned int j)
{
    return this->grid[i][j].GetHares();
}


void Landscape::CheckInputValue(double value)
{
    if(value <= 0 )
    {
        PrintWrongInputMsgAndExit("Configuration values can not be negative or zero.");
    }
}

void Landscape::PrintWrongInputMsgAndExit(string msg)
{
    cout<<msg<<std::endl;
    exit(-1);
}

