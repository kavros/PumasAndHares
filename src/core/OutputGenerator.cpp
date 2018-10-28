/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OutputGenerator.cpp
 * Author: alex
 * 
 * Created on October 9, 2018, 6:50 PM
 */

#include "../../include/OutputGenerator.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <assert.h>

OutputGenerator::OutputGenerator() 
{
    nextOutputNumber =0;
}

OutputGenerator::~OutputGenerator() {
}

void OutputGenerator::CreatePPMFile(Landscape landscape)
{
    int width = landscape.GetTotalColumns();
    int height = landscape.GetTotalRows();
    
    string filename="output"+std::to_string(nextOutputNumber)+".ppm";
    string folder="./data/outputs/";
    ofstream imgFile;
    
    imgFile.open (folder+filename);
    imgFile << "P3\n";
    imgFile << "# "+filename+"\n";
    
    imgFile << width;    
    imgFile << " "+std::to_string(height)+"\n";
    imgFile << "255\n";
        
    string imageValues="";
    int totalCharsInRow = 0;
    for(int i=0; i < height; i++)
    {
        for(int j=0; j < width;j++)
        {
            string pixel = GetSquarePixel(landscape,i,j);
            totalCharsInRow +=  pixel.size();
                    
            //add new line before total number of chars exceed 70 
            if(totalCharsInRow >= 45 )
            {
                totalCharsInRow =0;
                imageValues +="\n";
            }
            imageValues += pixel;
            
        }
        imageValues+="\n";
    }
    //SplitRows(imageValues);
    imgFile << imageValues;
    imgFile.close();
    nextOutputNumber++;
}


string OutputGenerator::GetSquarePixel(Landscape landscape,int i,int j)
{   
    string pixel="";
    bool isSquareWater = landscape.IsSquareWater(i,j);
   
    if(isSquareWater)
    {
        //make pixel white
        pixel+=" ";
        pixel +="255 ";//red
        pixel +="255 ";//blue
        pixel +="255 ";//green
        pixel +=" ";
    }
    else 
    {
        double hares = landscape.GetHares(i,j);
        double pumas = landscape.GetPumas(i,j);
        
        double pumaPercentage =0; 
        //puma and hares need to be positive numbers 
        //in order to calculate puma percentage
        if( hares > 0 && pumas > 0)
        {
            pumaPercentage =(pumas/(hares+pumas));
        }
                
        assert(pumaPercentage<=1 && pumaPercentage >=0);        
        int colorHue =pumaPercentage *255;
        assert(colorHue>=0 && colorHue<=255);
        
        
        string red = std::to_string(colorHue);
        pixel +=" ";
        pixel +=red+" ";//red
        pixel +="0 ";   //blue
        pixel +="0 ";   //green
        pixel +=" ";
     
    } 
    
  
    
    return pixel;
}

int OutputGenerator::SaveAverages(double avgsPuma[],double avgsHares[],int totalElements)
{
    if(avgsPuma  == NULL ||avgsHares == NULL || totalElements < 0 )
    {
        return -1;
    }
    string filename="averages.txt";
    string folder="./data/outputs/";
    ofstream txtFile;
    txtFile.open (folder+filename);
    txtFile<<"-Average numbers-"<<std::endl;
    for(int i=0; i < totalElements; i++)
    {
        txtFile<<"hares: "<<avgsHares[i]<<std::endl;
        txtFile<<"puma: "<<avgsPuma[i]<<std::endl;
        txtFile<<std::endl;
    }
    txtFile.close();
    return 0;
}
