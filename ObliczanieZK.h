#include <math.h>
#include <iostream>

#pragma once
class ObliczanieZK
{
	double ZK;
public:
	void kalkulatorZK(float weight, int height, int age, std::string gender, std::string argZK);
	double getZK();
};