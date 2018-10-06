/* 
 * File:   ParameterParser.cpp
 * Author: amced
 * 
 * Created on October 5, 2018, 11:20 PM
 */

#include "ParameterParser.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
ParameterParser::ParameterParser(string configFile) {
  ifstream ifs;
  try
  {
    ifs.open(configFile);
    string tmpstring;
    while (getline(ifs, tmpstring))
    {
      if (tmpstring.at(0) != this->commentsuffix.at(0)) //Allow comments in the config file, starting with number sign.
      {
        istringstream ss (tmpstring);
        string element;
        vector<string> param_v;
        while (getline(ss,element,':'))
        {
          //cout << element << endl; //Verbose output for debugging.
          param_v.push_back(element);
        }
        if (this->dict.count(param_v[0]) != 0) //Avoid duplicates and overwriting.
        {
          cerr << "Duplicate configuration option: " << param_v[0] << endl;
          break;
        }
        else if (!IsDouble(param_v[1]))
        {
          cerr << "Value for " << param_v[0] << " is of incorrect type." << endl;
          break;
        }
        else
        {
          this->dict[param_v[0]] = stod(param_v[1]);
          //cout << "Successfully read parameter " << param_v[0] << " as : " << param_v[1] << endl; //Verbose output for debugging.
        }
      }
    }
  }
  catch(...)
  {
    cerr << "Error opening configuration file.";
  }
  ifs.close();
}

//Hacky way to typecheck that the input is a double.
bool ParameterParser::IsDouble(std::string value)
{
    stringstream iss(value);
    double d;
    return iss >> d >> std::ws && iss.eof();
}

ParameterParser::ParameterParser(const ParameterParser& orig) {
}

ParameterParser::~ParameterParser() {
}

