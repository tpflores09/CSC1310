/*

	function definitions for Course Structure
	LAB 1 - CSC1310
	Tania Perdomo Flores
	
	1/26/2023
*/

#include "course1.h"
using namespace std;

Courses *createCourse (string, string, int, int);

int myCourses()
{
	int numCourses;
	cout << "\n\nHow many courses do you have?";
	cin >> numCourses;
	return numCourses;
}

