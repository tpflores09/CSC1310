/*Name: Tania Flores
  Course & Section: CSC 1310 - 001
  Due Date: 2/15/2023
Partner: Adrian Gonzalez*/

// this file contains the video game library functions and its parameters.


#include "VideoGameLibrary.h"           //included library header files.
#include "VideoGame.h"

/*
Function Name:  resizeVideoGameArray
Parameters:   none
Purpose:  : This function is called by addVideoGameToArray when the array size is not big enough to hold a new video game that   
            needs to be added.  The function makes the array twice as big as it currently is and then moves all the video game 
            pointers to this new array.
*/
void VideoGameLibrary:: resizeVideoGameArray()
{
    int max = maxGames * 2; //increase size by 2
	cout << "\nResizing VideoGameArray from " << maxGames << " to " << max << ".\n";
	//make an array that is twice as big as the one I've currently got
	VideoGame** newVideoGameArray = new VideoGame*[max];
	for(int i = 0; i < numGames; i++)
	{
		newVideoGameArray[i] = videoGamesArray[i];
	}
	delete [] videoGamesArray;
	videoGamesArray = newVideoGameArray;
	maxGames = max; 

}

/*
Function Name:  VideoGameLibrary (constructor)
Parameters:   An integer containing the maximum size of the video game library 
Purpose:  :  This function is automatically called when a VideoGameLibrary object is created and it creates a library 
             of video games.  
		*/
VideoGameLibrary :: VideoGameLibrary(int maximum)
{
    maxGames = maximum;
    numGames =0;

    videoGamesArray = new VideoGame*[maximum];

}

/*
Function Name:  ~VideoGameLibrary (destructor)
Parameters:   none
Purpose:  :  This function is automatically called when the VideoGame object is destroyed.  This releases the dynamically created
            individual video games and then deletes the array.
*/
VideoGameLibrary :: ~VideoGameLibrary()
{
    for (int i =0; i<numGames;i++)
    {
        delete videoGamesArray[i];
    }
    delete [] videoGamesArray;
}

/*
Function Name:  addVideoGameToArray
Parameters:   none
Purpose:  :  This function should be called when you need to add a single video game to the video game library.  
*/
void VideoGameLibrary :: addVideoGameToArray()
{
    char string[100];
	int year;
	Text* gameTitle;
	Text* gameDeveloper;
	Text* gamePublisher;
	
	//add a movie
	cin.ignore();  //remove the \n from the keyboard buffer
	cout << "\n\nVideo Game TITLE: ";
	cin.getline(string, 100);
	gameTitle = new Text(string);
	cout << "\nVideo Game DEVELOPER: ";
	cin.getline(string, 100);
	gameDeveloper = new Text(string);
	cout << "\nVideo Game PUBLISHER: ";
	cin.getline(string, 100);
	gamePublisher = new Text(string);
	cout << "\nVideo Game YEAR: ";
	cin >> year;
	cin.ignore();
	
	//create the movie
	VideoGame* game = new VideoGame(gameTitle ,gameDeveloper,gamePublisher, year);
	
	//add the movie to the library
	if(numGames == maxGames)
		resizeVideoGameArray();	

	videoGamesArray[numGames] = game;
	
	(numGames)++;

}

/*
Function Name:  displayVideoGames
Parameters:   none
Purpose:  : This function should be called when the user wants to have all the video games in the library printed to the screen.    
*/
void VideoGameLibrary :: displayVideoGames()
{
    if(numGames > 0)
	{
		for(int i=0; i < (numGames); i++)
		{
			cout << endl << right << setw(50) << "----------Video Game " << (i+1) << "----------";
			videoGamesArray[i]->printVideoGameDetails(); 
		}
	}
    else    
        cout << "\nThere are no video games in your library yet.";
   
}

/*
Function Name:  displayVideoGamesTitles
Parameters:   none
Purpose:  : This function should be called when you want to print only the video game titles out of the video game 
*/
void VideoGameLibrary :: displayVideoGamesTitles()
{

    Text* gameTitle;
    for( int i=0; i <numGames; i++)
    {
        cout << "\nVideo Game " << (i+1) << ": ";
        gameTitle = videoGamesArray[i] -> getVideoGameTitle();
        gameTitle -> displayText();
    }
}

 /*
Function Name:  loadVideoGamesFromFile
Parameters:   A pointer to a character (c-string or string literal argument) containing the filename
Purpose:  :  This function should be called when the user wants to read video game data from a file and add the video games 
            to the video game library.  The file must have data in the following order: title, developer, publisher, year.  
*/
void VideoGameLibrary :: loadVideoGamesFromFile(char*filename)
{
	int numVideoGamesReadToFile =0;
	ifstream inFile;
	char string[100];
	Text* gameTitle;
	Text* gameDeveloper;
	Text* gamePublisher;
	VideoGame* game;
	int gameYear; //year released
	
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(string, 100);
		while(!inFile.eof())
		{	
			gameTitle = new Text(string);
			 
			inFile.getline(string, 100); 
			inFile.getline(string, 100); 
			inFile >> gameYear;
			inFile.ignore();
			gamePublisher = new Text(string); 
			
			
			//one video game has been read from the file.  Now create a video game object
			game = new VideoGame(gameTitle, gameDeveloper,gamePublisher,gameYear);
			
			//now add this video game to the library
			
			if(numGames == maxGames)
				resizeVideoGameArray();	//increase size by 2

			videoGamesArray[numGames] = game;
			
			(numGames)++;
			
			//confirm addition to user
			cout << endl;
			gameTitle->displayText();
			cout << " was added to the Video Game library!\n";
						
			inFile.getline(string, 100); 
			
			numVideoGamesReadToFile++;
		}
		
		cout << "\n\n" << numVideoGamesReadToFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "Sorry, I was unable to open the file.\n\n";
	}
}

/*
Function Name:  removeVideoGameFromArray
Parameters:   none
Purpose:  : This function should be called when the user wants to remove one single video game from the video game library. 
            The video game to be removed must is identified by the user and then removed.
*/
void VideoGameLibrary :: removeVideoGameFromArray()
{
    int gamePick;
	
	if(numGames <= 1)
	{
	   cout << endl << "There must always be at least one video game in your library.  You can\'t";
	   cout << " remove any video games right now or you will have no video games in your library.\n";
	}
	else
	{
		cout << "\n\nChoose from the following video games to remove:\n";
		displayVideoGamesTitles();
		cout << "\nChoose a video game to remove between 1 & " << numGames << ":  ";
		cin >> gamePick;
		
		while(gamePick < 1 || gamePick > numGames)
		{
			cout << "\nOops!  You must enter a number between 1 & " << numGames << ":  ";
			cin >> gamePick;
		}

		int movieIndexToBeRemoved = gamePick-1;
		Text* gameTitle;
		gameTitle = videoGamesArray[movieIndexToBeRemoved]->getVideoGameTitle();
		
		cout << "\n\nThe video game \"";
		gameTitle->displayText();
		cout << "\" has been successfully deleted.\n";	
		
		
		delete videoGamesArray[movieIndexToBeRemoved];
		
		int numElementsToMoveBack = (numGames) - 1;
		
		for(int i = movieIndexToBeRemoved; i < numElementsToMoveBack; i++)
		{
			videoGamesArray[i] = videoGamesArray[i+1]; 
		}
		
		
		videoGamesArray[numElementsToMoveBack] = NULL;
		
		
		(numGames)--;
	}
}

/*
Function Name:  saveToFile
Parameters:   A pointer to a character (c-string or string literal argument) containing the filename
Purpose:  :  This function should be called when the user wants to print all the video game data from the video game 
            library to a file.  The data is printed in the following order (one piece of data per line):  title, developer, publisher, year.
*/
void VideoGameLibrary:: saveToFile(char* filename)
{
    ofstream outFile;
	
	outFile.open(filename);
	
	for(int i=0; i<numGames; i++)
	{
		videoGamesArray[i]->printVideoGameDetailsToFile(outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll video games in your library have been printed to " << filename << endl;
}