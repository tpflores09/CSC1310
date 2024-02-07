/*

	Driver for Course Structure
	LAB 1 - CSC1310
	Tania Perdomo Flores
	
	1/26/2023
*/
#include "course1.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main ()
{
	//LOOK! 
	//Create a pointer to an array of Course pointers called myCourses here
	Courses **myCourses;
	
	int numCourses, numSections;
	string name, location;
	int numHours;
	
	cout << "\nHow many courses are you taking this semester?\n";
	cin >> numCourses;
	cin.ignore();
	
	//LOOK!!
	//Dynamically allocate a new array of pointers to Courses of size numCourses and assign this array to myCourses
	myCourses = new Courses*[numCourses];
	
	for (int i=0; i< numCourses; i++)
	{
		cout << "\nCOURSE NAME:\t\t";
		getline(cin, name);
		cout << "\nCOURSE LOCATION:\t";
		getline(cin, location);
		cout << "\nCOURSE HOURS:\t\t";
		cin >> numHours;
		cout << "\nNUMBER OF SECTIONS?\t";
		cin >> numSections;
		cin.ignore();
		
		//LOOK!!
		//Call the createCourse function and make sure to assign the returned value to myCourses[i]
        myCourses[i] = createCourse (name, location, numSections, numHours);

		
		for(int x=0; x<numSections; x++)
		{
			cout << "\nSECTION " << x+1 << ":\t\t";
			cin >> myCourses[i]->sectionsArray[x];    //Read in the string from the user and put in the correct array element of the sections array
		} 
		cout << "\n*******************************\n";
	}
	
	cout << "\n\nThe following are the courses you entered:\n\n";
	for(int i=0; i<numCourses; i++)
	{
		cout << "******************************* COURSE " << (i+1) << "*******************************\n";
		printCourse(myCourses[i]);
	}
	
	for(int i=0;  i< numCourses; i++)
	{
		destroyCourse(myCourses[i]);
	}
	delete [] myCourses;
	
	cout << endl << endl;
	return 0;
}