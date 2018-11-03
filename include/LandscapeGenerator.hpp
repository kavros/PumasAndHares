#ifndef LANDSCAPEGENERATOR_HPP
#define LANDSCAPEGENERATOR_HPP
#include <string>
using namespace std;
/**
 * A class that we use in order to geneate Landscapes.
 */
class LandscapeGenerator
{
        
public:           
    /**
     * Constructor for landscape generator.
     * Initialize member variables.
     */
    LandscapeGenerator(); 
    /**
     * Return a landscape with zero and one in random positions
     * using member variables.
     * 
     * @return 
     */
    int GetRandomLandDistribution2();
    /**
     * Get input values from command line and assign them to member variables using
     * setter functions.
     * @param ac
     * @param av
     * @return 
     */
    int ParseCmdLine(int ac, char *av[]);
    /**
     * Sets total number of rows.
     * @throws invalid_argument exception if totalRows is below 0.  
     * @param totalRows
     */
    void SetTotalRows(int totalRows);
    /**
     * Sets total number of columns.
     * @throws invalid_argument exception if totalColumns is below 0.  
     * @param totalColumns
     */
    void SetTotalColumns(int totalColumns);
    /**
     * Sets land percentage.
     * @throws invalid_argument exception if landPercentage is below 0 or higher than 1.  
     * @param landPercentage 
     */
    void SetLandPercentage(float landPercentage);
    /**
     * Sets output file name.
     *  @throws invalid_argument exception if file name is empty.
     * @param fileName
     */
    void SetOutputFileName(string fileName);
    /**
     * Writes landscape to a file.
     */
    void WriteLandscapeToFile();
    /**
     * Generate a random land distribution.
     */
    void GetRandomLandDistribution();

private:
    int totalColumns;
    int totalRows;
    int landMatrix[2002][2002];
    float landPercentage;
    string outputFileName;
    /**
     * Return random integer number in the range [lowerbound,higherbound].
     * @param lowerBound
     * @param upperBound
     * @return 
     */
    int GetRandomInRange(int lowerBound,int upperBound);
    /**
     * Initialize all position of the landscape with water.
     */ 
    void InitLandscapeWithWater();
    /**
    * Here we create the landscape. At first we create a set of coordinates (x,y) in the range x:(2 - totalRows-1)      
    * y:(2 - totalColumns-1) and then throw land in and around of that point. For every new point we create,                 
    * we increase the number count by one and check that we don't exceed the total points wanted.                    
    */
    void GenerateRandomLand();
    /*
    * Here the loops go through all the points that have been created and finds the points of land
    * which have no neighbors. So if a point doesn't have, then a land point is created next to it in a way that
    * it doesn't affect the boundaries.                                                            
    */ 
    int NormalizeLandscape();
    /**
 
    * Subtrace extra land to reach again the wanted percentage of land in landscape.
    * Because extra land was added in section 2 (if is added), the algorithm need to find a way to replace that land with water somewhere else.
    * It finds a land point that has more than two neighbors and make one of them water. 
    */
    void RemoveExtraLand(int countExtraLand);
    /**
     * Save landscape in to .dat file.
     */
    void SaveLandscape();
    
    /**
     * Returns the number of neighbors for the cell (i,j) that have water,
     * @param i
     * @param j
     * @return 
     */
    int CountNeighbours(int i,int j);

};  

#endif
