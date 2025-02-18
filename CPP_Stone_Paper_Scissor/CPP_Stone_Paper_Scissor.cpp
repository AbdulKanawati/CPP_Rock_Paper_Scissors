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

int main()
{
    
}