#include "codeIterator.h"




codeIterator::codeIterator(map<int, string> importCode)
{

	strategyCode = importCode;
	mapToArray(strategyCode);

}


codeIterator::~codeIterator()
{
}



map<int, vector<string>> codeIterator::mapToArray(map<int, string> strategyCode)
{

	map<int, vector<string>> temp;


	//Overhead for using auto minimal - Improves code readability
	for (auto i : strategyCode) {

		temp.insert(std::pair<int, vector<string>>(i.first, splitString(i.second)));

	}


	return temp;

}

vector<string> codeIterator::splitString(string input)
{


	//Split input into vector of strings
	const char& delimiter = ' ';

	string buffer{ "" };
	vector<string> code;

	for (char currentChar : input)
	{
		if (currentChar != delimiter) buffer += currentChar; else
			if (currentChar == delimiter && buffer != "") { code.push_back(buffer); buffer = ""; }
	}
	if (buffer != "") code.push_back(buffer);

	strategyCodeSplit = code;
	return code;
}







