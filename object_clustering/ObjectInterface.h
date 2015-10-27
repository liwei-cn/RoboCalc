/*
 * ObjectInterface.h
 *
 *  Created on: Oct 26, 2015
 *      Author: liwei
 */

#ifndef OBJECTINTERFACE_H_
#define OBJECTINTERFACE_H_

class ObjectInterface
{
public:
	virtual ~ObjectInterface() {};

	virtual double GetRadius() const = 0;
	virtual double GetXCoordinate() const = 0;
	virtual double GetYCoordinate() const = 0;
	virtual double GetAngle() const = 0;
	virtual int GetColor() const = 0;
};


#endif /* OBJECTINTERFACE_H_ */
