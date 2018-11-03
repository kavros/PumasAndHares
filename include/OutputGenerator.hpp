/**
 * A class that generates our outputs.
 * This class generate an image every T time steps which T is a value inside configuration.
 * In  addition, save a text file with average densities of pumas and hares.
 */
#ifndef OUTPUTGENERATOR_HPP
#define OUTPUTGENERATOR_HPP
#include "Landscape.hpp"
class OutputGenerator {
public:
    OutputGenerator();
    virtual ~OutputGenerator();
    
    /**
     * Generate a ppm file inside data/outputs output file
     * Filename: output <<prefix>>+<<nextOutputNumber>.ppm where nextOutputNumber
     * is a counter which starts from 0.
     * Every pixel can be blue or green or red or black for more details see documentation
     * of function GetSquarePixel.
     * @param landscape
     */
    int CreatePPMFile(Landscape landscape);
    
    /**
     * Print average number of hares and puma every T steps in a file
     * with name <<prefix>><<averages>>.txt.
     * @param landscape
     */
    int SaveAverages(double avgsPuma[],double avgsHares[],int totalElements,string prefix);
    
    
private:
    int nextOutputNumber;
   /**
    * if (square is water) pixel is blue.
    * if( pumas  > hares) pixel is red.
    * if( pumas < hares) pixel is green.
    * if( pumas == hares) pixel is black.
    * @param landscape
    * @param i
    * @param j
    * @return 
    */
    string GetSquarePixel(Landscape landscape,int i,int j);
};

#endif /* OUTPUTGENERATOR_HPP */

