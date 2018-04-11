#pragma once
#include <map>
#include <set>
#include "codeIterator.h"

using namespace std;
class strategy
{
public:
	strategy(string ioLocation, int iterations);
	~strategy();

	void readCode(string ioLocation);

	void determineFirstOperation();

	int getW();
	int getX();
	int getY();
	int getZ();
	int getIterations();
	int getMyScore();
	set<string> getKeywords() { return keywords; }
	set<string> getOperators() { return operators; }
	set<string> getOperands() { return operands; }
	string getFileLocation() { return fileLocation; }

	map <int, string> getCode();
	map<int, vector<string>> getCodeVector();

	bool getBetrayed();

	void setW(float a);
	void setX(float a);
	void setY(float a);
	void setZ(float a);
	void setIterations(int a) { iterations = a; }
	void setMyScore(int a);
	void setFileLocation(string a);
	

	void setCodeVector(map<int, vector<string>> a);
	void setBetrayed(bool i);

protected:

	char lastOutcome;

	float alloutcomesW;
	float alloutcomesX;
	float alloutcomesY;
	float alloutcomesZ;

	int iterations;
	int myScore;


	bool betrayed;
	

	map<int, vector<string>> stratergyCodeVector;
	map<int, string> stratergyCode;

	set<string> keywords{ "IF", "GOTO", "BETRAY", "SILENCE", "RANDOM", "LASTOUTCOME", "ALLOUTCOMES_W", "ALLOUTCOMES_X", "ALLOUTCOMES_Y", "ALLOUTCOMES_Z", "ITERATIONS", "MYSCORE" };
	set<string> operators{"+","-"};
	set<string> operands{ ">","<" ,"=" };

	string fileLocation;
};

