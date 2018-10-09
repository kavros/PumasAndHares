/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeSquare.hpp
 * Author: alex
 *
 * Created on October 7, 2018, 1:38 PM
 */

#ifndef LANDSCAPESQUARE_HPP
#define LANDSCAPESQUARE_HPP
class LandscapeSquare
{

    private:
        double pumas; //needs to be >=0
        double hares; //needs to be >=0
        bool isLand; 
        
    public:
        LandscapeSquare(double pumas, double hares,bool isLand);
        
        void SetPumas(double pumas);
        void SetHares(double hares);
        
        void GetPumas();
        void GetHares();
            
};
#endif /* LANDSCAPESQUARE_HPP */

