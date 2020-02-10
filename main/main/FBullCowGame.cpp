#include "stdafx.h"
#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame()
{
	Reset();
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

void FBullCowGame::Reset()
{

	constexpr int32 MaxTries = 8;
	MyMaxTries = MaxTries;
	MyCurrentTry = 1;

	const FString HiddenWord = "planet";
	MyHiddenWord = HiddenWord;

	return;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// Receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SumbitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;

	//loop through all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[i])
			{
				if (i == j)
				{
					BullCowCount.BullCount++;
				}
			}
			else
			{
				BullCowCount.CowCount++;
			}
		}
	}

	return BullCowCount;
}