#include <iostream>
#include <fstream> 
#include <ctime>
#include "../../include/LandscapeGenerator.hpp" 

using namespace std;

LandscapeGenerator::LandscapeGenerator(int width,int height,int landDistribution,int waterDistribution)
{
	this->width=width;
	this->height=height;
	this->landDistribution=landDistribution;
	this->waterDistribution=waterDistribution;	
}

void LandscapeGenerator::GenerateData()
{
	
}


