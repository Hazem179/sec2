#include "Fbullcowgame.h"
#include<map>
#define TMap std::map
void Fbullcowgame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyCurrentTry = 1;
	bGameIsWon = false;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

int Fbullcowgame::MaxTries() const { return MyMaxTries; }; // TODO make it return value

int Fbullcowgame::GetCurrentTry() const { return MyCurrentTry; };

bool Fbullcowgame::IsGameWon() const { return bGameIsWon; }

int32 Fbullcowgame::GetHiddenWordLenght() const
{
	return MyHiddenWord.length();
}

Fbullcowgame::Fbullcowgame()
{
	Reset();
}

EGuessStatus Fbullcowgame::CheckGuessValidity(FString Guess) { 

	if (! IsIsogram(Guess))// if the guess isn't an isogram
	{

		return EGuessStatus::Not_Isogram;

	}
	else if (! IsLowerCase(Guess))// if the guess isn't all lowercase
	{

		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLenght()) // if the guess length is wrong
	{
		return EGuessStatus::Wrog_Lenght;
	}
	else
	{
		return EGuessStatus::ok;
	}




};//TODO make actual error
//recieves a VALID guess , incriments turn
FBullCowCount Fbullcowgame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	//compare letters against the hidden word
	int32 WordLenght = MyHiddenWord.length();
	for (int32 MHWchar = 0; MHWchar < WordLenght; MHWchar++)
	{

		for (int32 Gchar = 0; Gchar < WordLenght; Gchar++)
		{
			if (Guess[Gchar] == MyHiddenWord[MHWchar])
			{
				if (MHWchar == Gchar)
				{
					BullCowCount.Bulls++;

				}
				else
				{
					BullCowCount.Cows++;

				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLenght)
	{
		bGameIsWon = true;

	}
	else {
		bGameIsWon = false;

	}
	return BullCowCount;

}
bool Fbullcowgame::IsIsogram(FString Word) const
{
	TMap <char, bool> LetterSeen;

 	if (Word.length() <= 1) {return true;}

	for (char Letter:Word)
	{
		Letter = towlower(Letter);

		if (LetterSeen[Letter])
		{
			return false;
		}
		else
		{
			LetterSeen[Letter] = true;
		}

	}
	return true;
}
bool Fbullcowgame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}

	return true;
}
;

