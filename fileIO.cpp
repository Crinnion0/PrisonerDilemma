#include "fileIO.h"


using namespace std;



fileIO::fileIO()
{
}


fileIO::~fileIO()
{
}

map<int, string> fileIO::readFile(string fileLocation)
{

	map<int, string> tempMap;

	//Read file into map and return it to the strategy

	fileName = fileLocation;



	SourceFile.open(fileName);

	if (!SourceFile.is_open()) {
		cout << "Invalid Filename\n";
		return tempMap;
	}




	while (getline(SourceFile, temp)) {

		istringstream iss(temp);

		string test;

		iss >> test;
		int id;
		id = stoi(test);
		test = "";

		while (iss) {

			string subs;
			iss >> subs;
			test += subs += " ";

		}

		tempMap.insert(pair<int, string>(id, test));

	}



	SourceFile.close();
	return tempMap;
}



