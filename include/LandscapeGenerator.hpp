#include <string>
class LandscapeGenerator
{
	private:
		int width;
		int height;
		int landDistribution;
		int waterDistribution;
		std::string filePath ;

	public:
		LandscapeGenerator(int width,int height,int landDistribution,int waterDistribution);
		void GenerateData();	
};
