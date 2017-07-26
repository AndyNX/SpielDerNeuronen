// an interface for a container for all the things in the universe
// overload the virtual functions with specific implementations



#ifndef WORLD_MAP
#define WORLD_MAP

#include <vector>
#include <list>
#include "SpatialVector.cpp"
#include "Thing.cpp"

class WorldMap {
 
public:
    
    virtual std::list<Thing> getLocalPeers(const SpatialVector&, double, const SpatialVector&, double) = 0;       	// returns a list within a sector
    
																													// Note: functions like look()
																													// shall provide further 
																													// object filtering depending on
																													// line of sight etc.
    
    virtual void progressInTime(double) = 0;                                // iterates over all the things
                                                                            // in the universe and calls
                                                                            // their progress() functions
                                                                            // checks if the thing moves
                                                                            // to another quadrant etc
    
};

#endif

