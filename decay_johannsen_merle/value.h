#pragma once
#include "constPara.h"
class Value
{
public:
	Value();
	Value(double A0, double t, double um);

	double calculatealpha();

	double getA() { return A; };
	double getA0() { return A0; };
	double gett() { return t; };
	double getum() { return um; };
	
private :

	double A;												// Concentration of 1,2‑dichlorobenzene on the outlet of the reactor				[mol/m^3]
	double alpha;											// Reaction yield																[%]
	double b;												// Compound factor combining construction and flow parameters of the reactor	[s^-1]
	double k;												// 	Reaction rate constant														[s^-1]
	double T;												// Temperature																	[K]
	
	// input variables with intervals
	double A0;												// Concentration of 1,2‑dichlorobenzene on the inlet to the reactor				[mol/m^3]
	double t;												// Temperature																	[°C]
	double um;												// Velocity of gas flow in the reactor											[m/s]

	double calculateT(double t);
	double calculateA(double A0, double k, double b);
	double calculatek(double t);
	double calculateb(double um);
	double calculatealpha(double A, double A0);
};

