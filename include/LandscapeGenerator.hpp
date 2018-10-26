#include <string>
class LandscapeGenerator
{
	private:
		int width;
		int height;
                int land_matrix[2002][2002];
                float land_percentage;

	public:
            
		LandscapeGenerator(int width,int height, float land_percentage);
                
                int Get_landscape_width() const;
                
                int Get_landscape_height() const;
                
                float Get_landscape_water_percentage() const;
                
                int Get_random_land_distribution();
                

                
                int get_matrix();
};

