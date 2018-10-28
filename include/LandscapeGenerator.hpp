#include <string>
class LandscapeGenerator
{
	private:
		int width;
		int height;
                int landMatrix[2002][2002];
                float landPercentage;

	public:           
		LandscapeGenerator(int width,int height, float land_percentage);
                
                int GetRandomLandDistribution();
};

