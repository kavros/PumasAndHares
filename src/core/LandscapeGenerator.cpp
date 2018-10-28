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
//    if ((width <= 0) || (height <= 0)){
//        cout << "Error in the input data: " << endl;
//        cout << "You should give an integer non-negative number for each dimension in the range [1:2000]"  << endl;
//        goto end_the_program;
//    }
    
    /*
     * The landscape data will be saved in the file "Data.dat"
     */
    ofstream myfile;
    myfile.open ("Data.dat");
    
    int count = 0;     /* this variable will hold the number of land points that exist inside the landscape */
    int total_space = height*width; /* Total landscape points */
    int i, j;
    int x, y; /* integers we use for creating random coordinates */
    
    /* 
     * According to the total wanted percentage of land we will create a specific number of land points in "random" positions
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
    
  /* *****************************************************************************************************************/
  /* SECTION 1:
  /* Here we create the landscape. At first we create a set of coordinates (x,y) in the range x:(2 - height-1) 
  /* y:(2 - width-1) and then throw land in and around of that point. For every new point we create,
  /*  we increase the number count by one and check that we don't exceed the total points wanted.
   * The number is created randomly in a range [a,b] using the formula rand_num = a + (rand()%((b-1)-a + 1));
  /******************************************************************************************************************/    
more_land:
        x = 2 + (rand() % ((height-1) - 2 + 1)); 
        y = 2 + (rand() % ((width-1) - 2 + 1));
          
        for (i = x-1; i<=x+1; i++){
            for (j = y-1; j<= y+1; j++){
                   
                if (count == land_points){
                    goto endloop; /* The land creation as soon as the count reaches the wanted value. */
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
   /* Here the loops go through all the points that have been created and finds the points of land
    * which have no neighbour. So if a point doesn't have a land point is created next to it in a way that
   /* it doesn't affect the boundaries.                                                            
   /**********************************************************************************************************/              
    int count_neighbours; 
    int extra_land = 0; /* In this value is recorded the number of extra land that was added  */
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

 /* SECTION 3:
  * Subtrace extra land to reach again the wanted percentage of land in landscape.
  * Because extra land was added in section 2 (if is added), the algorithm need to find a way to replace that land with water somewhere else.
  * It finds a land point that has more than two neighbours and make one of them water. 
  */
    
    int neighbours_coord_x[4]; /* This two arrays hold the coordinates of the neighbours. */ 
    int neighbours_coord_y[4];
    int rand_neighbour;
    
subtrace_more:     
    
    for (i=1; i<=4; i++){
        neighbours_coord_x[i] = 0;
        neighbours_coord_y[i] = 0;
    }    
    /* 
     * In case we equalize the added land with adding water somewhere else goto to write the final matrix else try to find
     * more land and do it water. 
     */
    if (extra_land == 0) goto write_file;

    x = 1 + (rand() % ((height) - 1 + 1)); 
    y = 1 + (rand() % ((width) - 1 + 1));
    
    if (land_matrix[x][y] == 1){  /* We are searching for a land with more than two neighbours to make it water. */
        
        /* Count how many nearest neighbours exist and record their x and y coordinates in the two vectors
         * neighbours_coord_x & y.
         */
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
            
            if (count_neighbours >= 2){    /* If it has than two neighbours then take one of them "randomly" and make it water */
                rand_neighbour = 1 + (rand() % ((count_neighbours) - 1 + 1));  
                
                x = neighbours_coord_x[rand_neighbour];
                y = neighbours_coord_y[rand_neighbour];
                
                land_matrix[x][y] = 0; 
             
                extra_land -= 1; /* Water was added in the position of land. Subtrace -1 from the sum */
                
            }        
    }
    goto subtrace_more; 

write_file:    
     
    /* Landscape has been created. Write data into the file "Data.dat" */ 
    myfile << height << " " << width << endl; 
    for (i = 1; i <= height; i++){
        for (j=1; j <= width; j++){
            myfile << land_matrix[i][j] << " ";
        }
        myfile << endl;
    }

    /*
     * Print results
     */
    cout << "The total landscape points are = " << total_space << endl;
    
    cout << "The total land points are = " << count + extra_land << endl; /* extra_land variable should be zero. This addition is for check */
    
    float land_concentration = (float) count/total_space;
    
    cout << "The total concentration of land is = " << land_concentration <<  " land/total_land" << endl;
    
    cout << endl;
    
    myfile.close();

end_the_program:
cout << "Finish. The landscape with water in the boundaries is stored in the Data.dat file " << endl;
    
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

