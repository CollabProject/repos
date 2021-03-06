/*
* console executable that makes use of the BullCow class
* acts as the view in a MVC pattern
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiates the game

int main()
{	
	do 
	{
		PrintIntro();
		PlayGame();
	}
	
	while (AskToPlayAgain());	
	
	return 0;
}

void PrintIntro()
{
	constexpr int32 NumberOfTurns = 9;
	std::cout << "Welcome to the Bulls and Cows, a guessing game" << std::endl;
	std::cout << "Can u guess the " << NumberOfTurns;
	std::cout << " letter isogram I'm thinking of?" << std::endl;

	return;
}

void PlayGame()
{	
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	for (int32 count = 1; count < MaxTries; count++)
	{
		FText Guess = GetGuess();

		FBullCowCount BullCowCount = BCGame.SumbitGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.BullCount;
		std::cout << "Cows = " << BullCowCount.CowCount << std::endl;

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

// Get a guess from the player and then repeat it back to them
FText GetGuess()
{
	int32 CurrentTries = BCGame.GetCurrentTry();

	std::cout << "Enter your guess: ";
	FText Guess = "";
	std::getline(std::cin, Guess);	

	return Guess; 
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y') || (Response[0] == 'Y');
	std::cout << std::endl;
}