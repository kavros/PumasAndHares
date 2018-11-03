#include "LandscapeSquare.hpp"
#include <iostream>
#include <assert.h>
using namespace std;
LandscapeSquare::LandscapeSquare() 
{
}

LandscapeSquare::~LandscapeSquare() 
{
}

void LandscapeSquare::SetIsWater(bool value)
{
    bool val =( (value == 0) || (value ==1));
    assert(val);
    this->isWater = value;
}

void LandscapeSquare::SetPumas(double pumas)
{
    assert(pumas >= 0);
    this->pumas=pumas;
}

void LandscapeSquare::SetHares(double hares)
{
    assert(hares>=0);
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
    