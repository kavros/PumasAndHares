#ifndef LANDSCAPEGENERATOR_HPP
#define LANDSCAPEGENERATOR_HPP
#include <string>
using namespace std;

class LandscapeGenerator
{
private:
        int totalColumns;
        int totalRows;
        int landMatrix[2002][2002];
        float landPercentage;
        string outputFileName;
                
public:           
        //LandscapeGenerator(int width,int height, float land_percentage); 
        LandscapeGenerator(); 
        int GetRandomLandDistribution();
        int ParseCmdLine(int ac, char *av[]);
        int SetTotalRows(int totalRows);
        int SetTotalColumns(int totalColumns);
        int SetLandPercentage(float landPercentage);
        int SetOutputFileName(string fileName);
};

#endif
