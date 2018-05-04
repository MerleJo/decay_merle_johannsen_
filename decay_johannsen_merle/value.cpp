#include "value.h"
#include <math.h>


Value::Value() {													// needed to create an empty Value array in main

}

Value::Value(double bigA0, double t, double um)						// constructor to create Value object with previous calculated random numbers
{
	this->bigA0	= bigA0;
	this->t		= t;
	this->um	= um;
}

double Value::calculateAlpha()										// public function
{																	// used to calculate alpha by using the other private function of the class
	k		= calculateK(t);
	b		= calculateB(um);
	bigA	= calculateBigA(bigA0, k, b);
	alpha	= calculateAlpha(bigA, bigA0);

	return alpha;
}


double Value::calculateBigA(double bigA0, double k, double b)			// calculates A
{
	bigA = bigA0 * exp(-k / b);
	return bigA;
}

double Value::calculateK(double t)									// calculates k
{
	ConstPara help;

	bigT = calculateBigT(t);
	k = help.getk0() * exp(-help.getE() / (help.getR()*bigT));
	return k;

}

double Value::calculateB(double um)									// calculates b
{
	ConstPara help;

	b = (help.getSmallA() * help.getLcc() * um) / 
		(4 * help.getLcb() * help.getNcl());
	return b;
}

double Value::calculateBigT(double t)									// converts temperature from Celsius to Kelvin
{
	bigT = t + 273.15;
	return bigT;
}

double Value::calculateAlpha(double bigA, double bigA0)					// calculates alpha
{
	alpha = 1 - (bigA / bigA0);
	alpha = alpha * 100;											// turns alpha into a percentage values
	return alpha;
}


