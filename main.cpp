#include <iostream>
#include "GenerateLandscape.hpp"
#include "ParameterParser.hpp"
using namespace std;

int main()
{
	//TODO: verify that numbers are ok
	// 0 < width,height<=2000  
	//and landDistribution+waterDistribution  ==100
	
	GenerateLandscape landscape(50,50,40,60);
	cout<<"Hello World"<<endl;
}

