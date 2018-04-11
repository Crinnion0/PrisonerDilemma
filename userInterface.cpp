#include "userInterface.h"
#include <iostream>
#include <string>


using namespace std;

userInterface::userInterface()
{

}

userInterface::~userInterface()
{



}


void userInterface::get_welcome() const
{
	cout << "\n";
	cout << "Welcome to the Prisoner Dilemma Program.\n";
	cout << "----------------------------------------\n";
	cout << "---------------------------------\n";
	cout << "---------------------------\n";
	cout << "--------MENU--------\n";
	cout << "1. Load Strategies\n";
	cout << "2. Change Number of Iterations (Default 1)\n";
	cout << "3. Gangs\n";
	cout << "4. Exit\n";


}

string userInterface::get_fileLocation()
{

	cout << "Please Enter Strategy: ";
	cin >> fileLocation;
	return fileLocation;
}

void userInterface::setIteration()
{


	cout << "Input Number of Iterations: \n";
	cin >> iterationSelection;

}

void userInterface::setUserSelection()
{
	cin >> interfaceSelection;

}



int userInterface::getUserSelection()
{


	return interfaceSelection;
}

void userInterface::setStrategyNumber()
{

	cout << "How many strategies would you like to load?\n";
	cin >> strategyNumber;

}



