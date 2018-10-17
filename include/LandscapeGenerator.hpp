#include <string>
class LandscapeGenerator
{
	private:
		int width;
		int height;
                int up_limit;
                int land_matrix[3000][3000];
                int x_coord[2000*2000];
                int y_coord[2000*2000];
                float water_percentage;

	public:
            
		LandscapeGenerator(int width,int height, float water_percentage);
                
                int Get_landscape_width() const;
                
                int Get_landscape_height() const;
                
                float Get_landscape_water_percentage() const;
                
                int Get_random_land_distribution();
                

                
                int get_matrix();
};

