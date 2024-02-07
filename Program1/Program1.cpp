/*
	Title:  Program1.cpp
	Author:  Tania Flores
    Partner: Adrian Gonzalez
	Date:  2/15/2023
	Purpose: Your program should allow users to load a list of video game data from a file, save video game data to a file, add a video game, 
             remove a video game, display all video games in the library, and remove all video games.
*/


#include "Text.h"                           //library header files.
#include "VideoGame.h"
#include "VideoGameLibrary.h"
#include <iostream>
using namespace std;
int main()

{
    int choice;                                 //input variables.
    int maxGames;
    char filename[25];
    cout << "How many video games can your library hold?\n";     //this sets the max input of video games from the user and dynamically alocates an object and sends the nymber entered as an argument.
    cin >> maxGames;
    while(maxGames <= 0)      // this is to ensure that the user enters a valid number in maxGames.
	{
		cout << "\n\nYou have to have at least one movie available in RedBox.\n";
		cout << "How many movies can this RedBox hold?\n";
		cin >> maxGames;
	}

    VideoGameLibrary* videoGameLibrary = new VideoGameLibrary(maxGames);    //this sets for a new video game library with the user's max amount of games.
    do
    {
        cout << "What would you like to do?" << endl;                //menu option that allows the user to customize what they want to do with their library.
        cout << "1.  Load video games from file." << endl;
        cout << "2.  Save a video games to a file." << endl;
        cout << "3.  Add a video game." << endl;
        cout << "4.  Remove a vdeo games." << endl;
        cout << "5.  Display all video games." << endl;
        cout << "6. Remove ALL video games from this library and end program." << endl;
        cout << "CHOOSE 1-6: ";
        cin >> choice;
        while(choice < 1 || choice > 6)              //user will be sent to this loop  is a number less than 1 and greater that 5 is inputted.
        { 
            cout << " This is not a valid choice." << endl;
            cout << "Choice: ";
            cin >> choice;                              //user will get out of this loop if a number 1 through 5 is entered
                    
        }
        switch (choice)            //switcher allows the menu to loop through after user has completed the option they chose.
        {
            case 1:                                                    //choice 1 loads the user's personal video game files that they input.
            cout << "\nWhat is the name of the file? (example.txt):  ";
					cin >> filename;
					videoGameLibrary->loadVideoGamesFromFile(filename);      //this function allows the user's library to be added on.
            
            break;
            
            case 2:                                                             //choice 2 allows the user to save a game into a new file which the user can name.
            cout << "\n\nWhat do you want to name the file? (example.txt):  ";
					cin >> filename;
					videoGameLibrary->saveToFile(filename);                    // this function is asks for the name of the file and saves the game into that specific file.
            break;

            case 3:                                     //choice 3 allows the user to add a video game to the library and enter game information.
            videoGameLibrary-> addVideoGameToArray();
            break;

            case 4:                                           //choice 4 gives the user an option to remove a video game from the library and displays all video games in library for the user to choose which game to remove.
            videoGameLibrary -> removeVideoGameFromArray();
            break;

            case 5:                                       //choice 5 outputs all games in the library to the user and then gives the user the menu loop.
            videoGameLibrary -> displayVideoGames();
            break;

            case 6:                           //choice 6 allows the user to completely remove all of the video games in the library and ends the program.
            delete videoGameLibrary;
            break;
        }
    } while (choice != 6);                     //this while loop is so that the menu continues to loop after every option and ends when the user chooses it to.

    cout << "\n\nGOODBYE!\n\n";                 //program outputs this when user chooses to end the program.
    return 0;
    
}
