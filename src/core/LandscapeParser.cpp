/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LandscapeParser.cpp
 * Author: alex
 * 
 * Created on October 9, 2018, 6:40 PM
 */
#include <iostream>
#include <fstream>

#include "LandscapeParser.hpp"

using namespace std;

LandscapeParser::LandscapeParser() {
	int rows, colms;

	/* Read height=rows and widht=colms from the landscape file  */
	ifstream myfile;
	myfile.open("../../Data.dat", ios::in);
	myfile >> rows >> colms;
	
	/* Allocate memory address for the matrix  */
	int** matrix = new int*[rows];
	for (int i = 0; i < rows; i++){
		matrix[i] = new int[colms];
	}
	
myfile.close();	
}

LandscapeParser::LandscapeParser(const LandscapeParser& orig) {
}

LandscapeParser::~LandscapeParser() {
}

