/*
	Title:  Lab2.cpp
	Author: Tania Perdomo Flores
	Date:  02/06/2023
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iomanip>
#include <cmath>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser (string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "The result is: " << sumOfNumbers(num) << endl;//print out the result of the sumOfNumbers function here

                   

                break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++) 
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				cout << endl;
				if (ARRAY_SIZE == true){
					cout << num << " is in the array." << endl;
				} else {
					cout << "No!" << num << " is not in the array." << endl; //print if the value that the user entered is in the array or not here
				}
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				return userString[0]; //call string reverser function here
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				cout << endl;
				if (isPalindrome(userString) == true){
					cout << "Yes!" << userString << " is a palindrome!" << endl;
				} else {
					cout << "No!" << userString << "is NOT a palindrome" << endl;
				}
				 //print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				cout << "The value of " << num1 << " x " << num2 << " is " << multiply(num1,num2) << endl;//print out the value returned from the multiply function here
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}


//implement the five recursive functions below!!!!
int sumOfNumbers(int num){
    if (num == 0){
        return 0;
	} else {
    	return num + sumOfNumbers(num-1);
    }
}

bool isMember(int *myArray, int ARRAY_SIZE, int num){
    if (ARRAY_SIZE == 0){
        return false;
    } else if (myArray[ARRAY_SIZE] == num){
        return true;
    } else {
		return isMember(myArray, ARRAY_SIZE, num);
	}
}

void stringReverse (string userString, int x){
    if (userString.size() == x){
        return;
	}
    stringReverser(userString.substr(1), ARRAY_SIZE-1);
	cout << userString[0];
}

bool isPalindrome (string userString){
    if (isPalindrome(userString)){
        return true;
    } else {
		return false;
	}
	return 0;
}

int multiply (int num1, int num2) {
	if (num1==0 || num2 ==0){
	return 0;
	} else {
		return num2+multiply(num1-1, num2);
	}
}