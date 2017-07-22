
#include <vector>
#include "worldMap.h"
#include <list>

class thing
{
protected:
	std::vector<double> position;
	//std::vector<double> orientation;
	double energy;
	double maxEnergy; // maybe things should split into children beyond a certain energy
	double weight;
	double maxSpeed;
	// double strength; // could also be a function s(health), with different objects having different maxHealth
	std::list<thing> baggage;
	bool isActive;

	// maybe all get Functions with some random uncertainty
	double getPosition();
	double getWeight();
	double getEnergy();

	virtual void progress();

	virtual void move();

	virtual void look();
	list<thing> sense(const worldMap& map)
	{
		look();
	}

	virtual void plan();
	virtual void act();
	// amount of drained energy should maybe be scale down by amount *= (own.energy - target.energy)/target.energy
	// , but not more than factor 1.0
	virtual void drainEnergy(thing& target);	// = eat()
	virtual void transferEnergy(thing& target);	// = throw()
	virtual void pickUp(thing& target);
	virtual void drop(thing& target);
}


