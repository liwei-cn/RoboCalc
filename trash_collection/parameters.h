#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include <iostream>
#include <fstream>
#include <sstream>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>

using namespace std;

const int NumberOfAgent = 1;
const int NumberOfObject = 1;
const int NumberOfBasket = 1;
const double EPuckMaximumSpeed = 12.8;
const double ControlStepSize = 0.1;
const int MaximumStepSize = 10000;
const int OversamplingRate = 10;
const int ArenaWidth = 100;
const double AgentController[8] = {0.08, -0.08, 1.0, 1.0, 0.1, 0.5,1.0,1.0};

const double RobotRadius = 3.7;
const double ObjectRadius = 5.0;
const double BasketRadius = 10.0;

const double CameraRange = 140.0;
const double CameraFieldOfView = 3.1415926/3;

const unsigned WallColor = 0;
const unsigned ObjectColor = 1;
const unsigned RobotColor = 2;
const unsigned BasketColor = 3;

const double ObjectHeight = 10.0;
const double ObjectMass = 350000.0; // TODO
const double ObjectDryFrictionCoefficient = 0.58; //TODO
const double ObjectViscousFrictionCoefficient = 0.35; //TODO

const double BasketHeight = 10.0;
const double BasketMass = 350000.0; // TODO
const double BasketDryFrictionCoefficient = 0.58; //TODO
const double BasketViscousFrictionCoefficient = 0.35; //TODO

#endif
