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
    double angle(const SpatialVector& vec) const ;
    
    void turn (double angle);
    
    void enlarge (double coef);
    
    SpatialVector& operator+=(const SpatialVector& rhs);
    SpatialVector& operator-=(const SpatialVector& rhs);
    
    SpatialVector& operator=(const SpatialVector& rhs);
    
    void setCoord(double val, unsigned int idx);
    
};

SpatialVector::SpatialVector() : coords(numDimensions, 0.0) {}

SpatialVector::SpatialVector(const SpatialVector& vec) : coords(numDimensions, 0.0) {
    
    for(unsigned int i = 0; i < numDimensions; i++) {
        coords[i] = vec.coords[i];
    }
        
    
}

void SpatialVector::setCoord(double val, unsigned int idx) {
 
    if (idx < numDimensions) {
        coords[idx] = val;
    }
    
}

double SpatialVector::distance(const SpatialVector& vec) const {
    
    double sum = 0.0;
    
    for(unsigned int i = 0; i < numDimensions; i++) {
        sum += (vec.coords[i] - coords[i]) * (vec.coords[i] - coords[i]);
    }
    
    return sqrt(sum);
    
}


double SpatialVector::angle(const SpatialVector& vec) const {
    
    double length = 0.0;
    double vec_length = 0.0;
    double scalar_prod = 0.0;
    
    for(unsigned int i = 0; i < numDimensions; i++) {
        vec_length		+= (vec.coords[i]) * (vec.coords[i]);
        length			+= (coords[i]) * (coords[i]);
        scalar_prod		+= (coords[i]) * (vec.coords[i]);
    }
    
    double cos_angle = scalar_prod / sqrt (length) / sqrt(vec_length);
    
    return acos(cos_angle);
    
    
}

SpatialVector& SpatialVector::operator+=(const SpatialVector& rhs) {
	
	for (unsigned i = 0; i < numDimensions; i++) {
		coords[i] += rhs.coords[i];
	}
	
	return *this;
	
}

SpatialVector& SpatialVector::operator-=(const SpatialVector& rhs) {
	
	for (unsigned i = 0; i < numDimensions; i++) {
		coords[i] -= rhs.coords[i];
	}
	
	return *this;
	
}

#endif
