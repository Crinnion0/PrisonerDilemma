#include "strategy.h"
#include "fileIO.h"



strategy::strategy(string ioLocation, int iterations)
{

	alloutcomesW = 0;
	alloutcomesX = 0;
	alloutcomesY = 0;
	alloutcomesZ = 0;
	iterations = 1;

	fileLocation = ioLocation;
	setIterations(iterations);

	readCode(fileLocation);
	codeIterator a(getCode());

	stratergyCodeVector = a.mapToArray(stratergyCode);

}


strategy::~strategy()
{
}

void strategy::readCode(string ioLocation)
{
	fileIO reader;

	stratergyCode = reader.readFile(ioLocation);



}

void strategy::determineFirstOperation()
{

	
	string s = stratergyCode[10];
	istringstream ss(s);
	string a;

	ss >> a;


	if (a == "IF"){

		

	}
	else if (a == "GOTO") {

		cout << "GOT A GOTO";
	}
	else if (a == "BETRAY") {

	}
	else if (a == "SILENCE") {

	}
	else if (a == "RANDOM") {


	}


}



int strategy::getW()
{
	return alloutcomesW;
}

int strategy::getX()
{
	return alloutcomesX;
}

int strategy::getY()
{
	return alloutcomesY;
}

int strategy::getZ()
{
	return alloutcomesZ;
}

int strategy::getIterations()
{
	return iterations;
}

int strategy::getMyScore()
{
	return myScore;
}


map<int, string> strategy::getCode()
{
	return stratergyCode;
}

map<int, vector<string>> strategy::getCodeVector()
{
	return stratergyCodeVector;
}

bool strategy::getBetrayed()
{
	return betrayed;
}

void strategy::setW(float a)
{

	alloutcomesW+ a;
}

void strategy::setX(float a)
{
	alloutcomesX+a;

}

void strategy::setY(float a)
{
	alloutcomesY+a;

}

void strategy::setZ(float a)
{

	alloutcomesZ+a;

}

void strategy::setMyScore(int a)
{

	myScore = myScore + a;
}

void strategy::setFileLocation(string a)
{

	fileLocation = a;

}

void strategy::setCodeVector(map<int, vector<string>> a)
{

	stratergyCodeVector = a;

}

void strategy::setBetrayed(bool i)
{
	betrayed = i;

}


