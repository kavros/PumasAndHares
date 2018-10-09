/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeGenerator.cpp
 * Author: alex
 *
 * Created on October 9, 2018, 10:17 AM
 */

#include <cstdlib>
#include "../../include/LandscapeGenerator.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    LandscapeGenerator landscape(50,50,40,60);
    landscape.GenerateData();
    return 0;
}
