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

void ShowGameOverScreen()
{
    cout << Tabs(2) <<
        "__________________________________________________________\n\n";
    cout << Tabs(2) << " +++ G a m e O v e r
        ++ + \n";
        cout << Tabs(2) <<
        "__________________________________________________________\n\n";
}

// Function to reset the console screen
void ResetScreen()
{
    system("cls");
    system("color 0F");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        // This struct will store the final result of all rounds.
        // The PlayGame function will create game rounds after asking for the number of rounds.
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
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