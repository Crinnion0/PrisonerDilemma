#include "strategy.h"
#include <iostream>
#include <string>
#include "codeExecute.h"
#include "userInterface.h"
#include "gangs.h"

using namespace std;

class tournament
{
public:
	tournament(userInterface welcome);
	~tournament();

	friend map<string, double> operator+=(map<string, double>& a, map<string, double>& b);

	void initialiseStrategies(userInterface welcome);
	void setFileLocation();


	void runTournament(vector<strategy> a);
	void runTournament(vector<strategy> a, vector<strategy> b);



protected:

	int totalStrategies;

	map<string, double> totalScores;
	string fileLocation;

	vector<strategy> strategies;

	vector<strategy> gang;



};

