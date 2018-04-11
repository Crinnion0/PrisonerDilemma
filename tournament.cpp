#include "tournament.h"



tournament::tournament(userInterface welcome)
{


	initialiseStrategies(welcome);

}


tournament::~tournament()
{
}




void tournament::initialiseStrategies(userInterface welcome)
{

	bool loop = false;

	//Run interface 
	while (loop != true) {

		welcome.get_welcome();
		welcome.setUserSelection();



		if (welcome.getUserSelection() == 1) {

			welcome.setStrategyNumber();

			for (int i = 0; i < welcome.getStrategyNumber(); i++) {

				fileLocation = welcome.get_fileLocation();
				strategies.push_back(strategy(fileLocation, welcome.getIteration()));
				totalStrategies++;


			}

			runTournament(strategies);



			cout << "Would you like to view statistics? (Y or N) \n";
			string temp;
			cin >> temp;
			if (temp == "Y", "y") {


				for (auto it = totalScores.begin(); it != totalScores.cend(); it++) {
					cout << it->first << " : Total Years: " << it->second << "\n";


				}

				if (temp == "N", "n")
				{
					temp = "";
				}
				else { cout << "Invalid Response\n"; }

				cout << "Would you like to return to the menu? (Y or N)\n";
				cin >> temp;


				if (temp == "Y", "y") {
					initialiseStrategies(welcome);


				}
				if (temp == "N")  std::exit(0);


			}
		}
		else if (welcome.getUserSelection() == 2) {
			welcome.setIteration();

		}

		else if (welcome.getUserSelection() == 3) {


			cout << "Enter Strategies for Gang 1\n";
			for (int i = 1; i < 6; i++) {

				cout << "Number" << i << " :\n";
				fileLocation = welcome.get_fileLocation();
				gang.push_back(strategy(fileLocation, welcome.getIteration()));
			}

			gangs testGang(gang);

			cout << "Enter Strategies for Gang 2\n";

			for (int i = 1; i < 6; i++) {

				cout << "Number" << i << " :\n";
				fileLocation = welcome.get_fileLocation();
				gang.push_back(strategy(fileLocation, welcome.getIteration()));

			}


			gangs testGang2(gang);

			runTournament(testGang.getGang(), testGang2.getGang());



			cout << "Would you like to view statistics? (Y or N) \n";
			string temp;
			cin >> temp;
			if (temp == "Y", "y") {


				for (auto it = totalScores.begin(); it != totalScores.cend(); it++) {
					cout << it->first << " : Total Years: " << it->second << "\n";


				}

				if (temp == "N", "n")
				{
					temp = "";
				}
				else { cout << "Invalid Response\n"; }

				cout << "Would you like to return to the menu? (Y or N)\n";
				cin >> temp;


				if (temp == "Y", "y") {
					initialiseStrategies(welcome);


				}
				if (temp == "N")  std::exit(0);
			}



		}
		else if (welcome.getUserSelection() == 4) {

			std::exit(0);

		}
		else {
			cout << "Invalid Selection\n";
			cout << "Re-Enter Selection: \n";

		}



	}
}




void tournament::setFileLocation()
{
}

void tournament::runTournament(vector<strategy> a)
{

	//If j = i + 1 the strategy won't compete against itself

	for (int i = 0; i != a.size(); i++) {
		for (int j = i; j != a.size(); j++) {
			codeExecute tournamentRun(a[i], a[j]);



			totalScores += tournamentRun.returnAllResults();

		}
	}



}
void tournament::runTournament(vector<strategy> a, vector<strategy> b)
{

	//If j = i + 1 the strategy won't compete against itself

	for (int i = 0; i != a.size(); i++) {
		for (int j = i; j != a.size(); j++) {
			codeExecute tournamentRun(a[i], b[j]);



			totalScores += tournamentRun.returnAllResults();

		}
	}



}



map<string, double> operator+=(map<string, double>& a, map<string, double>& b)
{
	for (auto& i : b) {

		a.insert(i);

	}
	return a;
}
