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
     * Print average number of hares and puma every T steps in a file
     * with name averages.txt.
     * @param landscape
     */
    void PrintAverageHaresAndPumas(double avgsPuma[],double avgsHares[],int totalElements);
    
    
private:
    int nextOutputNumber;
   
    string GetSquarePixel(Landscape landscape,int i,int j);
};

#endif /* OUTPUTGENERATOR_HPP */

