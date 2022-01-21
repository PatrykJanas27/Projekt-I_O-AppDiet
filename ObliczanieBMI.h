#include <math.h>
#include <iostream>
#pragma once
class ObliczanieBMI
{
	double BMI;
public:
	double kalkulatorBMI(float weight, int height, std::string argBMI);
	double getBMI();
};