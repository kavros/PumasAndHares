#ifndef LANDSCAPESIMULATION_HPP
#define LANDSCAPESIMULATION_HPP
#include "../include/Landscape.hpp"
#include "../include/OutputGenerator.hpp"

class LandscapeSimulation {
public:
    LandscapeSimulation(Landscape landscape);
    virtual ~LandscapeSimulation();

    void Run();
    
private:
    Landscape landscape;
    OutputGenerator outputGenerator;
    double GetAverageHares();
    double GetAveragePumas();
    
};

#endif /* LANDSCAPESIMULATION_HPP */

