/*

	Header file for Course Structure
	LAB 1 - CSC1310
	Tania Perdomo Flores
	
	1/26/2023
*/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
 
// Structure declaration
struct Courses
{
   string name;      // name string
   string location;      // location string
   string *sectionsArray;   // sections pointer to an array of strings
   int numSections;        // number of sections
   int numHours;     // number of credit hours
};

int myCourses();

Courses* createCourse(string, string, int, int);

void destroyCourse (Courses* myCourses);

void printCourse (Courses* myCourses);

#endif