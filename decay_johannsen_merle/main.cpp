//=============================================================================
//	APPLICATION:	decay_johannsen_merle
//	MODULE:			main
//	PURPOSE:
//	AUTHOR(S):		FT7673
//
//	01.05.2018 17:35:04	Created.
//=============================================================================
#pragma warning(disable : 4996)															// needs to be disabled for the localtime
#include <iostream>
#include <fstream>
#include <iomanip>
#include "value.h" 
using namespace std;
//-----------------------------------------------------------------------------
//	THE MAIN ENTRY POINT TO THE PROGRAM.
//
//	input:	argc	The number of arguments of the programme.
//			argv	The vector of arguments of the programme.
//	return:	The code of the reason the process was terminated for.
//			The value defaults to zero.
//-----------------------------------------------------------------------------
int main(int argc, char* argv[])
{
	int				seedValue;															// seed value for the random number generator
	int				savePlace;															// keeps the number of case which produces the maximum
	const int		size			= 10000;											// amount of tries

	double			saveA0[size];														// keeps the random numbers for A0
	double			savet[size];														// keeps the random numbers for t
	double			saveum[size];														// keeps the random numbers for um
		
	double			alpha;																// alpha of the current Value object
	double			alphaMax		= 0;												// maximum alpha of the simulation

	Value			valueArray[size];													// keeps all Value objects of the simulation
	
	time_t const	t				= time(0);											// keeps the current time


	ofstream ostr("decay_merle_johannsen.rlt", ofstream::out | ofstream::trunc);		// writes output to the file

	
	cout << "Please enter the seed value: ";
	cin >> seedValue;																	// reads seed value from the standard input
	cout << endl;

	srand(seedValue);																	// sets the seed value

	for (int i = 0; i < size; i++) {													// creates the random numbers
		saveA0[i]	= fmod(rand(), (1.65*pow(10, -0.5))- (1.25*pow(10, -0.5)))			
						+ (1.25*pow(10, -0.5));
		savet[i]	= rand() % (295-175) + 175;
		saveum[i]	= fmod(rand(), (5.38 - 1.12)) + (1.12);
	}
	
	if (ostr.is_open()) {
		for (int i = 0; i < size; i++) {
			valueArray[i] = Value(saveA0[i], savet[i], saveum[i]);						// create a Value object and saves it in the array

			alpha = valueArray[i].calculatealpha();										// calculates alpha for the certain Value object

			if (alphaMax < alpha) {														// checks if this alpha is bigger than the ones before
				alphaMax = alpha;														// if yes: sets it as the current alpha maximum
				savePlace = i;
			}
		}
										
																						// writes the file
		ostr << "Merle Johannsen" << endl;
		ostr << "C++ Programming Language Course" << endl;
		ostr << "Value of seed: "  << right << setw(75) << seedValue << endl;
		ostr << "Numbers of tries: " << right << setw(72) << size << endl << endl << endl;
		
 		ostr << "Number of the case: "  << right << setw(70)<< savePlace << endl;
		ostr << "Concentration of 1,2 dichlorobenzene on the inlet to the reactor: " << right << setw(24) << valueArray[savePlace].getA0() << " mol/m"  << char(179)<<endl;
		ostr << "Concentration of 1,2 dichlorobenzene on the outlet of the reactor: " << right << setw(23) << valueArray[savePlace].getA() << " mol/m" << char(179) << endl;
		ostr << "Temperature of reaction: " << right << setw(65) << valueArray[savePlace].gett() << " °C" << endl;
		ostr << "Mean linear velocity of gas flow in the reactor: " << right << setw(41)<< valueArray[savePlace].getum() << " m/s" << endl;
		ostr << "Maximum reaction yield: " << right << setw(66)<< alphaMax << " %"<< endl << endl << endl;

		ostr << put_time(localtime(&t), "%d.%m.%G %H:%M:%S") << endl;
		
		
		cout << "Simulation Process has been completed." << endl;
		ostr.close();
	}
	else {
		perror("File is not open");
	}
	return 0;
}
