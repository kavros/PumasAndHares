#include <string>
class GenerateLandscape
{
	private:
		int width;
		int height;
		int landDistribution;
		int waterDistribution;
		std::string filePath = "./data/";

	public:
		GenerateLandscape(int width,int height,int landDistribution,int waterDistribution);
		void GenerateData();	
};
