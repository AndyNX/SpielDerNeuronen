#ifndef SPATIAL_VECTOR
#define SPATIAL_VECTOR

#include <vector>

class SpatialVector {
 
private:
    
    static const unsigned int numDimensions = 2;
    std::vector<double> coords;
    
public:
    
    SpatialVector();
    
    double distance (const SpatialVector& vec);
    
    void turn (double angle);
    
    void enlarge (double coef);
    
    SpatialVector& operator+=(const SpatialVector& rhs);
    
};

#endif