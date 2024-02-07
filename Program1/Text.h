/*Name: Tania Flores
  Course & Section: CSC 1310 - 001
  Due Date: 2/15/2023
Partner: Adrian Gonzalez*/


#ifndef TEXT_H
#define TEXT_H

#include <iostream>
using namespace std;


class Text
{
    public: 
        /*
			Function Name:  Text (constructor)
			Parameters:  Send a pointer to a constant character array or a string literal to this function
			Purpose:  called automatically when Text object is created, dynamically allocates a character array which 
                      contains the character array passed to the function.
		*/
        Text(const char*);

        /*
			Function Name:  ~Text (destructor)
			Parameters:  Send a pointer to a constant character array or a string literal to this function
			Purpose:  release dynamically allocated memory for the c-string in the Text object 
		*/
        ~Text();

        /*
			Function Name:  Text (constructor)
			Parameters:  none
			Purpose:  print the c-string (textArray) to the screen. (c++ will let you just cout a char array)
		*/
        void displayText() const;

        /*
			Function Name:  getText (accessor function)
			Parameters: none
			Purpose:  return pointer to a constant character array
		*/
        const char* getText() const;

        /*
			Function Name:  getLength (accessor function)
			Parameters:  none
			Purpose:  return the length of the string
		*/
        int getLength() const;
        
        
    private :
        const char* textArray;
        int textLength;


};


#endif