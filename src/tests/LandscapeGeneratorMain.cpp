#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../include/LandscapeGenerator.hpp"
using namespace std;

int main()
{
    int srand(time(NULL));
	
	LandscapeGenerator landscape(13, 65, 0.41);
        
        landscape.GetRandomLandDistribution();   
}

