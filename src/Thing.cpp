#ifndef THING
#define THING

#include <vector>
#include "WorldMap.h"
#include <list>
#include "SpatialVector.cpp"

class WorldMap; //forward declaration

class Thing
{
protected:
	SpatialVector position;
	SpatialVector velocity;	// has to be reduced in every timestep by friction
	//std::vector<double> acceleration;
	//std::vector<double> orientation;
	double health; // should be reduced in every timestep by a small amount
	double maxHealth; // maybe Things should split into children beyond a certain energy
	double mass;
	
	double maxSpeed;
	// double strength; // could also be a function s(health), with different objects having different maxHealth
	std::list<Thing> baggage;
	bool isFree;

	// maybe all get Functions with some random uncertainty
	double getPosition();
	double getMass();
	double getEnergy();

	virtual void progress();

	virtual void move();

	virtual void look();
	std::list<Thing> sense(const WorldMap* map)
	{
		look();
	}

	virtual std::vector<double> plan(const std::list<Thing>& environment);
	virtual void act(std::vector<double> plan);
	// amount of drained energy should maybe be scale down by amount *= (own.energy - target.energy)/target.energy
	// , but not more than factor 1.0
	virtual void transferHealth(Thing& target, double amount);	// = eat(), heal()
	virtual void transferEnergy(Thing& target, double amount);	// = throw()
	virtual void pickUp(Thing& target);
	virtual void drop(Thing& target);
        
public:
        const SpatialVector& getExactPosition() const; 
};

const SpatialVector& Thing::getExactPosition() const {
 
    return position;
    
}

#endif
