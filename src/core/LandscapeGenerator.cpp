#include <iostream>
#include <fstream> 
#include <ctime>
#include <cstdlib>
#include <exception>
#include "../../include/LandscapeGenerator.hpp"
#include "../../include/Args.hpp"

using namespace std;
/*
LandscapeGenerator::LandscapeGenerator(int width,int height, float landPercentage)
{

	this->totalRows=height;  
    
        this->landPercentage=landPercentage; 
}
*/
LandscapeGenerator::LandscapeGenerator()
{

}


int LandscapeGenerator::ParseCmdLine(int ac, char *av[])
{
    args::ArgumentParser parser("Landscape File Generator.");
    
    args::HelpFlag help(parser, "help", "Display this help message", {'h',"help"});
    
    args::ValueFlag<double> landPerc(parser, "l", "The percentage of land.", {'l'});
    args::ValueFlag<int> tRows(parser, "r", "The total rows of the landscape.", {'r'});
    args::ValueFlag<int> tColumns(parser, "c", "The total columns of the landscape.", {'c'});
    args::Positional<std::string> filename(parser,"filename","Output filename for the landscape.");
     try
    {
        parser.ParseCLI(ac, av);
        
        if(tColumns.Get() > 2000 || tRows.Get() > 2000)
        {
            throw invalid_argument("total columns and rows must be under 2000");
        }
        
        SetTotalColumns( tColumns.Get());
        SetTotalRows(tRows.Get());
        SetLandPercentage(landPerc.Get());
        SetOutputFileName(filename.Get());
        return 0;
    }
    
    catch(args::Help){
        std::cout << parser;
    }
    
    catch(args::ParseError e){
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
    }
    catch (args::ValidationError e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << parser;
    }
    
}

int LandscapeGenerator::SetOutputFileName(string fileName)
{
    this->outputFileName = fileName;
}

int LandscapeGenerator::SetTotalRows(int totalRows)
{
    this->totalRows = totalRows;
    return 0;
}

int LandscapeGenerator::SetTotalColumns(int totalColumns)
{
    this->totalColumns = totalColumns;
    return 0;
}

int LandscapeGenerator::SetLandPercentage(float landPercentage)
{
    this->landPercentage = landPercentage;
    return 0;
}


int LandscapeGenerator::GetRandomLandDistribution2()
{
    int totalLandPoints = landPercentage*totalColumns*totalRows;
    
    //initialize landscape with water
    for(int i =0; i<totalRows; i++)
    {
        for(int j =0; j<totalColumns; j++)
        {
            landMatrix[i][j]=0;
        }  
    }
    
    int randomColumnNumber =0;
    int randomRowNumber=0;
    int currLandPoint = 0;
    
    //assign land points randomly
    while( currLandPoint != totalLandPoints)
    {
        randomColumnNumber = GetRandomInRange(0,totalColumns-1);
        randomRowNumber= GetRandomInRange(0,totalRows-1);
        
        if( landMatrix[randomRowNumber][randomColumnNumber]==0 )
        {
            landMatrix[randomRowNumber][randomColumnNumber] = 1;
            currLandPoint++;
        }
    }
    
    WriteLandscapeToFile();
 
}


int LandscapeGenerator::GetRandomInRange(int lowerBound,int upperBound)
{
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<>dis(lowerBound, upperBound);   
    //cout<<dis(gen)<<std::endl;
    
    return dis(gen);   
}

void LandscapeGenerator::WriteLandscapeToFile()
{
    ofstream landscapeFile;
    try
    {
        landscapeFile.open (outputFileName);
        
        landscapeFile << totalRows << " " << totalColumns << endl; 
        for (int i = 0; i < totalRows; i++)
        {
            for (int j=0; j < totalColumns; j++)
            {
                landscapeFile << landMatrix[i][j] << " ";
            }
            landscapeFile << endl;
        }
    
        landscapeFile.close();
        
    }
    catch (exception& e)
    {
        cout << e.what() << '\n';
    }
}

int LandscapeGenerator::GetRandomLandDistribution()
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
    myfile.open (outputFileName);
    
    int count = 0;     /* this variable will hold the number of land points that exist inside the landscape */
    int totalSpace = totalRows*totalColumns; /* Total landscape points */
    int i, j;
    int x, y; /* integers we use for creating random coordinates */
    
    /* 
     * According to the total wanted percentage of land we will create a specific number of land points in "random" positions
     */
    int landPoints = landPercentage*totalSpace; 
    
    /*
     * Make sure nothing was written before in the matrix-landscape
     */
    for(i=0; i<totalRows+2; i++){
        for(j=0;j<totalColumns+2; j++){
            landMatrix[i][j] = 0;
        }
    }    
  /* *****************************************************************************************************************/
  /* SECTION 1:
  /* Here we create the landscape. At first we create a set of coordinates (x,y) in the range x:(2 - height-1) 
  /* y:(2 - width-1) and then throw land in and around of that point. For every new point we create,
  /*  we increase the number count by one and check that we don't exceed the total points wanted.
  /* HOW RANDOM NUMBERS ARE CREATED:
  /* The numbers are created randomly in a range [a,b] using the formula randomNumber = a + (rand()%((b-1)-a + 1));
  /******************************************************************************************************************/    
    while(count < landPoints)
    {
        x = 2 + (rand() % ((totalRows-1) - 2 + 1)); 
        y = 2 + (rand() % ((totalColumns-1) - 2 + 1));
          
        for (i = x-1; i<=x+1; i++){
            for (j = y-1; j<= y+1; j++)
            {
                   
                if (count == landPoints)
                {
                    //goto endloop; 
                    break;
                }                  
                if (landMatrix[i][j] == 0)
                {
                    landMatrix[i][j] = 1;
                    count += 1;
                }
            }
        }
    }

   /***************************************************************************************************************/
   /* SECTION 2:
   /* Here the loops go through all the points that have been created and finds the points of land
    * which have no neighbours. So if a point doesn't have, then a land point is created next to it in a way that
   /* it doesn't affect the boundaries.                                                            
   /***************************************************************************************************************/              
    int countNeighbours; 
    int extraLand = 0; /* In this value is recorded the number of extra land that was added  */
    for (i = 1; i <= totalRows; i++){
        for (j=1; j <= totalColumns; j++){
            
            countNeighbours = 0;
                
            if (landMatrix[i][j] == 1)
            {
                    /*At first count how many neighbours exist*/
                    if (landMatrix[i+1][j] == 1)
                    {
                        countNeighbours += 1;
                    }
                    if (landMatrix[i-1][j] == 1)
                    {
                        countNeighbours += 1;
                    }
                    if (landMatrix[i][j+1] == 1)
                    {
                        countNeighbours += 1;
                    }
                    if (landMatrix[i][j-1] == 1)
                    {
                        countNeighbours += 1;
                    }
                    
                    if (countNeighbours == 0)
                    {
                       
                        if (i == totalRows) 
                        {
                            landMatrix[i-1][j] = 1;  /* In the case my point is in the down limit of my landscape I don't want to
                                                       * create more land out of the borders */
                        }
                        else
                        {
                            landMatrix[i+1][j] = 1; 
                        }
                        extraLand += 1;    /* I want to know how much new land I created because that will change my concentration */
                    }                        
            }
        }
    }
 /*********************************************************************************************************************************************/  
 /* SECTION 3:
 /* Subtrace extra land to reach again the wanted percentage of land in landscape.
 /* Because extra land was added in section 2 (if is added), the algorithm need to find a way to replace that land with water somewhere else.
 /* It finds a land point that has more than two neighbours and make one of them water. 
 /*********************************************************************************************************************************************/
    int neighboursCoordX[4]; /* This two arrays hold the coordinates of the neighbours. */ 
    int neighboursCoordY[4];
    int randNeighbour;
    
subtrace_more:     
    
    for (i=1; i<=4; i++){
        neighboursCoordX[i] = 0;
        neighboursCoordY[i] = 0;
    }    
    /* 
     * In case we equalize the added land with adding water somewhere else goto to write the final matrix,
     *  ELSE try to find more land and do it water. 
     */
    if (extraLand == 0) goto write_file;


    x = 1 + (rand() % ((totalRows) - 1 + 1)); 
    y = 1 + (rand() % ((totalColumns) - 1 + 1));
    
    if (landMatrix[x][y] == 1){  /* We are searching for a land with more than two neighbours to make it water. */
        
        /* Count how many nearest neighbours exist and record their x and y coordinates in the two vectors
         * neighboursCoordX & Y.
         */
            if (landMatrix[x+1][y] == 1)
            {
                countNeighbours += 1;
                neighboursCoordX[countNeighbours] = x+1;
                neighboursCoordY[countNeighbours] = y;
            }
            if (landMatrix[x-1][y] == 1)
            {
                countNeighbours += 1;
                neighboursCoordX[countNeighbours] = x-1;
                neighboursCoordY[countNeighbours] = y;
            }
            if (landMatrix[x][y+1] == 1)
            {
                countNeighbours += 1;
                neighboursCoordX[countNeighbours] = x;
                neighboursCoordY[countNeighbours] = y+1;
            }
            if (landMatrix[x][y-1] == 1)
            {
                countNeighbours += 1;
                neighboursCoordX[countNeighbours] = x;
                neighboursCoordY[countNeighbours] = y-1;
            }
            
            if (countNeighbours >= 2)
            {    /* If it has more than two neighbours then take one of them "randomly" and make it water */
                
                randNeighbour = 1 + (rand() % ((countNeighbours) - 1 + 1));  
                
                x = neighboursCoordX[randNeighbour];
                y = neighboursCoordY[randNeighbour];
                
                landMatrix[x][y] = 0; 
             
                extraLand -= 1; /* Water was added in the position of land. Subtrace -1 from the sum */                
            }        
    }
    goto subtrace_more; 

write_file:        
 
    /* Landscape has been created. Write data into the file "Data.dat" */ 
    myfile << totalRows << " " << totalColumns << endl; 
    for (i = 1; i <= totalRows; i++){
        for (j=1; j <= totalColumns; j++){
            myfile << landMatrix[i][j] << " ";
        }
        myfile << endl;
    }
    
    myfile.close();

    cout << "--------------------------------------------------------------------------------------------------" << endl;
    cout << "The landscape has been created and is stored in the Data.dat file without water in the boundaries " << endl;
    cout << "--------------------------------------------------------------------------------------------------" << endl;

end_the_program:
    return 0;
}
