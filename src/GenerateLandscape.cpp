#include <iostream>
#include <fstream> 
#include <ctime>
#include "../include/GenerateLandscape.hpp" 

using namespace std;

GenerateLandscape::GenerateLandscape(int width,int height,int landDistribution,int waterDistribution)
{
	this->width=width;
	this->height=height;
	this->landDistribution=landDistribution;
	this->waterDistribution=waterDistribution;	
}

void GenerateLandscape::GenerateData()
{
	std::ofstream outfile (filePath
							+"w"+to_string(width)
							+"h"+to_string(height)
							+"ld"+to_string(landDistribution)
							+"wd"+to_string(waterDistribution)
							+".txt");
	
	outfile << width << " " << height << endl;
	for(int j=0; j<height; j++)
	{
		for(int i=0; i<width; i++ )
		{
			outfile << 1<<" ";
		}
		outfile<<endl;
	}

	outfile.close();
}


