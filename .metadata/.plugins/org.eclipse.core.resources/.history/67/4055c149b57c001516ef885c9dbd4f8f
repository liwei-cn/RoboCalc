/*
 * agent.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */
#include "agent.h"

Agent::Agent(double InitialXCoordinate, double InitialYCoordinate, double InitialAngle) : myColor(RobotColor), myRadius(RobotRadius), myEnkiEpuck(new Enki::EPuck(0))
{
	mySensorReading = 0;
	SetXCoordinate(InitialXCoordinate);
	SetYCoordinate(InitialYCoordinate);
	SetAngle(InitialAngle);
}

unsigned Agent::GetSensorReading()
{
	return mySensorReading;
}

void Agent::SetSensorReading(unsigned sensorReading)
{
	mySensorReading = sensorReading;
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
