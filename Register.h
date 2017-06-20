#pragma once
#include <iostream>
#include "Runner.h"
#include <string>
#include <vector>

class Register
{
public:
	//constructor
	Register(string filename);

	//sort runners from fastest to slowest
	void sortRunners();

	//put runners in corresponding color file based on pace
	void addToGroup();

	//print the sorted vector
	void printVector();
private:
	vector <Runner> RegisteredRunners;
};