#include<iostream>
#include<cstdlib>
using namespace std;

// Enum for game choices
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };

// Enum for round winners
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

// Struct to hold information about each round
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};

// Struct to store final game results
struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short Computer2WinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName = "";
};

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        // The PlayGame function will be implemented later.
        // Then, we will display the Game Over screen.
        ShowGameOverScreen();
        ShowFinalGameResults();
        cout << endl << Tabs(3) << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
    //Seeds the random number generator in c++, called only once
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}