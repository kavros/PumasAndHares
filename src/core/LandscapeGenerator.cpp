#include <iostream>
#include <fstream> 
#include <ctime>
#include <cstdlib>
#include "../../include/LandscapeGenerator.hpp"
using namespace std;

LandscapeGenerator::LandscapeGenerator(int width,int height, float water_percentage)
{
        up_limit = 99;         /* this variable determines the initial probability of water creation in the landscape in SECTION 1:*/
	this->width=width;    /* width of the landscape */
	this->height=height;  /* height of the landscape */
        int land_matrix[3000][3000]; /* This is the matrix that will represent our landscape */
        int x_coord[10 + width*height/up_limit]; /*  */
        int y_coord[10 + width*height/up_limit]; /*  */
        this->water_percentage=water_percentage;
}

int LandscapeGenerator::Get_landscape_width() const
{
    return width;
}

int LandscapeGenerator::Get_landscape_height() const
{
    return height;
}

float LandscapeGenerator::Get_landscape_water_percentage() const
{
    return water_percentage;
}

int LandscapeGenerator::Get_random_land_distribution()
{
    ofstream myfile;
    myfile.open ("Data.dat");
    
    int count = 0;     /*  */
    int sum = 0;
    int total_space = height*width;
    int i, j, k;

    float water_concentration = 0;
    
    for(i=0; i<height; i++){
        for(j=0;j<width; j++){
            land_matrix[i][j] = 0;
        }
    }
    
  /* SECTION 1:
   * In this section of loops the Algorithm creates water pseudo-randomly in the whole landscape with
   * probability (1/(up_limit + 1)) %.
   * For every water space that it crates the coordinates are saved in the x-component vector named x_coord
   * and the y-component vector y_coord correspondingly.
   */
    for (i=1; i<height-1; i++){
        for (j=1; j<width-1; j++){
            k = 0 + (rand() % (up_limit - 0 + 1)); /* 
                                                    * Here we create a "random" number in the range (0 - up_limit) and when the number is equal
                                                    * to one specific number (e.g 46 in this case) of the range water is then created. This will
                                                    * give us approximately (1/(up_limit + 1))% of water in the landscape.
                                                    */
            if (k == 46)
            {       
                x_coord[count] = i;  /* store the x-coordinate of the water point */
                y_coord[count] = j;  /* store the y-coordinate of the water point */
                land_matrix[i][j] = 0;
            
                count += 1;
                if (count == 1000)
                { 
                    count = 0;
                    sum += 1;
                }  
            
            }
            else
            {
                land_matrix[i][j] = 1;
            }
            
        }
    }       
    count = (sum*1000) + count;   /* Sum the total number of counts */
    
    /* SECTION 2:
     * 
     */
    int level {0};
    int x_coordinate {0}, y_coordinate {0};
level_up:
    level += 1;   
    for (k=0; k<count; k++){
        x_coordinate = x_coord[k];
        y_coordinate = y_coord[k];
        for (i = x_coordinate-level; i<= x_coordinate+level; i++){
            for (j = y_coordinate-level; j<= y_coordinate+level; j++){
                if (land_matrix[i][j] != 0){
                    count +=1;
                    land_matrix[i][j] = 0;
                }
                if ((float)count/total_space >= water_percentage - 0.02){
                    goto exit_loop;
                }
            }
        }
    }
    goto level_up;
    
    exit_loop: cout << "Exit loop " << endl;
    
    for (i = 0; i < height; i++){
        for (j=0; j < width; j++){
            myfile << land_matrix[i][j] << " ";
        }
        myfile << endl;
    }

    cout << "The total landscape points are = " << total_space << endl;
    
    cout << "The total water points are = " << count << endl;
    
    water_concentration = (float) count/total_space;
    
    cout << "The total concentration of water is = " << water_concentration <<  " water/total_land" << endl;
    
    cout << endl;
    
    myfile.close();
}
