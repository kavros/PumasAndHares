#ifndef LANDSCAPEGENERATOR_HPP
#define LANDSCAPEGENERATOR_HPP
#include <string>
using namespace std;

class LandscapeGenerator
{
        
public:           
        //LandscapeGenerator(int width,int height, float land_percentage); 
        LandscapeGenerator(); 
        int GetRandomLandDistribution();
        int GetRandomLandDistribution2();
        int ParseCmdLine(int ac, char *av[]);
        int SetTotalRows(int totalRows);
        int SetTotalColumns(int totalColumns);
        int SetLandPercentage(float landPercentage);
        int SetOutputFileName(string fileName);
        void WriteLandscapeToFile();
        

private:
        int totalColumns;
        int totalRows;
        int landMatrix[2000][2000];
        float landPercentage;
        string outputFileName;
        int GetRandomInRange(int lowerBound,int upperBound);

        
};  

#endif
