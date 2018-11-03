#include <iostream>
#include <fstream> 
#include <ctime>
#include <cstdlib>
#include <exception>
#include "../../include/LandscapeGenerator.hpp"
#include "../../include/Args.hpp"

using namespace std;

LandscapeGenerator::LandscapeGenerator()
{
    totalColumns = 0;
    totalRows =0;
    landPercentage =0;
    outputFileName ="";
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
    return 0;
}

void LandscapeGenerator::SetOutputFileName(string fileName)
{
    if(fileName.empty() ) 
    {
        throw std::invalid_argument("File name cannot be empty.");
    }
    this->outputFileName = fileName;

}

void LandscapeGenerator::SetTotalRows(int totalRows)
{
    if(totalRows <= 0 || totalRows > 2000) 
    {
        throw std::invalid_argument("Total number of rows can be between 0 and 2000.");
    }
    this->totalRows = totalRows;

}

void LandscapeGenerator::SetTotalColumns(int totalColumns)
{
    if(totalColumns <= 0 || totalColumns > 2000) 
    {
        throw std::invalid_argument("Total number of columns can be between 0 and 2000.");
    }
    this->totalColumns = totalColumns;

}

void LandscapeGenerator::SetLandPercentage(float landPercentage)
{
    if( (landPercentage <= 0.0) || (landPercentage >1.0)) 
    {
        throw std::invalid_argument("Land percentage must be between 0 and 1.");
    }
    this->landPercentage = landPercentage;

}




int LandscapeGenerator::GetRandomLandDistribution2()
{
    if(totalColumns ==0 || totalRows == 0 || landPercentage ==0 || outputFileName.empty())
    {
        return -1;
    }
    
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
    return 0;
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

void LandscapeGenerator::InitLandscapeWithWater()
{
     /*
     * Make sure nothing was written before in the matrix-landscape
     */
    for(int i=0; i < totalRows+2; i++)
    {
        for(int j=0;j<totalColumns+2; j++)
        {
            landMatrix[i][j] = 0;
        }
    }
    
}

void LandscapeGenerator::GenerateRandomLand()
{
    int x,y;
    int landPoints = landPercentage*totalRows*totalColumns; 
    int count=0;
    
    
    while(true)
    {
        x = GetRandomInRange(2,totalRows-1);
        y = GetRandomInRange(2,totalColumns-1);

        for (int i = x-1; i<=x+1; i++)
        {
            for (int j = y-1; j<= y+1; j++)
            {       
                if (count == landPoints)
                {
                    return;
                    //goto endloop; /* The land creation as soon as the count reaches the wanted value. */
                }                   
                if (landMatrix[i][j] == 0)
                {
                    landMatrix[i][j] = 1;
                    count += 1;
                }
            }
        }
    }
 
}

int LandscapeGenerator::NormalizeLandscape()
{
                
    int countNeighbours; 
    int extraLand = 0; /* In this value is recorded the number of extra land that was added  */
    for (int i = 1; i <= totalRows; i++)
    {
        for (int j=1; j <= totalColumns; j++)
        {
            
            countNeighbours = 0;
                
            if (landMatrix[i][j] == 1)
            {
                    /*At first count how many neighbors exist*/
                    countNeighbours = CountNeighbours(i,j);
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
    return extraLand;
}

void LandscapeGenerator::RemoveExtraLand(int extraLand)
{
    int neighboursCoordX[4]; /* This two arrays hold the coordinates of the neighbors. */ 
    int neighboursCoordY[4];
    int randNeighbour;
    int x,y;
    int countNeighbours=0;
    while(true)
    {

        for (int i=0; i<4; i++){
            neighboursCoordX[i] = 0;
            neighboursCoordY[i] = 0;
        }    
        /* 
         * In case we equalize the added land with adding water somewhere else goto to write the final matrix,
         *  ELSE try to find more land and do it water. 
         */
        if (extraLand == 0) 
        {
            return;
        };

        x = GetRandomInRange(1,totalRows);
        y = GetRandomInRange(1,totalColumns);

        if (landMatrix[x][y] == 1){  /* We are searching for a land with more than two neighbors to make it water. */

            /* Count how many nearest neighbors exist and record their x and y coordinates in the two vectors
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
                {    /* If it has more than two neighbors then take one of them "randomly" and make it water */

                    randNeighbour = GetRandomInRange(1,countNeighbours);

                    x = neighboursCoordX[randNeighbour];
                    y = neighboursCoordY[randNeighbour];

                    landMatrix[x][y] = 0; 

                    extraLand -= 1; /* Water was added in the position of land. Subtrace -1 from the sum */                
                }        
        }
    }
}

int LandscapeGenerator::CountNeighbours(int i,int j)
{
    int counter=0;
    if (landMatrix[i+1][j] == 1)
    {
        counter += 1;
    }
    if (landMatrix[i-1][j] == 1)
    {
        counter += 1;
    }
    if (landMatrix[i][j+1] == 1)
    {
        counter += 1;
    }
    if (landMatrix[i][j-1] == 1)
    {
        counter += 1;
    }
    return counter;
}

void LandscapeGenerator::SaveLandscape()
{
     
   ofstream myfile;
    myfile.open (outputFileName);
    /* Landscape has been created. Write data into the file "Data.dat" */ 
    myfile << totalRows << " " << totalColumns << endl; 
    for (int i = 1; i <= totalRows; i++)
    {
        for (int j=1; j <= totalColumns; j++)
        {
            myfile << landMatrix[i][j] << " ";
        }
        myfile << endl;
    }
    
    myfile.close();
}

void LandscapeGenerator::GetRandomLandDistribution()
{
    InitLandscapeWithWater();
    GenerateRandomLand();
    int extraLand  = NormalizeLandscape();
    RemoveExtraLand(extraLand);
    SaveLandscape();
}
