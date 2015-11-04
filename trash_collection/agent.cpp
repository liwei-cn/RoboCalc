/*
 * agent.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */
#include "agent.h"

Agent::Agent(double InitialXCoordinate, double InitialYCoordinate, double InitialAngle):
myColor(RobotColor), myRadius(RobotRadius), myEnkiEpuck(new Enki::EPuck(Enki::EPuck::CAPABILITY_BASIC_SENSORS))
{
	mySensorReading = 0;
	basketSeenFlag = 0;
	canPickedFlag = 0;
	SetXCoordinate(InitialXCoordinate);
	SetYCoordinate(InitialYCoordinate);
	SetAngle(InitialAngle);
	SetLeftSpeed(0);
	SetRightSpeed(0);
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

double Agent::GetInfraredSensorValue(const int index)
{
	if (index == 0)
		return myEnkiEpuck->infraredSensor0.getValue();
	if (index == 1)
		return myEnkiEpuck->infraredSensor1.getValue();
	if (index == 2)
		return myEnkiEpuck->infraredSensor2.getValue();
	if (index == 3)
		return myEnkiEpuck->infraredSensor3.getValue();
	if (index == 4)
		return myEnkiEpuck->infraredSensor4.getValue();
	if (index == 5)
		return myEnkiEpuck->infraredSensor5.getValue();
	if (index == 6)
		return myEnkiEpuck->infraredSensor6.getValue();
	if (index == 7)
		return myEnkiEpuck->infraredSensor7.getValue();
	return 0;
}

void Agent::UpdateSensorValue(const std::vector<ObjectInterface*> ArrayOfItems)
{
	mySensorReading = WallColor;

	double MinimumSensingDistance = 1.0/0.0;

	const double ri = myRadius;
	const double xi = GetXCoordinate();
	const double yi = GetYCoordinate();
	const double ai = GetAngle();

	for (unsigned i = 0; i < ArrayOfItems.size(); i++)
	{
		if (ArrayOfItems[i] != this)
		{
			const double rj = ArrayOfItems[i]->GetRadius();
			const double xj = ArrayOfItems[i]->GetXCoordinate();
			const double yj = ArrayOfItems[i]->GetYCoordinate();

			const double side = -sin(ai)*(yi - yj) - cos(ai)*(xi - xj);
			const double dper = fabs(cos(ai)*(yi - yj) - sin(ai)*(xi - xj));

			if (side > 0 && dper < rj)
			{
				const double dij = sqrt(pow(xj - xi, 2.0) + pow(yj - yi, 2.0));
				const double dsense = sqrt(pow(dij, 2.0) - pow(dper, 2.0)) - sqrt(pow(rj, 2.0) - pow(dper, 2.0)) - ri;  //sensing distance

				if (dsense < MinimumSensingDistance)       //check the nearest item
				{
					MinimumSensingDistance = dsense;
					mySensorReading = ArrayOfItems[i]->GetColor();
				}
			}
		}
	}

}

/*
void Agent::UpdateSpeed()
{
	std::cout << mySensorReading << std::endl;
	myEnkiEpuck->leftSpeed = EPuckMaximumSpeed * AgentController[2*mySensorReading];
	myEnkiEpuck->rightSpeed = EPuckMaximumSpeed * AgentController[2*mySensorReading + 1];
} */

void Agent::UpdateWheelValue()
{
	std::cout << mySensorReading << " " << myEnkiEpuck->infraredSensor0.getValue() << " " << myEnkiEpuck->infraredSensor1.getValue() << std::endl;

	if (mySensorReading == 0 && canPickedFlag == 0)
	{
		myEnkiEpuck->leftSpeed = 0.08*EPuckMaximumSpeed;
		myEnkiEpuck->rightSpeed = -0.08*EPuckMaximumSpeed;
	}

	else if (mySensorReading == 1 && canPickedFlag == 0 && (myEnkiEpuck->infraredSensor0.getValue() < 100 || myEnkiEpuck->infraredSensor1.getValue() < 100))
	{
		myEnkiEpuck->leftSpeed = EPuckMaximumSpeed;
		myEnkiEpuck->rightSpeed = EPuckMaximumSpeed;
	}

//	else if (mySensorReading == 1 && (myEnkiEpuck->infraredSensor0.getValue() > 1000 || myEnkiEpuck->infraredSensor1.getValue() > 1000) && canPickedFlag == 0)
//	{
//		canPickedFlag = 1;
//		myEnkiEpuck->leftSpeed = -0.1*EPuckMaximumSpeed;
//		myEnkiEpuck->rightSpeed = 1.0*EPuckMaximumSpeed;
//	}
//
//	else if (canPickedFlag == 1 && mySensorReading == 3 && (myEnkiEpuck->infraredSensor0.getValue() < 100))
//	{
//		myEnkiEpuck->leftSpeed = EPuckMaximumSpeed;
//		myEnkiEpuck->rightSpeed = EPuckMaximumSpeed;
//	}
//
//	else if ((canPickedFlag == 1) && mySensorReading == 2 && (myEnkiEpuck->infraredSensor0.getValue() > 1000))
//	{
//		myEnkiEpuck->leftSpeed = 0;
//		myEnkiEpuck->rightSpeed = 0;
//		canPickedFlag = 0;
//	}

}