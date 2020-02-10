#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 BullCount = 0;
	int32 CowCount = 0;
};

class FBullCowGame
{

public:

	FBullCowGame(); // Constructor
	
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset();
	bool CheckGuessValidity(FString);

	//counts the number of bulls and cows and increases the valid guess
	FBullCowCount SumbitGuess(FString);

private:

	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
};