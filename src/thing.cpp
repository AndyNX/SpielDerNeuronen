
#include <vector>
#include "worldMap.h"
#include <list>

// hello

class thing
{
protected:
	std::vector<double> position;
	std::vector<double> velocity;	// has to be reduced in every timestep by friction
	//std::vector<double> acceleration;
	//std::vector<double> orientation;
	double health; // should be reduced in every timestep by a small amount
	double maxHealth; // maybe things should split into children beyond a certain energy
	double mass;
	
	double maxSpeed;
	// double strength; // could also be a function s(health), with different objects having different maxHealth
	std::list<thing> baggage;
	bool isFree;

	// maybe all get Functions with some random uncertainty
	double getPosition();
	double getMass();
	double getEnergy();

	virtual void progress();

	virtual void move();

	virtual void look();
	std::list<thing> sense(const worldMap& map)
	{
		look();
	}

	virtual std::vector<double> plan(const std::list<thing>& environment);
	virtual void act(std::vector<double> plan);
	// amount of drained energy should maybe be scale down by amount *= (own.energy - target.energy)/target.energy
	// , but not more than factor 1.0
	virtual void transferHealth(thing& target, double amount);	// = eat(), heal()
	virtual void transferEnergy(thing& target, double amount);	// = throw()
	virtual void pickUp(thing& target);
	virtual void drop(thing& target);
}


