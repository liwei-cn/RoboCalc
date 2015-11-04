/*
 * basket.h
 *
 *  Created on: Nov 3, 2015
 *      Author: liwei
 */

#ifndef BASKET_H_
#define BASKET_H_

#include "ObjectInterface.h"
#include <enki/PhysicalEngine.h>
#include <enki/robots/e-puck/EPuck.h>

class Basket : public ObjectInterface
{
public:

	Basket(double InitialXCoordinate, double InitialYCoordinate);

	double GetRadius() const;
	double GetXCoordinate() const;
	double GetYCoordinate() const;
	double GetAngle() const;
	int GetColor() const;
	Enki::PhysicalObject* GetBasketPointer();

	void SetXCoordinate(const double XCoordinate);
	void SetYCoordinate(const double YCoordinate);

private:
	Enki::PhysicalObject* myEnkiPhysicalObject;
	double myRadius;
	int myColor;
};

#endif /* BASKET_H_ */
