/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeSquare.cpp
 * Author: alex
 * 
 * Created on October 9, 2018, 8:54 PM
 */

#include "LandscapeSquare.hpp"
#include <iostream>
using namespace std;
LandscapeSquare::LandscapeSquare() 
{
}

LandscapeSquare::~LandscapeSquare() 
{
}



void LandscapeSquare::CheckInput(bool value)
{
    if(value < 0)
    {
        PrintWrongInputMsgAndExit("pumas or hares variables cannot have negative value ");
    }
}

void LandscapeSquare::PrintWrongInputMsgAndExit(std::string msg)
{
    std::cout<<msg<<std::endl;
    exit(-1);
}

void LandscapeSquare::SetIsWater(bool value)
{
    this->isWater = value;
}

void LandscapeSquare::SetPumas(double pumas)
{
    CheckInput(pumas);
    this->pumas=pumas;
}

void LandscapeSquare::SetHares(double hares)
{
    CheckInput(hares);
    this->hares=hares;
}

double LandscapeSquare::GetPumas()
{
    return this->pumas;
}

double LandscapeSquare::GetHares()
{
    return this->hares;
}

bool LandscapeSquare::GetIsWater()
{
    return this->isWater;
}
    