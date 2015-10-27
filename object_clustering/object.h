/*
 * object.h
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include <enki/PhysicalEngine.h>
#include <enki/robots/e-puck/EPuck.h>

class Object
{
public:

	Object();
	const double& GetRadius() const;
	const double& GetXCoordinate() const;
	const double& GetYCoordinate() const;
	const double& GetAngle() const;
	const int& GetColor() const;

private:
	Enki::PhysicalObject * myEnkiPhysicalObject;

	double myRadius;
	int myColor;
};

#endif /* OBJECT_H_ */