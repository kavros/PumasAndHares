#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../../include/LandscapeGenerator.hpp"
using namespace std;

int main()
{
    int srand(time(NULL));
    
	//TODO: verify that numbers are OK
	// 0 < width,height<=2000  
	//and landDistribution+waterDistribution  ==100
	
	LandscapeGenerator landscape(2000, 2000, 0.4);
             
	cout<<"Hello World"<<endl<< endl;
        cout << "The wanted water percentage is " << landscape.Get_landscape_water_percentage() << endl;
        
        
        cout << "Landscape width is: " << landscape.Get_landscape_width() <<
        
        endl << "Landscape height is: " << landscape.Get_landscape_height() << endl;
        
        landscape.Get_random_land_distribution();

    
}

