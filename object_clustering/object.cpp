/*
 * object.cpp
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#include "object.h"

#define ObjectHeight 10.0
#define ObjectMass 35.0 // TODO
#define ObjectDryFrictionCoefficient 0.58 //TODO
#define ObjectViscousFrictionCoefficient 0.0 //TODO

Object::Object() : myRadius(ObjectRadius), myColor(ObjectColor), myEnkiPhysicalObject(new Enki::PhysicalObject)
{

}

const double& Object::GetRadius() const
{
	return myRadius;
}

const double& Object::GetXCoordinate() const
{
	return myEnkiPhysicalObject->pos.x;
}

const double& Object::GetYCoordinate() const
{
	return myEnkiPhysicalObject->pos.y;
}

const double& Object::GetAngle() const
{
	return myEnkiPhysicalObject->angle;
}

const int& Object::GetColor() const
{
	return myColor;
}