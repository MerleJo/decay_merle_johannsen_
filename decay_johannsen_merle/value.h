#pragma once
#include "constPara.h"
class Value
{
public:
	Value();
	Value(double bigA0, double t, double um);

	double calculateAlpha();

	double getA() { return bigA; };
	double getA0() { return bigA0; };
	double getSmallT() { return t; };
	double getUm() { return um; };
	
private :

	double bigA;											// Concentration of 1,2‑dichlorobenzene on the outlet of the reactor				[mol/m^3]
	double alpha;											// Reaction yield																[%]
	double b;												// Compound factor combining construction and flow parameters of the reactor	[s^-1]
	double k;												// 	Reaction rate constant														[s^-1]
	double bigT;											// Temperature																	[K]
	
	// input variables with intervals
	double bigA0;											// Concentration of 1,2‑dichlorobenzene on the inlet to the reactor				[mol/m^3]
	double t;												// Temperature																	[°C]
	double um;												// Velocity of gas flow in the reactor											[m/s]

	double calculateBigT(double t);
	double calculateBigA(double bigA0, double k, double b);
	double calculateK(double t);
	double calculateB(double um);
	double calculateAlpha(double bigA, double bigA0);
};

