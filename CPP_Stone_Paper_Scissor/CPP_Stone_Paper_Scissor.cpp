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

// Function to get Player1's choice with input validation
enGameChoice ReadPlayer1Choice()
{
    short Choice = 1;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enGameChoice)Choice;
}

stGameResults PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound [" << GameRound << "] begins:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

        if (RoundInfo.Winner == enWinner::Player1) Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer) ComputerWinTimes++;
        else DrawTimes++;

        PrintRoundResults(RoundInfo);
    }
    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}

void ShowGameOverScreen()
{
    cout << Tabs(2) <<
        "__________________________________________________________\n\n";
    cout << Tabs(2) << " +++ G a m e O v e r
        ++ + \n";
        cout << Tabs(2) <<
        "__________________________________________________________\n\n";
}

// Function to read the number of rounds from the user
short ReadHowManyRounds()
{
    short GameRounds;
    do
    {
        cout << "How Many Rounds (1 to 10)? ";
        cin >> GameRounds;
    } while (GameRounds < 1 || GameRounds > 10);
    return GameRounds;
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