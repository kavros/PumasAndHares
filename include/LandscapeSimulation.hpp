/**
 * A class that contains the function that run the simulation
 * using the provided input landscape,configuration landscape and equations.
 */

#ifndef LANDSCAPESIMULATION_HPP
#define LANDSCAPESIMULATION_HPP
#include "../include/Landscape.hpp"
#include "../include/OutputGenerator.hpp"

class LandscapeSimulation {
public:
    
    /**
     * Constructor  for the landscape simulation 
     * assigns landscape as a member variable.
     * @param landscape
     */
    LandscapeSimulation(Landscape landscape);
    /**
     * Deallocate the 2d array with LandscapeSquares after the simulation finish.
     */
    virtual ~LandscapeSimulation();

    /**
     * Run the simulation using the equations.
     */
    void Run();
    
private:
    Landscape landscape;
    OutputGenerator outputGenerator;
    /**
     * Return the average number of hares using every position of the landscape.
     * @return 
     */
    double GetAverageHares();
    /**
     * Return the average number of puma using every position of the landscape.
     * @return 
     */
    double GetAveragePumas();
    
};

#endif /* LANDSCAPESIMULATION_HPP */

