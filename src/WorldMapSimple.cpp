#ifndef WORLD_MAP_SIMPLE
#define WORLD_MAP_SIMPLE

#include <vector>
#include "WorldMap.h"

class WorldMapSimple : public WorldMap 
{
    
    std::vector<Thing> map;
    
    std::list<Thing> getLocalPeers(const SpatialVector& pos, double r, const SpatialVector& dir, double a);
    
    void progressInTime(double t);
};

//returns all the objects within a sector
std::list<Thing> WorldMapSimple::getLocalPeers(const SpatialVector& pos, double r, const SpatialVector& dir, double a) {
    
    std::list<Thing> ret;
    
    // iterate over all the objects
    for (std::vector<Thing>::iterator it = map.begin(); it != map.end(); it++) {
        
        // process those within the radius
        SpatialVector thingPos(it->getExactPosition());
        
        if (pos.distance(thingPos) < r) {             
			
			// evaluate the angle between line of sight (dir) and line towards thing
			SpatialVector thingDir(thingPos);
			thingDir -= pos;
			
			if (dir.angle(thingDir) < a) {
				ret.push_back(*it);
			}	
			
			
		}
        
    }
    
    return ret;
    
}

#endif
