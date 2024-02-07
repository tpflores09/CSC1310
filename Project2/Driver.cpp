/*
	Title:  driver.cpp - Program2
	Author:  Tania Flores
	Course: CSC 1310 - 001
	Partner: Adrian Gonzalez
	Date:  3/15/2023
	Purpose: read the county list from the csv, add them all to the linked list
			sort the list, and then print the sorted list.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "County.h"
#include "List.h"          //include your list header here------------------------------------------------------------------------


using namespace std;

int main()
{
	ifstream file;
	stringstream temp;
	string line, county, state;
	int index, pop;
	file.open("counties_list.csv", ios::in);
	file.open("counties_ten.csv", ios::in);

	//create a new list of county pointers ------------------------------------------------------------------
	List <County> countyList;
	County* newCounty;

	if(file.good()) {
	while(getline(file, line, ','))
	{
		temp.clear();
		temp.str(line);
		temp >> index;

		getline(file, line, ',');
		county = line;

		getline(file, line, ',');
		state = line;

		getline(file, line, '\n');
		temp.clear();
		temp.str(line);
		temp >> pop;

		newCounty = new County(index, county, state, pop);
		//append newCounty to your list-----------------------------------------------------------------------------------
		countyList.append(newCounty);
	}}

	file.close();

	//call mergesort---------------------------------------------------------------------------------------------
	countyList.mergesort();
	//print the list-----------------------------------------------------------------------------------------------------
	countyList.print();

	return 0;
}