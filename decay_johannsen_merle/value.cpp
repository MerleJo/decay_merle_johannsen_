#include "value.h"
#include <math.h>


Value::Value() {													// needed to create an empty Value array in main

}

Value::Value(double A0, double t, double um)						// constructor to create Value object with previous calculated random numbers
{
	this->A0	= A0;
	this->t		= t;
	this->um	= um;
}

double Value::calculatealpha()										// public function
{																	// used to calculate alpha by using the other private function of the class
	k		= calculatek(t);
	b		= calculateb(um);
	A		= calculateA(A0, k, b);
	alpha	= calculatealpha(A, A0);

	return alpha;
}


double Value::calculateA(double A0, double k, double b)				// calculates A
{
	A = A0 * exp(-k / b);
	return A;
}

double Value::calculatek(double t)									// calculates k
{
	ConstPara help;

	T = calculateT(t);
	k = help.getk0() * exp(-help.getE() / (help.getR()*T));
	return k;

}

double Value::calculateb(double um)									// calculates b
{
	ConstPara help;

	b = (help.geta() * help.getLcc() * um) / 
		(4 * help.getLcb() * help.getNcl());
	return b;
}

double Value::calculateT(double t)									// converts temperature from Celsius to Kelvin
{
	T = t + 273.15;
	return T;
}

double Value::calculatealpha(double A, double A0)					// calculates alpha
{
	alpha = 1 - (A / A0);
	alpha = alpha * 100;											// turns alpha into a percentage values
	return alpha;
}


