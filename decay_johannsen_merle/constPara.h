#pragma once
class ConstPara
{
public:
	ConstPara();
	
	double getLcb() { return Lcb; };
	double getLcc() { return Lcc; };
	double getR() { return R; };

	int getNcl() { return Ncl; };
	int geta() { return a; };

	int getk0() { return k0; };
	int getE() { return E; };

private:
	
	double Lcb;							// Length of catalyst’s block				[m]
	double Lcc;							// Length of catalyst’s channel				[m]
	double R;							// Universal gas constant					[J/mol/K]
	int Ncl;							// Number of catalyst layers of reactor bed
	int a;								// Specific surface of the catalyst			[m^2/m^3]

	int k0;								// Pre-exponential factor in Arrhenius Law
	int E;								// Activation energy						[J/mol]
};

