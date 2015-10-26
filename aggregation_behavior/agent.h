/*
 * agent.h
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#ifndef AGENT_H_
#define AGENT_H_

#include <enki/PhysicalEngine.h>
#include <enki/robots/e-puck/EPuck.h>

class Agent : public Enki::EPuck
{
public:
	Agent();
	~Agent();
	unsigned GetSensorReading();
	void SetSensorReading(unsigned sensorReading);
private:
	unsigned SensorReading;
};

#endif /* AGENT_H_ */
