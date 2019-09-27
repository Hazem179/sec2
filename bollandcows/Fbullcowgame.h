#pragma once
#include <string>
using FString = std::string;
using int32 = int;

// all values intialised to zero 
struct FBullCowCount
{
	int32 Bulls =0;
	int32 Cows =0;

};
enum  EGuessStatus
{
	Invalid_Guess,
	ok,
	Not_Isogram,
	Wrog_Lenght,
	Not_Lowercase,
};
class Fbullcowgame
{
public:
	int32 MaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;
	int32 GetHiddenWordLenght() const;
	Fbullcowgame();
	void Reset();// TODO make it return value
	EGuessStatus CheckGuessValidity(FString);
	FBullCowCount SubmitValidGuess(FString Guess);
	//ignore this.
private:
	//constructor initialisationed
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString  MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowerCase(FString)const;

};