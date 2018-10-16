/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   OutputGenerator.cpp
 * Author: alex
 *
 * Created on October 9, 2018, 6:51 PM
 */

#include <cstdlib>
#include "../../include/OutputGenerator.hpp"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    OutputGenerator output;
    Landscape landscape;
    output.CreatePPMFile(landscape);
    return 0;
}

