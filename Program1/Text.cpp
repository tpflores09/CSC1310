/*Name: Tania Flores
  Course & Section: CSC 1310 - 001
  Due Date: 2/15/2023
Partner: Adrian Gonzalez*/

//this file contains the char and text structs that the user would input or need displayed, and also allows for the releasing of memory when asked.

#include "Text.h"
#include <iomanip>
#include <cstring>
using namespace std;


/*
Function Name:  Text (constructor)
Parameters:  Send a pointer to a constant character array or a string literal to this function
Purpose:  called automatically when Text object is created, dynamically allocates a character array which 
           contains the character array passed to the function.
*/
Text :: Text(const char* text)
{
    textLength = strlen(text);

    char* newArray = new char[(textLength)+1];

    strcpy(newArray,text);

    this -> textArray = newArray;

}

 /*
Function Name:  ~Text (destructor)
Parameters:  Send a pointer to a constant character array or a string literal to this function
Purpose:  release dynamically allocated memory for the c-string in the Text object 
*/
Text :: ~Text()
{
    delete [] textArray;
    cout << "Text destructor: Released memory for textArray.\n";

}

/*
Function Name:  Text (constructor)
Parameters:  none
Purpose:  print the c-string (textArray) to the screen. (c++ will let you just cout a char array)
*/
void Text :: displayText() const
{
    cout << textArray;

} 

/*
Function Name:  getText (accessor function)
Parameters: none
Purpose:  return pointer to a constant character array
*/
const char* Text :: getText() const
{
    return textArray;
}

/*
Function Name:  getLength (accessor function)
Parameters:  none
Purpose:  return the length of the string
*/
int Text :: getLength() const
{
    return textLength;
}