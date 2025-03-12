# Rock-Paper-Scissors Game in C++ 🎮🎲🖥️

## Overview 🎯📌🔍
This C++ program implements the classic Rock-Paper-Scissors game where a player competes against the computer. The program follows best practices such as modular programming, separation of concerns, and the Single Responsibility Principle to ensure clean, maintainable, and scalable code. 🎉

## Features 🚀🔥🎮
- Interactive console-based gameplay
- Randomized computer moves using a seeded random number generator
- Multiple rounds with automatic score tracking
- Clear display of round results and final game winner
- Structured code with enums, structures, and functions for modular design

## Table of Contents 📖📝🔍
1. [Installation](#installation)
2. [How to Play](#how-to-play)
3. [Code Breakdown](#code-breakdown)
   - [Importing Libraries](#importing-libraries)
   - [Enums for Choices & Winners](#enums-for-choices--winners)
   - [Game Structures](#game-structures)
   - [Generating Random Moves](#generating-random-moves)
   - [Determining the Winner](#determining-the-winner)
   - [Displaying Results](#displaying-results)
   - [Game Loop](#game-loop)
4. [Code Structure](#code-structure)
5. [Best Practices](#best-practices)
6. [License](#license)

## Installation 🛠️📂🔧
To run this program on your system:
1. Ensure you have a C++ compiler installed (e.g., g++, clang++)
2. Download the source code.
3. Compile using the following command:
   ```bash
   g++ -o RockPaperScissors main.cpp
   ```
4. Run the program:
   ```bash
   ./RockPaperScissors
   ```

## How to Play 🎮🕹️🎲
- The player is prompted to choose Stone (1), Paper (2), or Scissors (3).
- The computer randomly selects a move.
- The winner of each round is displayed.
- After a fixed number of rounds (default: 3), the overall game winner is announced.
- The player can choose to play again or exit. 🎉

## Code Breakdown 🧐📜💻

### Importing Libraries 📚🔗🛠️
```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
```
- `iostream`: For input/output operations.
- `cstdlib`: Used for system functions like clearing the screen.
- `ctime`: Used for seeding the random number generator.
- `using namespace std;` allows the use of standard functions without prefixing `std::`. 🎯

### Enums for Choices & Winners 🎭🎲🏆
```cpp
enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };
```
- Defines available choices (Stone, Paper, Scissors).
- Defines possible outcomes (Player1 wins, Computer wins, Draw). 🏅

### Game Structures 🏗️📊🔢
```cpp
struct stRoundInfo {
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};
```
- Stores details of an individual round. 🎯

```cpp
struct stGameResults {
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner GameWinner;
    string WinnerName;
};
```
- Stores overall game results. 🏆

### Generating Random Moves 🎲🔄🤖
```cpp
int RandomNumber(int From, int To) {
    return rand() % (To - From + 1) + From;
}

enGameChoice GetComputerChoice() {
    return (enGameChoice) RandomNumber(1, 3);
}
```
- Generates a random number for the computer’s choice. 🔄

### Determining the Winner 🏆⚖️🎮
```cpp
enWinner WhoWonTheRound(stRoundInfo RoundInfo) {
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice) {
    case enGameChoice::Stone:
        return (RoundInfo.ComputerChoice == enGameChoice::Paper) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Paper:
        return (RoundInfo.ComputerChoice == enGameChoice::Scissors) ? enWinner::Computer : enWinner::Player1;
    case enGameChoice::Scissors:
        return (RoundInfo.ComputerChoice == enGameChoice::Stone) ? enWinner::Computer : enWinner::Player1;
    }
}
```
- Implements Rock-Paper-Scissors rules to determine round winners. 🥇

### Displaying Results 📊📢🏁
```cpp
void PrintRoundResults(stRoundInfo RoundInfo) {
    cout << "\n____________ Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   : [" << RoundInfo.WinnerName << "]\n";
}
```
- Displays the result of each round. 📢

### Game Loop 🔄🎮🕹️
```cpp
void StartGame() {
    char PlayAgain = 'Y';
    do {
        system("cls");
        stGameResults GameResults = PlayGame(3);
        cout << "\nGame Over! Winner: " << GameResults.WinnerName << endl;
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
}
```
- Controls the game flow and asks if the player wants to play again. 🔄

## Code Structure 🏗️🛠️📂
- **main.cpp**: Contains the game logic.
- **Functions**:
  - `RandomNumber(int, int)`: Generates a random number.
  - `GetComputerChoice()`: Picks a random move for the computer.
  - `WhoWonTheRound(stRoundInfo)`: Determines the winner of a round.
  - `WhoWonTheGame(short, short)`: Determines the overall game winner.
  - `ChoiceName(enGameChoice)`, `WinnerName(enWinner)`: Convert enums to readable text.
  - `PrintRoundResults(stRoundInfo)`: Displays round results.
  - `PlayGame(short)`: Runs the game for a set number of rounds.
  - `StartGame()`: Main game loop. 🎯

## Best Practices ✅🛠️💡
- **Modular Programming**
- **Separation of Concerns**
- **Use of Enums & Structs**
- **Randomized Moves**

## License 📜⚖️✅
This project is licensed under the MIT License. 🎉

