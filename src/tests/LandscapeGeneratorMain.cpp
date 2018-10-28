#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../include/LandscapeGenerator.hpp"
using namespace std;

int main()
{
    int srand(time(NULL));
	
	LandscapeGenerator landscape(10, 10, 0.1);
             
        cout << "The wanted water percentage is " << landscape.Get_landscape_water_percentage() << endl;
        
        cout << "Landscape width is: " << landscape.Get_landscape_width() <<
        
        endl << "Landscape height is: " << landscape.Get_landscape_height() << endl;
        
        landscape.Get_random_land_distribution();

    
}

