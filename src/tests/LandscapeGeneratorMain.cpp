#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../include/LandscapeGenerator.hpp"
#include "../../include/Landscape.hpp"
using namespace std;

int main(int argc, char** argv)
{
    //int srand(time(NULL));
    
    //LandscapeGenerator landscape(totalColumns, totalRows, landPercentage);
    LandscapeGenerator landscapeGenerator;
    landscapeGenerator.ParseCmdLine(argc,argv);
    
    landscapeGenerator.GetRandomLandDistribution2();   
}

