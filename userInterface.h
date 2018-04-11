#pragma once
#include <iostream>
#include <string>
#include "strategy.h"

using namespace std;


class userInterface
{
public:
	userInterface();
	~userInterface();

	void get_welcome() const;
	string get_fileLocation();

	string gameOrTournament() { return "Game (1) or Tournament?\n"; }

	void setIteration();
	int getIteration() { return iterationSelection; }


	void setUserSelection();
	int getUserSelection();

	void setStrategyNumber();
	int getStrategyNumber() { return strategyNumber; }

	void setGangNumber(int a) { gangNumber = a; }
	int getGangNumber() { return gangNumber; }

protected:

	int interfaceSelection;
	int iterationSelection;

	int strategyNumber;
	int gangNumber;

	string interfaceWelcome;
	string fileLocation;
};

