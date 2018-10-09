#include <string>
class LandscapeGenerator
{
	private:
		int width;
		int height;
		int landDistribution;
		int waterDistribution;
		std::string filePath = "./data/";

	public:
		LandscapeGenerator(int width,int height,int landDistribution,int waterDistribution);
		void GenerateData();	
};
