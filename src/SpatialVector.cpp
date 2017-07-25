#ifndef SPATIAL_VECTOR
#define SPATIAL_VECTOR

#include <vector>
#include <cmath>

class SpatialVector {
 
private:
    
    static const unsigned int numDimensions = 2;
    std::vector<double> coords;
    
public:
    
    SpatialVector();
    SpatialVector(const SpatialVector& vec);
    
    double distance (const SpatialVector& vec) const;
    
    void turn (double angle);
    
    void enlarge (double coef);
    
    SpatialVector& operator+=(const SpatialVector& rhs);
    
    SpatialVector& operator=(const SpatialVector& rhs);
    
    void setCoord(double val, int idx);
    
};

SpatialVector::SpatialVector() : coords(numDimensions, 0.0) {}

SpatialVector::SpatialVector(const SpatialVector& vec) : coords(numDimensions, 0.0) {
    
    for(int i = 0; i < numDimensions; i++) {
        coords[i] = vec.coords[i];
    }
        
    
}

void SpatialVector::setCoord(double val, int idx) {
 
    if (idx < numDimensions) {
        coords[idx] = val;
    }
    
}

double SpatialVector::distance(const SpatialVector& vec) const {
    
    double sum = 0.0;
    
    for(int i = 0; i < numDimensions; i++) {
        sum += (vec.coords[i] - coords[i]) * (vec.coords[i] - coords[i]);
    }
    
    return sqrt(sum);
    
}

#endif