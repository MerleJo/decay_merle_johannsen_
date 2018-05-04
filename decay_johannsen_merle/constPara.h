#pragma once
class ConstPara
{
public:
	ConstPara();
	
	double getLcb() { return lcb; };
	double getLcc() { return lcc; };
	double getR() { return r; };

	int getNcl() { return ncl; };
	int getSmallA() { return a; };

	int getk0() { return k0; };
	int getE() { return bigE; };

private:
	
	double lcb;							// Length of catalyst’s block				[m]
	double lcc;							// Length of catalyst’s channel				[m]
	double r;							// Universal gas constant					[J/mol/K]
	int ncl;							// Number of catalyst layers of reactor bed
	int a;								// Specific surface of the catalyst			[m^2/m^3]

	int k0;								// Pre-exponential factor in Arrhenius Law
	int bigE;							// Activation energy						[J/mol]
};

