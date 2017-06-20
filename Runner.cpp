#include "Runner.h"
#include <string>
#include <iostream>
using namespace std;

//create a runner object
Runner::Runner(string firstname, string lastname, int pace)
{
	this->firstname = firstname;
	this->lastname = lastname;
	this->pace = pace;
}

//returns the firstname of the runner
string Runner::get_firstname()
{
	return firstname;
}

//returns the lastname of the runner
string Runner::get_lastname()
{
	return lastname;
}

//returns the pace of the runner in seconds
int Runner::get_pace()
{
	return pace;
}