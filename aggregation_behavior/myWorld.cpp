/*
 * myWorld.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#include "myWorld.h"
#include "parameters.h"
using namespace Enki;

myWorld::myWorld(double width, double height, const Color& wallsColor, unsigned maxSteps) :
	Enki::World(width, height, wallsColor), maxSteps(maxSteps)
{
	c_step = 0;
	for (int i = 0; i < (NumberOfAgent); i++){
		agents.push_back(new Agent);  //sensor ability: none; noise: 0.05
		addObject(agents[i]);
	}
	InitializeConfiguration();
}

void myWorld::InitializeConfiguration()
{

	for(int i = 0; i < (NumberOfAgent); i++)
	{
		double xi;
		double yi;
		bool Overlap;

		do
		{
//			const double LengthOfSides = sqrt(AreaPerRobot*(NumberOfAgent+NumberOfModels));
			const double LengthOfSides = ArenaWidth;
			xi = LengthOfSides*gsl_rng_uniform(rng);
		    yi = LengthOfSides*gsl_rng_uniform(rng);
			Overlap = false;

			for (int j = 0; j < i; j ++ )
			{
				double xj = agents[j]->pos.x;
				double yj = agents[j]->pos.y;

				double dij = sqrt(pow(xi - xj, 2.0) + pow(yi - yj, 2.0));

				if (dij < (2.0 * EPuckRadius))
				{
					Overlap = true;
					break;
				}
			}

		} while(Overlap == true);

		agents[i]->pos.x = xi;
		agents[i]->pos.y = yi;
		agents[i]->angle = 2.0*M_PI*(gsl_rng_uniform(rng) - 0.5);
	}

}


void myWorld::UpdateAgentSpeed()
{
	for (int i = 0; i < (NumberOfAgent); i++){
		int SensorReading = ComputeSensorReading(i);
		if (SensorReading == 0){
			agents[i]->leftSpeed  = EPuckMaximumSpeed*AgentController[0];
			agents[i]->rightSpeed = EPuckMaximumSpeed*AgentController[1];
		}
		else if (SensorReading == 1){
			agents[i]->leftSpeed  = EPuckMaximumSpeed*AgentController[2];
			agents[i]->rightSpeed = EPuckMaximumSpeed*AgentController[3];
		}
	}
}

unsigned myWorld::ComputeSensorReading(const int &Index)
{
	agents[Index]->SetSensorReading(0);
	for(int j = 0; j < (NumberOfAgent); j ++ )
		if( j != Index )
		{
			const double xi = agents[Index]->pos.x;
			const double yi = agents[Index]->pos.y;
			const double ai = agents[Index]->angle;

			const double xj = agents[j]->pos.x;
			const double yj = agents[j]->pos.y;

			const double Side = -sin(ai)*(yi - yj) - cos(ai)*(xi - xj);
			const double PerpendicularDistance = fabs((yi - yj)*cos(ai) - (xi - xj)*sin(ai));

			if(Side > 0 && PerpendicularDistance <= EPuckRadius)
			{
				agents[Index]->SetSensorReading(1);
				break;
			}
		}

	return agents[Index]->GetSensorReading();
}

// returns true if the total simulation period has elapsed
bool myWorld::runStep()
{
	UpdateAgentSpeed();
	if (c_step != maxSteps)
	{
		step(ControlStepSize, OversamplingRate);
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