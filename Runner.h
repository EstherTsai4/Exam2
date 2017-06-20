#pragma once
#include <string>
using namespace std;

class Runner
{
public:
	//constructor for runner object
	Runner(string, string, int);

	//retrieving data fields of objects
	string get_firstname();
	string get_lastname();
	int get_pace();

private:
	string firstname;
	string lastname;
	int pace;
};
