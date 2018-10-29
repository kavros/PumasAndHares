#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../include/LandscapeGenerator.hpp"
using namespace std;

int main()
{
    int srand(time(NULL));
    int totalColumns = 1300;
    int totalRows =100;
    double landPercentage = 0.8;
    LandscapeGenerator landscape(totalColumns, totalRows, landPercentage);
    
    landscape.GetRandomLandDistribution();   
}

