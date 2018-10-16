/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeSquare.hpp
 * Author: alex
 *
 * Created on October 9, 2018, 8:54 PM
 */

#ifndef LANDSCAPESQUARE_HPP
#define LANDSCAPESQUARE_HPP

class LandscapeSquare {
public:
    LandscapeSquare();
    virtual ~LandscapeSquare();
private:
    bool   isWater;
    double pumas;
    double hares;
};

#endif /* LANDSCAPESQUARE_HPP */

