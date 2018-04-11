#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include<sstream>

using namespace std;




class fileIO {
public:
	fileIO();
	~fileIO();

	//Read code in from file
	map<int, string>readFile(string fileLocation);

protected:

	string fileName;
	string temp;
	ifstream SourceFile;

};
