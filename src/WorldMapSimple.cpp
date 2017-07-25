#ifndef WORLD_MAP_SIMPLE
#define WORLD_MAP_SIMPLE

#include <vector>
#include "WorldMap.h"

class WorldMapSimple : public WorldMap 
{
    
    std::vector<Thing> map;
    
    std::list<Thing> getLocalPeers(const SpatialVector& pos, double r);
    
    void progressInTime(double t);
};

std::list<Thing> WorldMapSimple::getLocalPeers(const SpatialVector& pos, double r) {
    
    std::list<Thing> ret;
    
    // iterate over all the objects and return those within the radius
    for (std::vector<Thing>::iterator it = map.begin(); it != map.end(); it++) {
        
        if (pos.distance(it->getExactPosition()) < r)             
                ret.push_back(*it);
        
    }
    
    return ret;
    
}

#endif