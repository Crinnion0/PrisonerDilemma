#pragma once
#include "strategy.h"
#include "codeIterator.h"
#include <fstream>


class codeExecute
{
public:
	codeExecute(strategy &a, strategy &b);
	codeExecute(vector<strategy>&a , vector<strategy>&b);
	~codeExecute();

	

	bool keywordOperation(strategy a, strategy b);
	bool calcExpression(strategy a, strategy b, vector<string> expressionLeft, vector<string> expressionRight, string expressionOperator);

	
	string getWord(strategy a);

	void setHasGotoNotCalled(bool a) { hasGotoNotCalled = a; }
	void incrementVariables(strategy &a, strategy &b);
	void incrementGangVariables(vector<strategy> &purple, vector<strategy> &magentam, int purpleTotalBetray, int magentaTotalBetray);

	void writeResults(strategy &a, strategy &b);


	map<string, double> returnAllResults() { return allResults; }

protected:

	set<string> ifOperands{ ">", "<", "=", };

	int executeIterations = 0;


	bool betrayW;
	bool betrayX;
	bool betrayY;
	bool betrayZ;


	bool hasGotoNotCalled;
	bool betrayLastRoundA;
	bool betrayLastRoundB;

	map<string, double> allResults;

	vector<string> stringExpression;
	vector<string> expressionLeft;
	vector<string> expressionRight;
	string expressionOperator;
	int gotoLineNo;
	
};

