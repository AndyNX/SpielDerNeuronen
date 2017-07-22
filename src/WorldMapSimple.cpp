#ifndef WORLD_MAP_SIMPLE
#define WORLD_MAP_SIMPLE

#include <vector>
#include "WorldMap.h"

class WorldMapSimple : public WorldMap 
{
    
    std::vector<std::list<Thing> > map;
    
    std::list<Thing> getLocalPeers(const SpatialVector& pos, double r);
    
    void progressInTime(double t);
};

#endif