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
    int width = landscape.GetWidth();
    int height = landscape.GetHeight();
    
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
        
        double percentage =0; 
        if(hares !=0 && pumas!=0)
        {
            percentage =(pumas/(hares+pumas));
        }
                
        assert(percentage<=1);        
        int colorHue =percentage *255;
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

void OutputGenerator::PrintAverageHaresAndPumas(double avgsPuma[],double avgsHares[],int totalElements)
{
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
}
