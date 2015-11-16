/*
 * myWorld.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#include "myWorld.h"
#include "parameters.h"
#include <sys/time.h>
#include <sys/stat.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
using namespace Enki;
gsl_rng *rng;

myWorld::myWorld(double width, double height, const Color& wallsColor, unsigned maxSteps) :
	Enki::World(width, height, wallsColor), maxSteps(maxSteps)
{
	c_step = 0;
	gsl_seed_generator();
	const double LengthOfSides = ArenaWidth;
	//initialize N (NumberOfAgent) agents with random position and orientation
	for (int i = 0; i < (NumberOfAgent); i++){

		double InitialXCoordinate;
		double InitialYCoordinate;
		do{
			InitialXCoordinate = LengthOfSides*gsl_rng_uniform(rng);
			InitialYCoordinate = LengthOfSides*gsl_rng_uniform(rng);

		} while (CheckOverlap(InitialXCoordinate, InitialYCoordinate, RobotRadius) == true);
		double InitialAngle = 2.0*M_PI*(gsl_rng_uniform(rng) - 0.5);

		myArrayOfAgents.push_back(new Agent(InitialXCoordinate, InitialYCoordinate, InitialAngle));
		addObject(myArrayOfAgents[i]->GetEpuckPointer());       //add an e-puck robot into the simulation world
		myArrayOfItems.push_back(myArrayOfAgents[i]);
	}

	gsl_rng_free(rng);
}

bool myWorld::CheckOverlap(const double XCoordinate, const double YCoordinate, const double Radius)
{

	bool Overlap = false;
	for(unsigned i = 0; i < myArrayOfItems.size(); i++)
	{
		double xj = myArrayOfItems[i]->GetXCoordinate();
		double yj = myArrayOfItems[i]->GetYCoordinate();

		double dij = sqrt(pow(XCoordinate - xj, 2.0) + pow(YCoordinate - yj, 2.0));

		if (dij < (Radius + myArrayOfItems[i]->GetRadius()))
		{
			Overlap = true;
			break;
		}

	}

	return Overlap;
}

void myWorld::UpdateAgentSpeed()
{
	for (unsigned i = 0; i < myArrayOfAgents.size(); i++){
		myArrayOfAgents[i]->UpdateSensorValue(myArrayOfItems);
		myArrayOfAgents[i]->UpdateSpeed();
	}
}

// returns true if the total simulation period has elapsed
bool myWorld::runStep()
{
	UpdateAgentSpeed();  //each robot (agent)'s speed is set in every control cycle (ControlStepSize)
	if (c_step != maxSteps)
	{
		step(ControlStepSize, OversamplingRate);  //the physics is updated at a rate of 10 (OversamplingRate) times per control cycle
		c_step++;
		return false;
	}
	return true;
}

void myWorld::run()
{
	bool finished = false;
	while (finished == false)
	{
		finished = runStep();
	}
}

void myWorld::gsl_seed_generator()
{
	unsigned long int Seed;
	struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv,&tz);
    Seed = tv.tv_sec * 1000000 + tv.tv_usec;
    rng = gsl_rng_alloc(gsl_rng_default);
    gsl_rng_set(rng, Seed);

    std::cout << "Seed: " << Seed << std::endl;
}
