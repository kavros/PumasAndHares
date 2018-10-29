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

#include <string>
class LandscapeSquare {
public:
    LandscapeSquare();
    void SetIsWater(bool value);
    void SetPumas(double pumas);
    void SetHares(double hares);
    
    double GetPumas();
    double GetHares();
    bool GetIsWater();
    
    virtual ~LandscapeSquare();
private:
    bool   isWater;
    double pumas;
    double hares;
    
    void CheckInput(bool value);
    void PrintWrongInputMsgAndExit(std::string msg);
};

#endif /* LANDSCAPESQUARE_HPP */

