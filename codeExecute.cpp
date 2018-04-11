#include "codeExecute.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


//Constructor for just prisoner

codeExecute::codeExecute(strategy &a, strategy &b)
{
	srand(time(NULL));


	
	for (int i = 0; i != a.getIterations(); i++) {

		executeIterations++;
		betrayW = false;
		betrayX = false;
		betrayY = false;
		betrayZ = false;
		betrayLastRoundA = false;
		betrayLastRoundB = false;



		keywordOperation(a, b);
		betrayLastRoundA = calcExpression(a, b, expressionLeft, expressionRight, expressionOperator);
		betrayLastRoundB = calcExpression(b, a, expressionLeft, expressionRight, expressionOperator);
		incrementVariables(a, b);




	}

	writeResults(a, b);


}


//Constructor for Gangs

codeExecute::codeExecute(vector<strategy>& purple, vector<strategy>& magenta)
{
	srand(time(NULL));


	int purpleTotalBetray = 0;
	int magentaTotalBetray = 0;

	for (int i = 0; i != purple[0].getIterations(); i++) {
		for (int j = 0; j != 5; j++) {


			executeIterations++;
			betrayW = false;
			betrayX = false;
			betrayY = false;
			betrayZ = false;
			betrayLastRoundA = false;
			betrayLastRoundB = false;

			keywordOperation(purple[j], magenta[j]);
			purpleTotalBetray += calcExpression(purple[j], magenta[j], expressionLeft, expressionRight, expressionOperator);
			keywordOperation(magenta[j], purple[j]);
			magentaTotalBetray += calcExpression(magenta[j], purple[j], expressionLeft, expressionRight, expressionOperator);

			incrementGangVariables(purple, magenta, purpleTotalBetray, magentaTotalBetray);
			writeResults(purple[j], magenta[j]);

		}



	}





}


codeExecute::~codeExecute()
{
}



bool codeExecute::calcExpression(strategy a, strategy b, vector<string> expressionLeft, vector<string> expressionRight, string expressionOperator)
{


	bool lefthandResult;
	bool righthandResult;




	int LHSsum = 0;
	int RHSsum = 0;


	bool booleanB = false;

	//Parsing Boolean Expression

	//Left hand Side

	for (vector<string>::iterator leftHand = expressionLeft.begin(); leftHand != expressionLeft.end(); leftHand++) {

		string previousOperator;

		if (a.getKeywords().count(*leftHand)) {

			if (*leftHand == "ALLOUTCOMES_W") {
				LHSsum = a.getW();
			}
			else if (*leftHand == "ALLOUTCOMES_X") {
				LHSsum = a.getX();
			}
			else if (*leftHand == "ALLOUTCOMES_Y") {
				LHSsum = a.getY();
			}
			else if (*leftHand == "ALLOUTCOMES_Z") {
				LHSsum = a.getZ();
			}
			else if (*leftHand == "ALLOUTCOMES_Z") {
				LHSsum = a.getZ();

			}
			else if (*leftHand == "LASTOUTCOME");
			else if (*leftHand == "W") {
				if (betrayW == true) {
					lefthandResult = true;
				}
				else { lefthandResult = false; }

			}
			else if (*leftHand == "X") {
				if (betrayX == true) {
					lefthandResult = true;
				}
				else { lefthandResult = false; }
			}
			else if (*leftHand == "Y") {
				if (betrayY == true) {
					lefthandResult = true;
				}
				else { lefthandResult = false; }
			}

			else if (*leftHand == "Z") {
				if (betrayZ == true) {
					lefthandResult = true;
				}
				else {
					lefthandResult = false;
				}
			}

			else cout << "Error: " << *leftHand << " is not a keyword";

		}
		else {

			int tempory = 0;

			if (*leftHand == "ALLOUTCOMES_W") tempory = a.getW();
			else if (*leftHand == "ALLOUTCOMES_X") tempory = a.getX();
			else if (*leftHand == "ALLOUTCOMES_Y")tempory = a.getY();
			else if (*leftHand == "ALLOUTCOMES_Z") tempory = a.getZ();
			else if (*leftHand == "ITERATIONS") tempory = executeIterations;
			else if (*leftHand == "MYSCORE") tempory = a.getMyScore();

			else cout << "Error: " << *leftHand << " is not a keyword";
			if (previousOperator == "+") LHSsum = LHSsum + tempory;
			else if (previousOperator == "-") LHSsum = LHSsum - tempory;
		}

		if (a.getOperators().count(*leftHand)) {

			previousOperator = *leftHand;
		}


	}



	// Right Hand Side

	for (vector<string>::iterator rightHand = expressionRight.begin(); rightHand != expressionRight.end(); rightHand++) {

		string previousOperator;
		int tempory = 0;

		if (a.getKeywords().count(*rightHand)) {


			if (*rightHand == "ALLOUTCOMES_W") tempory = a.getW();
			else if (*rightHand == "ALLOUTCOMES_X") tempory = a.getX();
			else if (*rightHand == "ALLOUTCOMES_Y") tempory = a.getY();
			else if (*rightHand == "ALLOUTCOMES_Z") tempory = a.getZ();
			else if (*rightHand == "ITERATIONS") tempory = executeIterations;
			else if (*rightHand == "MYSCORE") tempory = a.getMyScore();
			else cout << "Error: " << *rightHand << " is not a keyword";


		}

		else {

			if (*rightHand == "W") RHSsum = a.getW();
			else if (*rightHand == "X")RHSsum = a.getX();
			else if (*rightHand == "Y")RHSsum = a.getY();
			else if (*rightHand == "Z")RHSsum = a.getZ();
			else if (*rightHand == "Z")RHSsum = a.getZ();
			else if (*rightHand == "LASTOUTCOME");
			else if (*rightHand == "W")
				if (betrayW = true) righthandResult == true;
				else righthandResult == false;
			else if (*rightHand == "X")
				if (betrayX = true) righthandResult == true;
				else righthandResult == false;
			else if (*rightHand == "Y")
				if (betrayY = true) righthandResult == true;
				else righthandResult == false;
			else if (*rightHand == "Z")
				if (betrayZ = true) righthandResult == true;
				else righthandResult == false;
			else cout << "Error: " << *rightHand << " is not a keyword";






			if (previousOperator == "+") { RHSsum = RHSsum + tempory; }
			if (previousOperator == "-") { RHSsum = RHSsum - tempory; }
		}

		if (a.getOperators().count(*rightHand)) { previousOperator = *rightHand; }
	}

	//Execute the complete boolean expression 
	if (expressionOperator == "=") {
		if (LHSsum == RHSsum) return true;
		return true;
	}
	else if (expressionOperator == "<") {
		if (LHSsum < RHSsum) return true;
		return true;
	}
	else if (expressionOperator == "<=") {
		if (LHSsum <= RHSsum) return true;
		return true;
	}
	else if (expressionOperator == "=<") {
		if (LHSsum <= RHSsum) return true;
		return true;
	}
	else if (expressionOperator == ">") {
		if (LHSsum > RHSsum)return true;
		return true;
	}
	else if (expressionOperator == "=>") {
		if (LHSsum >= RHSsum) true;
		return true;
	}
	else if (expressionOperator == ">=") {
		if (LHSsum >= RHSsum) return true;
		return true;
	}
	else return false;
}



bool codeExecute::keywordOperation(strategy a, strategy b) {


	//Retrieve first line number
	gotoLineNo = a.getCodeVector().begin()->first;

	for (int i = 0; i < a.getCodeVector().size(); i++) {

		setHasGotoNotCalled(true);
		string word = getWord(a);


		//Check first word
		if (word == "BETRAY") {

			a.setBetrayed(true);
			return true;

		}
		else if (word == "SILENCE") {

			a.setBetrayed(false);
			return false;

		}
		else if (word == "RANDOM") {
			//Randomise 
			int b = rand() % 2;
			if (b = 0) {
				a.setBetrayed(false);
				return false;
			}
			else
				a.setBetrayed(true);
			return true;

		}
		else if (word == "GOTO") {

			setHasGotoNotCalled(false);
			for (auto temp : a.getCodeVector()) {
				if (gotoLineNo == temp.first) {
					for (auto vec : temp.second) {
						gotoLineNo = stoi(vec);
					}
				}
			}

		}



		else if (word == "IF") {


			

			for (auto temp : a.getCodeVector()) {

				if (gotoLineNo == temp.first) {
					stringExpression = temp.second;
				}
			}

			//Split full expression into LHS

			vector<string>::iterator expressionIterator;

			for (expressionIterator = stringExpression.begin() + 1; !(a.getOperands().count(*expressionIterator)); expressionIterator++) {

				expressionLeft.push_back(*expressionIterator);
			}

			//Assign operator 
			expressionOperator = *expressionIterator;
			expressionIterator++;

			

			//Split right hand expression, stopping at GOTO
			for (expressionIterator; *expressionIterator != "GOTO"; expressionIterator++) {
				expressionRight.push_back(*expressionIterator);

			}

			if (calcExpression(a, b, expressionLeft, expressionRight, expressionOperator)) {
				gotoLineNo = stoi(*(expressionIterator + 1));

			}
			else {
				for (auto& tempIterator : a.getCodeVector()) {
					bool endOfFile = false;
					if (endOfFile) {
						gotoLineNo = tempIterator.first;
					}
					else if (gotoLineNo == tempIterator.first) {
						endOfFile = true;
					}
				}
			}



		}

	}
}

//Get the first word from file
string codeExecute::getWord(strategy a)
{
	string tempString = "";

	for (auto& temp : a.getCodeVector()) {
		if (gotoLineNo == temp.first) {
			tempString = *(temp.second.begin());
		}
	}
	if (tempString == "") {
		return "Error: No lines found";
	}
	else {
		return tempString;
	}
}


void codeExecute::incrementVariables(strategy &a, strategy &b)
{
	//Perform boolean logic
	if (betrayLastRoundA == true) {
		if (betrayLastRoundB == true) {
			a.setZ(1);
			b.setZ(1);
			betrayZ = true;
			a.setMyScore(4);
			b.setMyScore(4);
		}
		else {
			a.setY(1);
			b.setX(1);
			betrayY = true;
			b.setMyScore(5);

		}

	}
	else if (betrayLastRoundA == false) {
		if (betrayLastRoundB == true) {
			a.setX(1);
			b.setY(1);
			betrayX = true;
			a.setMyScore(5);

		}
		else {
			a.setW(1);
			b.setW(1);
			betrayW = true;
			a.setMyScore(2);
			b.setMyScore(2);

		}
	}


}

//Boolean logic for Gangs
void codeExecute::incrementGangVariables(vector<strategy>& purple, vector<strategy>& magenta, int purpleTotalBetray, int magentaTotalBetray)
{


	if (purpleTotalBetray == 0 && magentaTotalBetray == 0)
	{
		for (int i = 0; i != 5; i++) {
			purple[i].setW(2);
			magenta[i].setW(2);
			betrayW = true;
		}

	}
	else if (magentaTotalBetray == 5) {
		for (int i = 0; i != 5; i++) {
			purple[i].setW(5);
			magenta[i].setW(0);
			betrayX = true;

		}
	}


	if (purpleTotalBetray == 5 && magentaTotalBetray == 5) {

		for (int i = 0; i != 5; i++) {
			purple[i].setW(4);
			magenta[i].setW(4);
			betrayZ = true;
		}


	}
	else if (magentaTotalBetray == 0) {
		for (int i = 0; i != 5; i++) {
			purple[i].setW(0);
			magenta[i].setW(5);
			betrayY = true;
		}
	}


	if ((purpleTotalBetray == 3 && magentaTotalBetray == 3) || (purpleTotalBetray == 2 && magentaTotalBetray == 2)) {

		for (int i = 0; i != 5; i++) {
			purple[i].setW(2);
			magenta[i].setW(2);
			betrayW = true;
		}
	}


	if (purpleTotalBetray > magentaTotalBetray) {
		for (int i = 0; i != 5; i++) {
			purple[i].setW(2.5);
			magenta[i].setW(3);
			betrayW = true;
		}
	}
	if (purpleTotalBetray < magentaTotalBetray) {
		for (int i = 0; i != 5; i++) {
			purple[i].setW(3);
			magenta[i].setW(2.5);
			betrayW = true;
		}

	}



}


//Write results to file and to console
void codeExecute::writeResults(strategy &a, strategy &b)
{
	ofstream out("out.txt");



	if (a.getMyScore() > b.getMyScore()) {

		allResults.insert(pair<string, double>(a.getFileLocation() + " vs " + b.getFileLocation() + " : " + a.getFileLocation() + " wins", a.getMyScore()));
		cout << a.getFileLocation() << " vs " << b.getFileLocation() << " : " << a.getFileLocation() << " wins. Total years: " << a.getMyScore() << "\n";
		out << a.getFileLocation() << " vs " << b.getFileLocation() << " : " << a.getFileLocation() << " wins. Total years: " << a.getMyScore() << "\n";

	}
	else if (b.getMyScore() > a.getMyScore()) {

		allResults.insert(pair<string, double>(a.getFileLocation() + " vs " + b.getFileLocation() + " : " + b.getFileLocation() + " wins", b.getMyScore()));
		cout << b.getFileLocation() << " vs " << a.getFileLocation() << " : " << b.getFileLocation() << " wins. Total years: " << b.getMyScore() << "\n";
		out << b.getFileLocation() << " vs " << a.getFileLocation() << " : " << b.getFileLocation() << " wins. Total years: " << b.getMyScore() << "\n";
	}
	else if (b.getMyScore() == a.getMyScore()) {
		allResults.insert(pair<string, double>(a.getFileLocation() + " vs " + b.getFileLocation() + " : " + b.getFileLocation() + " draws", a.getMyScore()));
		cout << a.getFileLocation() << " vs " << b.getFileLocation() << " : " << a.getFileLocation() << " draws. Total years:  " << a.getMyScore() << "\n";
		out << a.getFileLocation() << " vs " << b.getFileLocation() << " : " << a.getFileLocation() << " draws. Total years:  " << a.getMyScore() << "\n";
	}





}
