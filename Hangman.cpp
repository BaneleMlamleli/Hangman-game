/****************************************************************
** Name:			Hangman.cpp
** Author:			Cipher
** Source:			GNU C++
** Description:		This is a word game called Hangman
** Build:			g++ Hangman.cpp -o Hangman
** History:			01 April 2014 - work started
****************************************************************/

/**********************************************************************************************************************************************
** The word to guess is represented by a row of stars (asterisks), each letter is replaced by an asterisks to represent the hidden word.
** If the guessing player suggests a letter which occurs in the word, the letter will be written in its correct position replacing the star.
** If the suggested letter does not occur in the word, the amount of re-tries will be reduced by one.
** The game is over when the amount of re-tries reach zero or the player guesses all the letters in the word before the dre-tries
** reach zero. Initially the player starts with nine tries as the player misses the re-tries decrease by one.
**********************************************************************************************************************************************/

#include <iostream>				//Standard input and output headerfile
#include <ctime>				//random time generator and pausing console
#include <string>				//Standard string headerfile
#include <cstdlib>				//Headerfile for changing the console colour
#include <windows.h>            //windows library for console manipulation
using namespace std;			// using the namespace standard library for qualified (and unqualified naming)

#define consoleColor "color a"	//This is a predefined preprocessor constant for changing the console colour
#define clearConsole "cls"		//This is a predefined preprocessor constant for clearing the console
//************************************************************************************************************


//Message to be displayed if the player won the game
//The parameter is for the full word that was to be guessed. It will be displayed underneath the message
void gameWon(string randWord)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //creating an object for the color manipulation
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY); //changing the color of the text to bright red
    cout<<"\n"<<
          " **  **"<<"\n"<<
          " **  ** ****** **  **    **      ** ****** ***   **"<<"\n"<<
          "  ** ** ****** **  **    **      ** ****** ****  **"<<"\n"<<
          "   **** **  ** **  **    **  **  ** **  ** ** ** **"<<"\n"<<
          "     ** **  ** **  **    ** **** ** **  ** **  ****"<<"\n"<<
          "     ** ****** ******    ****  **** ****** **   ***"<<"\n"<<
          "     ** ****** ******    ***    *** ****** **    ** * * * * * *"<<endl;
    //this statement will change everything that is displayed underneath it to default color, green text with black background
    SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<"\nThe full word was: \""<<randWord<<"\"\n"<<endl;
}

//Message to be displayed if the player lose the game
//The parameter is for the full word that was to be guessed. It will be displayed underneath the message
void gameLost(string randWord)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);//creating an object for the color manipulation
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY); //changing the color of the text to bright red
    cout<<"\n\n"<<
          " **   **"<<"\n"<<
	      "  **  ** ****** **  **    **      ****** ******* ********"<<"\n"<<
          "   ** ** ****** **  **    **      ****** ******* ********"<<"\n"<<
	      "    **** **  ** **  **    **      **  ** **      **		"<<"\n"<<
	      "      ** **  ** **  **    **      **  ** ******* *****	"<<"\n"<<
	      "      ** **  ** **  **    **      **  ** ******* *****	"<<"\n"<<
	      "      ** **  ** **  **    **      **  **      ** **		"<<"\n"<<
	      "      ** ****** ******    ******* ****** ******* ********"<<"\n"<<
	      "      ** ****** ******    ******* ****** ******* ******** * * * * * *"<<endl;
    //this statement will change everything that is displayed underneath it to default color, green text with black background
    SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<"\nThe full word was: \""<<randWord<<"\"\n"<<endl;
}


//Explanation of the game to the player and how it's played
void gameMode()
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //creating an object for the color manipulation
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY); //changing the color of the word "GAME" to bright red
    cout<<"\n\t|====|\n\t GAME\n\t|====|\n\n"<<endl;

    //changing the color of the text to bright blue
    SetConsoleTextAttribute(color, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout<<"WELCOME TO HANGMAN\n\nThe word to guess is represented by a row of stars(asterisks)\n"<<
        "If the guessing player suggests a letter which occurs in the word,\nthe letter will be written in its correct position."<<
        "If the suggested\nletter does not occur in the word,the amount of re-tries will be reduced\nby one."<<
        "Initially the player starts with nine(9) tries as the player misses\nthe re-tries decrease by one.\n"<<
        "The game is over when the amount of re-tries reach zero or the player\nguesses all the letters in the word before reaching the re-try limit.\n\n"<<endl;

    //changing the color of the text to bright red
    SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout<<" **  **   ****   ***   **  ********  ***     ***   ****   ***   **"<<"\n"<<
          " **  **  ******  ****  **  ********  ****   ****  ******  ****  **"<<"\n"<<
          " ******  **  **  ** ** **  **        ** ** ** **  **  **  ** ** **"<<"\n"<<
          " ******  ******  **  ****  **   ***  **  **** **  ******  **  ****"<<"\n"<<
          " **  **  **  **  **   ***  ********  **   **  **  **  **  **   ***"<<"\n"<<
          " **  **  **  **  **    **  ********  **       **  **  **  **    **"<<endl;

    //changing the color of the text to bright red
    SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"\n\n\t|=========|\n\t GAME PLAY\n\t|=========|\n\n"<<endl;

    //this statement will change everything that is displayed underneath it to green text with black background
    SetConsoleTextAttribute(color, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

/*
Human figures of the hanging man
every miss is associated with a hanging man figure
this function has two parameters, the amount of misses and the correct full word
*/
void Hangman_lifeTrys(int value)
{
    switch(value)
        {
            case 0:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 1:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 2:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |       "<<"\n"<<
                         "**            "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 3:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |      "<<"\n"<<
                         "**     /       "<<"\n"<<
                         "**    /        "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 4:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |      "<<"\n"<<
                         "**     / \\    "<<"\n"<<
                         "**    /   \\   "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 5:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |      "<<"\n"<<
                         "**     /|\\    "<<"\n"<<
                         "**    /   \\   "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 6:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |      "<<"\n"<<
                         "**     /|\\    "<<"\n"<<
                         "**    / | \\   "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 7:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |      "<<"\n"<<
                         "**     /|\\    "<<"\n"<<
                         "**    / | \\   "<<"\n"<<
                         "**     /       "<<"\n"<<
                         "**    /        "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 8:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |      "<<"\n"<<
                         "**     /|\\    "<<"\n"<<
                         "**    / | \\   "<<"\n"<<
                         "**     / \\    "<<"\n"<<
                         "**    /   \\   "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;break;

            case 9:cout<<"\n*********    "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      *      "<<"\n"<<
                         "**      0      "<<"\n"<<
                         "**      |      "<<"\n"<<
                         "**     /|\\    "<<"\n"<<
                         "**    / | \\   "<<"\n"<<
                         "**     / \\    "<<"\n"<<
                         "**   _/   \\_  "<<"\n"<<
                         "**             "<<"\n"<<
                         "***            "<<"\n"<<
                         "*****          "<<"\n"<<endl;

            //display an error message if entry is less than zero or exceed 9
            default:cout<<"\n...ERROR!!...\nentry is out of range."<<endl;
       }
}

/*
This is the core function of the game. This is the game play.
It has one parameter for the word that is to be guessed and the word is randomly selected.
*/
void checkWord(string randWord)
{
    string word = randWord;
    string display = word;
    char letter;
    int misses = 0, corrLetter = 0;
    string alreadyExistLetter = "", missedLetter = "", strCorrLetter = "";

    /*
    'corrLetter' adds all correct letters in the word
    'alreadyExistLetter' adds all the already entered letters
    'missedLetter' adds all the wrong/missed letters
    'strCorrLetter' adds all the correct letters
    */

    //replacting each letter in the word with a star(asteriks)
    for(int a = 0; a < display.length(); a++)
        display[a] = '*';

    while(corrLetter < word.length() && (misses != 9))
    {
        system(clearConsole);
        gameMode(); //function for displaying instructions of the game

        //Display information as you play the game
        cout<<"Missed:\t\t    "<<misses<<endl;
        cout<<"Word Length:\t    "<<word.length()<<endl;
        cout<<"Missed letters:\t    "<<missedLetter<<endl;
        cout<<"Existing letter(s): "<<alreadyExistLetter<<endl;

        bool corrGuess = false;
        bool dupLetter = false;

        Hangman_lifeTrys(misses);
        cout<<"Full word:\t"<<display<<"\n"<<endl;

        string strLetter;
        cout<<"Enter letter in the word:  ";
        cin>>strLetter;
        letter = tolower(strLetter.at(0)); //takes the first character entered and converts it to lowercase letters

        for(int i = 0; i <= word.length(); i++)
        {
            if(word[i] == letter)
            {
                if(word[i] == display[i])
                {
                    alreadyExistLetter = alreadyExistLetter + letter;   //stores the already existing letter
                    dupLetter = true;
                    break;
                }
                else
                {
                    display[i] = word[i];
                    corrLetter++;
                    strCorrLetter = strCorrLetter + letter;
                    if(corrLetter == randWord.length()){
                        gameWon(randWord);
                    }
                    corrGuess = true;
                   // break;
                }
            }
        }
        if(dupLetter)
        {
            continue;
        }
        if(!corrGuess)
        {
            misses++; //increment the amount of times you miss by one
            missedLetter = missedLetter + letter;   //stores the missed letters
            if(misses == 9){
                gameLost(randWord);
            }
        }
    }
    misses;
    alreadyExistLetter;
    missedLetter;
    strCorrLetter;
}

/*
Initial function that will be called by the main function
This function has a list of words that will be randomly selected and sent as an argument
to the 'checkWord()' function.
*/
void mainFunction()
{
    string option;   //variable for choosing to play the game again or not
    char opt;

    do
    {
        system(clearConsole);  //clears the console

        //Amount of words that will be used for guessing in the game
        const int MAX = 30;
        string words[MAX] = {"cryptanalyst", "cipherbreaker", "calculus", "python", "logarithm", "caroline", "zingizingi","cipher","cryptography","array",
                             "programming", "pseudocode", "algorithm", "procrastinate", "hangman", "headerfile", "modulus", "arithmetics","run","codeblocks",
                             "algebra", "debbuging", "compiler", "banele", "mississippi", "function", "processor", "binary", "computers", "mathematics"};

        //randomly select a word in the array
        srand(time(0));
        //the random numbers that will be generated will be between 0 and 25 and associated with the word position
        string randomWord = words[(0 + (rand()%MAX))];

        cout<<"\nDISPLAY\n=======\n"<<endl;

        //calls the checkWord function with the argument of the randomly selected word
        checkWord(randomWord);

        cout<<"\n\n=============================\n"<<
              "Would you like to play again?\nYes/No: ";
        cin>>option;
        opt = option.at(0);
        opt = tolower(opt);

    }
    while(opt != 'n');
}

//This is the main function of the entire program
int main()
{
    /*
    This string of code will maximise the console
    system("start /max")
    */
    system(clearConsole); //clear the console
    system(consoleColor); //changes to text color and background of the console
    system("title Hangman Game  *****  Developer: Cipher");
    mainFunction();

    return 0;
}
