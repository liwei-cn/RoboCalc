/*
 * agent.h
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#ifndef AGENT_H_
#define AGENT_H_

#include "ObjectInterface.h"
#include "parameters.h"
#include <enki/PhysicalEngine.h>
#include <enki/robots/e-puck/EPuck.h>

class Agent : public ObjectInterface
{
public:
	Agent();
	unsigned GetSensorReading();
	void SetSensorReading(unsigned sensorReading);

	virtual double GetXCoordinate() const;
	virtual double GetYCoordinate() const;
	virtual double GetAngle() const;
	virtual double GetRadius() const;
	virtual int GetColor() const;

	void SetXCoordinate(double XCoordinate);
	void SetYCoordinate(double YCoordinate);
	void SetAngle(double Angle);
	void SetLeftSpeed(double leftSpeed);
	void SetRightSpeed(double rightSpeed);

	Enki::EPuck* GetEpuckPointer();
private:
	unsigned SensorReading, myColor;
	double myRadius;
	Enki::EPuck* myEnkiEpuck;
};

#endif /* AGENT_H_ */
