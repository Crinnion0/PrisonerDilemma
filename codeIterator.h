#pragma once
#include <string>
#include <map>
#include <iostream>
#include <vector>

using namespace std;

class codeIterator
{
public:


	codeIterator(map<int, string> importCode);
	~codeIterator();



	//Convert strategy map into vector of strings
	map<int, vector<string>> mapToArray(map<int, string> stratergyCode);

	vector<string> splitString(string input);





protected:

	string a;




	vector<string> strategyCodeSplit;
	map<int, string> strategyCode;

};

