// an interface for a container for all the things in the universe
// overload the virtual functions with specific implementations

#include <vector>
#include <list>

class WorldMap {
 
public:
    
    virtual std::list<thing> getLocalPeers(double x, double y, double r);   // returns a list within a circle
                                                                            // Note: functions like look()
                                                                            // shall provide further 
                                                                            // object filtering depending on
                                                                            // line of sight etc.
    
    virtual void progressInTime(double t);                                  // iterates over all the things
                                                                            // in the universe and calls
                                                                            // their progress() functions
                                                                            // checks if the thing moves
                                                                            // to another quadrant etc
    
}

