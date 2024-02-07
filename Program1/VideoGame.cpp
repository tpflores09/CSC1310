/*Name: Tania Flores
  Course & Section: CSC 1310 - 001
  Due Date: 2/15/2023
Partner: Adrian Gonzalez*/


#include "VideoGame.h"         //included library header files.
#include "Text.h"

//this file contains the videogame class functions and its parameters.


/*
Function Name:  VideoGame (constructor)
Parameters:  A pointer to a Text variable, containing the title of the video game
            A pointer to a Text variable, containing the developer of the video game
            A pointer to a Text variable, containing the publisher of the video game
	        An  integer containing the year the video game was released 
Purpose:  This function should be called when all video game information is known and it will create 
          a new video game with this information.
*/
VideoGame :: VideoGame(Text*title ,Text*developer,Text *publisher, int year)
{
    gameTitle = title;
    gameDeveloper = developer;
    gamePublisher = publisher;
    gameYear = year;
}

/*
Function Name:  ~VideoGame (destructor)
Parameters:  none
Purpose:  This function is automatically called when a Video game object is destroyed.  This function releases 
        the dynamically allocated text arrays in the Video game.
*/
VideoGame :: ~VideoGame()
{
    delete gameTitle;
    delete gameDeveloper;
    delete gamePublisher;
    cout << "VideoGame destructor: Released memory for VideoGame object.\n";
}

/*
Function Name:  printVideoGameDetails
Parameters: none
Purpose:   This function should be called when the user wants to print 
           ALL the video game information to the screen.
*/
void VideoGame :: printVideoGameDetails()
{
 
    cout << endl;
    cout << right << setw(30) << "Video Game TITLE: " << left;
    gameTitle -> displayText();
    cout << endl;
    cout <<  right << setw(30) <<"Video Game DEVELOPER: " << left;
    gameDeveloper -> displayText();
    cout << endl;
    cout <<  right << setw(30) <<"Video Game PUBLISHER: " << left;
    gamePublisher -> displayText();
    cout << endl;
    cout << right << setw(30) <<"Year Released: " << left << gameYear << endl ;

}

/*
Function Name:  printVideoGameDetailsToFile
Parameters:  a file stream object (sent by reference)
Purpose:   :  This function should be called when the user wants to print ALL the video game 
           information to the file.
*/
void VideoGame :: printVideoGameDetailsToFile(ofstream& outFile)
{

    char words[1000];
	strncpy(words, gameTitle->getText(), 1000);
	outFile << gameYear << endl;
	strncpy(words, gameDeveloper->getText(), 1000);
	outFile << words << endl;
	strncpy(words, gamePublisher->getText(), 1000);
	outFile << words << endl;
    outFile << gameYear << endl;

}

/*
Function Name:  getVideoGameTitle
Parameters:   none
Purpose:  :  to return a pointer to the Text object containing the video game title
*/
Text* VideoGame :: getVideoGameTitle()const
{
    return gameTitle;
}