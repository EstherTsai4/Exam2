#include <iostream>
#include <string>

#include "Runner.h"
#include "Register.h"
using namespace std;

int main()
{
	//declare variable for filename
	string filename;

	//ask user to enter in filename
	cout << "What is the file name of registered runners? ";
	cin >> filename;

	//create vector from the filename
	Register create(filename);

	//sort the runners by calling the sort function
	create.sortRunners();
	//print sorted runners
	create.printVector();

	//put the runners into the corresponding group
	create.addToGroup();

	return 0;
}