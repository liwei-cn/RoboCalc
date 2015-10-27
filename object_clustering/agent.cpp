/*
 * agent.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */
#include "agent.h"

Agent::Agent() : myColor(RobotColor), myRadius(RobotRadius), myEnkiEpuck(new Enki::EPuck(0))
{
	SensorReading = 0;
}

unsigned Agent::GetSensorReading()
{
	return SensorReading;
}

void Agent::SetSensorReading(unsigned sensorReading)
{
	SensorReading = sensorReading;
}

double Agent::GetXCoordinate() const
{
	return myEnkiEpuck->pos.x;
}


double Agent::GetYCoordinate() const
{
	return myEnkiEpuck->pos.y;
}

double Agent::GetAngle() const
{
	return myEnkiEpuck->angle;
}

int Agent::GetColor() const
{
	return myColor;
}

double Agent::GetRadius() const
{
	return myRadius;
}

void Agent::SetXCoordinate(double XCoordinate)
{
	 myEnkiEpuck->pos.x = XCoordinate;
}


void Agent::SetYCoordinate(double YCoordinate)
{
	 myEnkiEpuck->pos.y = YCoordinate;
}

void Agent::SetAngle(double Angle)
{
	 myEnkiEpuck->angle = Angle;
}

void Agent::SetLeftSpeed(double leftSpeed)
{
	 myEnkiEpuck->leftSpeed = leftSpeed;
}

void Agent::SetRightSpeed(double rightSpeed)
{
	 myEnkiEpuck->rightSpeed = rightSpeed;
}

Enki::EPuck* Agent::GetEpuckPointer()
{
	return myEnkiEpuck;
}