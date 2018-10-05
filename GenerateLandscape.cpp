#include <iostream>
#include <fstream> 
#include <ctime>
#include "GenerateLandscape.hpp"
using namespace std;

GenerateLandscape::GenerateLandscape(int width,int height,int landDistribution,int waterDistribution)
{
	this->width=width;
	this->height=height;
	this->landDistribution=landDistribution;
	this->waterDistribution=waterDistribution;	
}



