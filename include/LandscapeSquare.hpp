/**
 * A class that represent a square inside the landscape grid.
 * We use this class in order to create our 2d array.
 * Every position of our landscape has a instance of this class.
 */

#ifndef LANDSCAPESQUARE_HPP
#define LANDSCAPESQUARE_HPP

#include <string>
class LandscapeSquare 
{
public:
    /**
     * Constructor  of LandscapeSquare.
     */
    LandscapeSquare();
    /**
     * Set value of water true or false.
     * @param value
     */
    void SetIsWater(bool value);
    /**
     * Set number of pumas.
     * @param pumas
     */
    void SetPumas(double pumas);
    /**
     * Sets number of hares.
     * @param hares
     */
    void SetHares(double hares);
    
    /**
     * Return the number of pumas.
     * @return 
     */
    double GetPumas();
    /**
     * Return the number of hares.
     * @return 
     */
    double GetHares();
    /**
     * Return true if square is water else return false.
     * @return 
     */
    bool GetIsWater();
    /**
     * Destructor of LandscapeSquare.
     */
    virtual ~LandscapeSquare();
private:
    bool   isWater;
    double pumas;
    double hares;
    
  
};

#endif /* LANDSCAPESQUARE_HPP */

