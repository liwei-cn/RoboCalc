/*
 * agent.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */
#include "agent.h"

Agent::Agent(): EPuck(0)
{
	SensorReading = 0;
}

Agent::~Agent()
{

}

unsigned Agent::GetSensorReading()
{
	return SensorReading;
}

void Agent::SetSensorReading(unsigned sensorReading)
{
	SensorReading = sensorReading;
}
