/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OutputGenerator.hpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:50 PM
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
     * Filename: output<<nextOutputNumber>.ppm where nextOutputNumber
     * is a counter which starts from 0
     * @param landscape
     */
    void CreatePPMFile(Landscape landscape);
    
    /**
     * Print average of hares and pumas at regular intervals.
     * How often do we need to print the average (it is an overhead) 
     * @param landscape
     */
    void PrintAverageHaresAndPumas(Landscape landscape);
    
    
private:
    int nextOutputNumber;
   
};

#endif /* OUTPUTGENERATOR_HPP */

