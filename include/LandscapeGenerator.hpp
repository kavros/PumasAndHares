#ifndef LANDSCAPEGENERATOR_HPP
#define LANDSCAPEGENERATOR_HPP
#include <string>
using namespace std;

class LandscapeGenerator
{
        
public:           
        //LandscapeGenerator(int width,int height, float land_percentage); 
        LandscapeGenerator(); 
        int GetRandomLandDistribution2();
        int ParseCmdLine(int ac, char *av[]);
        void SetTotalRows(int totalRows);
        void SetTotalColumns(int totalColumns);
        void SetLandPercentage(float landPercentage);
        void SetOutputFileName(string fileName);
        void WriteLandscapeToFile();
        void GetRandomLandDistribution();


private:
        int totalColumns;
        int totalRows;
        int landMatrix[2002][2002];
        float landPercentage;
        string outputFileName;
        int GetRandomInRange(int lowerBound,int upperBound);
        void InitLandscapeWithWater();
        void GenerateRandomLand();
        int NormalizeLandscape();
        void RemoveExtraLand(int countExtraLand);
        void SaveLandscape();
        int CountNeighbours(int i,int j);

};  

#endif
