#include <iostream>
#include <string>
#include "Fbullcowgame.h"

void PrintIntro();
void PlayGame();
void PrintGameSummary();
FString GetValidGuess();
bool PlayAgain();
Fbullcowgame Bcgame = Fbullcowgame();
int maxtries = Bcgame.MaxTries();
int curretntry = Bcgame.GetCurrentTry();

// the entry of the game
int main()
{

	do
	{
		PrintIntro();
		PlayGame();

	} while (PlayAgain());

	return 0;
}
void PlayGame()
{
	Bcgame.Reset();


	
	// loop asking for guesses until the game won.
	// is not won and there are still tries remaining
	while(! Bcgame.IsGameWon() && Bcgame.GetCurrentTry()<= maxtries)
	{
		FString Guess = GetValidGuess();

        // Submit valid guess to the game
	FBullCowCount BullCowCount =	Bcgame.SubmitValidGuess(Guess);
		//print number of BC
		// return guess to the user
	std::cout << "Bulls = " << BullCowCount.Bulls;
	std::cout << "  Cows = " << BullCowCount.Cows << std::endl;

	std::cout << std::endl;
	}
	PrintGameSummary();
	return;
}
//intro message
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows, a fun word geme.\nCan you guess the " << Bcgame.GetHiddenWordLenght()
		<< " letter isogram I'm thinking of?" << std::endl;
	return;
}
//get the guess from user

//TODO make loop checking valid

FString GetValidGuess()
{
	std::string Guess = "";

	EGuessStatus Status = EGuessStatus::Invalid_Guess;
	do {
		std::cout << "Try " << curretntry << " : please enter your guess: ";
		std::getline(std::cin, Guess);
		 Status = Bcgame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrog_Lenght:
			std::cout << "Please enter a " << Bcgame.GetHiddenWordLenght() << " letter word. \n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "please don't repeat the letters. \n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "please write the word in lowercase. \n";
			break;
		default:
	

			break;
		}std::cout << std::endl;
	} while (Status!= EGuessStatus::ok);
	{

	}
	return Guess;
}

bool PlayAgain()
{
	std::string Replay = "";
	std::cout << "Do you want to play again with the same word?(y/n)";
	std::getline(std::cin, Replay);

	return (Replay[0] == 'y') || (Replay[0] == 'Y');
}
void PrintGameSummary()
{
	if (Bcgame.IsGameWon())
	{
		std::cout << "Well done - you won!! :D \n";
	}
	else
	{
		std::cout << "Better luck next time :( \n";

	}


}
