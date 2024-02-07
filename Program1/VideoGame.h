/*
	Title:  Program1.cpp
	Author:  Tania Flores
    Partner: Adrian Gonzalez
	Date:  2/15/2023
	Purpose: header file for VideoGame.cpp
*/
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "Text.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;



class VideoGame
{
    public:
        /*
			Function Name:  VideoGame (constructor)
			Parameters:  A pointer to a Text variable, containing the title of the video game
                         A pointer to a Text variable, containing the developer of the video game
                         A pointer to a Text variable, containing the publisher of the video game
	                     An  integer containing the year the video game was released 

			Purpose:  This function should be called when all video game information is known and it will create 
                      a new video game with this information.
		*/
        VideoGame(Text*,Text*,Text *, int);

        /*
			Function Name:  ~VideoGame (destructor)
			Parameters:  none
			Purpose:  This function is automatically called when a Video game object is destroyed.  This function releases 
                      the dynamically allocated text arrays in the Video game.
		*/
        ~VideoGame();

        /*
			Function Name:  printVideoGameDetails
			Parameters: none
			Purpose:   This function should be called when the user wants to print 
                       ALL the video game information to the screen.
		*/
        void printVideoGameDetails();

        /*
			Function Name:  printVideoGameDetailsToFile
			Parameters:  a file stream object (sent by reference)
			Purpose:   :  This function should be called when the user wants to print ALL the video game 
                          information to the file.
		*/
        void printVideoGameDetailsToFile(ofstream &outfile);

        /*
			Function Name:  getVideoGameTitle
			Parameters:   none
			Purpose:  :  to return a pointer to the Text object containing the video game title
		*/
        Text *getVideoGameTitle() const;



    private:
        Text *gameTitle;
        Text *gameDeveloper;
        Text *gamePublisher;
        int gameYear;


};

#endif