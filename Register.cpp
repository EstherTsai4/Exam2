#include <iostream>
#include <vector>
#include <fstream>
#include "Register.h"
#include "Runner.h"
#include <string>
#include <iomanip>
using namespace std;

//create a constructor for register by adding the registered runners to the vector
Register::Register(string filename)
{
	//read the file containing all the registered runners
	ifstream readFile(filename);

	//objects to read in file
	string firstname, lastname;
	int pace;

	//read the file and store each line in the vector
	//read until reaches end of the file
	while (readFile >> firstname >> lastname >> pace)
	{
		Runner temp(firstname, lastname, pace);
		RegisteredRunners.push_back(temp);
	}
}

void Register::sortRunners()
{
	//sort the vector of runners based on the pace
	//from fastest to slowest runner


	for (int i = 0; i < RegisteredRunners.size(); i++)
	{
		//set a the first runner in the list of runners as the fastest
		Runner maxPace = RegisteredRunners[i];
		int maxIndex = i;

		//checks if the first runner is actually the fastest; if not, set the other runner as the fastest
		for (int j = i + 1; j < RegisteredRunners.size(); j++)
		{
			if (maxPace.get_pace() > RegisteredRunners[j].get_pace())
			{
				maxPace = RegisteredRunners[j];
				maxIndex = j;
			}
		}
		
		//swap the elements if applicable
		if (maxIndex != i)
		{
			RegisteredRunners[maxIndex] = RegisteredRunners[i];
			RegisteredRunners[i] = maxPace;
		}
	}
}

//add the runner to their corresponding color group
void Register::addToGroup()
{
	//open the files
	ofstream whiteFile("white.txt");
	ofstream yellowFile("yellow.txt");
	ofstream greenFile("green.txt");
	ofstream orangeFile("orange.txt");
	ofstream blueFile("blue.txt");
	ofstream lilacFile("lilac.txt");
	ofstream redFile("red.txt");

	//go through each runner's pace and sort based on their speed
	for (int i = 0; i < RegisteredRunners.size(); i++)
	{
		//write runner to white.txt
		if (RegisteredRunners[i].get_pace() > 0 && RegisteredRunners[i].get_pace() <= 360)
		{

			//write the data fields into a line
			whiteFile << left << RegisteredRunners[i].get_firstname() << setw(10) << RegisteredRunners[i].get_lastname()
				<< setw(10) << RegisteredRunners[i].get_pace() << endl;
		
		}
		//add to yellow group
		else if (RegisteredRunners[i].get_pace() >= 361 && RegisteredRunners[i].get_pace() <= 420)
		{

			//write the data fields into a line
			yellowFile << left << RegisteredRunners[i].get_firstname() << setw(10) << RegisteredRunners[i].get_lastname()
				<< setw(10) << RegisteredRunners[i].get_pace() << endl;

		}
		//add to green group
		else if (RegisteredRunners[i].get_pace() >= 421 && RegisteredRunners[i].get_pace() <= 480)
		{

			//write the data fields into a line
			greenFile << left << RegisteredRunners[i].get_firstname() << setw(10) << RegisteredRunners[i].get_lastname()
				<< setw(10) << RegisteredRunners[i].get_pace() << endl;

		}
		//add to orange group
		else if (RegisteredRunners[i].get_pace() >= 481 && RegisteredRunners[i].get_pace() <= 540)
		{
	
			//write the data fields into a line
			orangeFile << left << RegisteredRunners[i].get_firstname() << setw(10) << RegisteredRunners[i].get_lastname()
				<< setw(10) << RegisteredRunners[i].get_pace() << endl;

		}
		//add to blue group
		else if (RegisteredRunners[i].get_pace() >= 541 && RegisteredRunners[i].get_pace() <= 600)
		{
		
			//write the data fields into a line
			blueFile << left << RegisteredRunners[i].get_firstname() << setw(10) << RegisteredRunners[i].get_lastname()
				<< setw(10) << RegisteredRunners[i].get_pace() << endl;

		}
		//add to lilac group
		else if (RegisteredRunners[i].get_pace() >= 601 && RegisteredRunners[i].get_pace() <= 720)
		{
			
			//write the data fields into a line
			lilacFile << left << RegisteredRunners[i].get_firstname() << setw(10) << RegisteredRunners[i].get_lastname()
				<< setw(10) << RegisteredRunners[i].get_pace() << endl;

		}
		//add to red group
		else if (RegisteredRunners[i].get_pace() >= 721 && RegisteredRunners[i].get_pace() <= 1200)
		{

			//write the data fields into a line
			redFile << left << RegisteredRunners[i].get_firstname() << setw(10) << RegisteredRunners[i].get_lastname()
				<< setw(10) << RegisteredRunners[i].get_pace() << endl;

		}
	}

	//close the files
	whiteFile.close();
	yellowFile.close();
	greenFile.close();
	orangeFile.close();
	blueFile.close();
	lilacFile.close();
	redFile.close();
}

void Register::printVector()
{
	for (int i = 0; i < RegisteredRunners.size(); i++)
	{
		cout << left << RegisteredRunners[i].get_firstname() << setw(10) 
			<< RegisteredRunners[i].get_lastname() << setw(10) 
			<< RegisteredRunners[i].get_pace() << "seconds" << setw(10) << endl;
	}
}