/*
 * myWorld.h
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#ifndef MYWORLD_H_
#define MYWORLD_H_

#include "agent.h"
#include "object.h"
#include "basket.h"
#include "parameters.h"
#include <enki/PhysicalEngine.h>
#include <enki/robots/e-puck/EPuck.h>

class myWorld : public Enki::World
{
public:
	myWorld(double width, double height, const Enki::Color& wallsColor, unsigned maxSteps);
	void InitializeConfiguration();
	bool CheckOverlap(const double XCoordinate, const double YCoordinate, const double Radius);
	void UpdateAgentSpeed();
	bool runStep();
	void run();
	void gsl_seed_generator();
    /* Extend virtual funtion controlStep, where the dynamics of the world
     * are specified
     * void controlStep(double dt) */
private:
    unsigned maxSteps;
    unsigned c_step;
    std::vector< Agent* > myArrayOfAgents;
    std::vector< Object* > myArrayOfObjects;
    std::vector< Basket* > myArrayOfBasket;
    std::vector< ObjectInterface* > myArrayOfItems;
};



#endif /* MYWORLD_H_ */
