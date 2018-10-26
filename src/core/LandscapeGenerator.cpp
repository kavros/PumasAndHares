#include <iostream>
#include <fstream> 
#include <ctime>
#include <cstdlib>
#include "../../include/LandscapeGenerator.hpp"
using namespace std;

LandscapeGenerator::LandscapeGenerator(int width,int height, float land_percentage)
{
	this->width=width;    /* Width of the landscape */
	this->height=height;  /* Height of the landscape */
        int land_matrix[2002][2002]; /* This is the matrix that will represent our landscape */
        this->land_percentage=land_percentage; /* Total percentage of water in the whole landscape */
}

int LandscapeGenerator::Get_random_land_distribution()
{
   // if ((width == 8) || (height == 8)){
   //     cout << "Error in the input data: " << endl;
   //     cout << "You should give an integer non-negative number for each dimension in the range [1:2000]"  << endl;
   //     goto finish_program;
   // }
    
    /*
     * The landscape data will be saved in the file "Data.dat"
     */
    ofstream myfile;
    myfile.open ("Data.dat");
    
    int count = 0;     /* this variable will hold the number of land points that exist inside the landscape */
    int total_space = height*width; /* Total landscape value */
    int i, j;
    int x, y; /* integers we use for creating random coordinates */
    
    /* 
     * According to the total wanted percentage of land we create a specific number of land points in random positions
     */
    int land_points = land_percentage*total_space; 
    
    /*
     * Make sure nothing was written before in the matrix-landscape
     */
    for(i=0; i<height+2; i++){
        for(j=0;j<width+2; j++){
            land_matrix[i][j] = 0;
        }
    }
    
  /* SECTION 1:
   * Here we create the landscape. At first we create a set of coordinates (x,y) in the range x:(1 - height-1) 
   * y:(1 - width-1) and then throw land in and around of that point. For every new point we create,
   *  we increase the number count by one and check that we don't exceed the total points wanted.
   */    
more_land:       
        x = 2 + (rand() % ((height-1) - 2 + 1)); 
        y = 2 + (rand() % ((width-1) - 2 + 1));
            for (i = x-1; i<=x+1; i++){
                for (j = y-1; j<= y+1; j++){
                    
                        if (count == land_points){
                            goto endloop;
                        }
                        
                        if (land_matrix[i][j] == 0)
                        {
                            land_matrix[i][j] = 1;
                            count += 1;
                        }
                }
            }
            goto more_land;
endloop:
            
            
   /***********************************************************************************************************/
   /* SECTION 2:
   /* Here we go through all the points that we have thrown land and now we want to make sure
   /* that there is non-point without neighbours. So if a point doesn't have we add one in a position 
   /* were we don't affect the boundaries.                                                                   
   /**********************************************************************************************************/              
    int count_neighbours; 
    int extra_land = 0;
    for (i = 1; i <= height; i++){
        for (j=1; j <= width; j++){
            
            count_neighbours = 0;
                
            if (land_matrix[i][j] == 1)
            {
                    /*At first count how many neighbours exist*/
                    if (land_matrix[i+1][j] == 1){
                    count_neighbours += 1;
                    }
                    if (land_matrix[i-1][j] == 1){
                    count_neighbours += 1;
                    }
                    if (land_matrix[i][j+1] == 1){
                    count_neighbours += 1;
                    }
                    if (land_matrix[i][j-1] == 1){
                    count_neighbours += 1;
                    }
                    
                    if (count_neighbours == 0){
                        if (i == height) {
                            land_matrix[i-1][j] = 1;  /* In the case my point is in the down limit of my landscape I don't want to
                                                       * create more land out of the borders */
                        }
                        else
                        {
                            land_matrix[i+1][j] = 1; 
                        }
                        extra_land += 1; /* I want to know how much new land I created because that will change my concentration */
                    }                        
            }
        }
    }
    cout << " extra_land = " << extra_land << endl; 
    
    int neighbours_coord_x[4];
    int neighbours_coord_y[4];
    int rand_neighbour;

subtrace_more:   
    for (i=1; i<=4; i++){
        neighbours_coord_x[i] = 0;
        neighbours_coord_y[i] = 0;
    }
    
    /* 
     * In case we equalized the added land with adding water somewhere else goto to write the final matrix else try to find
     * more land and do it water, if it has more than one nearest neighbours. 
     */
    if (extra_land == 0) goto write_file;

    x = 1 + (rand() % ((height) - 1 + 1)); 
    y = 1 + (rand() % ((width) - 1 + 1));
    cout << x << " " << y << " " <<land_matrix[x][y] << endl;
    count_neighbours = 0;
    if (land_matrix[x][y] == 1){  /* We are searching for a land with more than two neighbours to make it water. */
        
        /* Count how many nearest neighbours exist and record their x and y coordinates */
            if (land_matrix[x+1][y] == 1){
            count_neighbours += 1;
            neighbours_coord_x[count_neighbours] = x+1;
            neighbours_coord_y[count_neighbours] = y;
            }
            if (land_matrix[x-1][y] == 1){
            count_neighbours += 1;
            neighbours_coord_x[count_neighbours] = x-1;
            neighbours_coord_y[count_neighbours] = y;
            }
            if (land_matrix[x][y+1] == 1){
            count_neighbours += 1;
            neighbours_coord_x[count_neighbours] = x;
            neighbours_coord_y[count_neighbours] = y+1;
            }
            if (land_matrix[x][y-1] == 1){
            count_neighbours += 1;
            neighbours_coord_x[count_neighbours] = x;
            neighbours_coord_y[count_neighbours] = y-1;
            }
            
            cout << "neighbours " << count_neighbours << endl;
            
            if (count_neighbours >= 2){    /* If it is land with more than two neighbours then take one of them and make it water */
                rand_neighbour = 1 + (rand() % ((count_neighbours) - 1 + 1));  
                
                /* Take one of the neighbours and do it water */
                
                land_matrix[neighbours_coord_x[rand_neighbour]][neighbours_coord_y[rand_neighbour]] == 0; 
             
                extra_land -= 1; /* Water was added in the position of land. Subtrace one from the sum */
                
            }        
    }
    goto subtrace_more; 

write_file:    
    cout << " extra_land = " << extra_land << endl;
            
    /* 
     * Write data into the file "Data.dat" 
     */
    myfile << height << " " << width << endl; 
    for (i = 0; i < height+2; i++){
        for (j=0; j < width+2; j++){
            myfile << land_matrix[i][j] << " ";
        }
        myfile << endl;
    }

    /*
     *
     */
    cout << "The total landscape points are = " << total_space << endl;
    
    cout << "The total land points are = " << count << endl;
    
    float land_concentration = (float) count/total_space;
    
    cout << "The total concentration of land is = " << land_concentration <<  " land/total_land" << endl;
    
    cout << endl;
    
    myfile.close();

finish_program:
cout << endl;
    
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
    return land_percentage;
}

