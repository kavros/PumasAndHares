/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Landscape.hpp
 * Author: alex
 *
 * Created on October 7, 2018, 1:06 PM
 */

#ifndef LANDSCAPE_HPP
#define LANDSCAPE_HPP
#include "LandScapeSquare.hpp"
#include "Square.hpp"
#include <iostream>
using namespace std;

class Landscape
{
    private:
        int width;
        int height;
        LandscapeSquare[width][height] landscape; //missing implemenation file
    
    public:
        Landscape(int widht,int height);
        
        void SetWidth(int width);
        void SetHeight(int height);
        
        void GetWidth();
        void GetHeight();
};


#endif /* LANDSCAPE_HPP */

