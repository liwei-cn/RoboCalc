#ifndef PARAMETERS_H_
#define PARAMETERS_H_

#include <iostream>
#include <fstream>
#include <sstream>

const int NumberOfAgent = 20;
const double EPuckMaximumSpeed = 12.8;
const double ControlStepSize = 0.1;
const int OversamplingRate = 10;
const int ArenaWidth = 200;
const double AgentController[4] = {-0.7, -1.0, 1.0, -1.0};

const double RobotRadius = 3.7;
const unsigned WallColor = 0;
const unsigned RobotColor = 1;

#endif
