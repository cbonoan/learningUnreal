// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    // Setting up game
    InitGame();

    // Welcome player 
    PrintLine(TEXT("Welcome to Bull Cows!")); // Any string needs to be wrapped in the TEXT macro
    PrintLine(TEXT("Guess the 4 letter word!")); // Magic number remove!
    PrintLine(TEXT("Press ENTER to continue..."));

    // Prompt player guess
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Checking Player's guess

    if(Input == HiddenWord) {
        // Player wins
        // Show how many guesses it took?
        PrintLine(TEXT("That's the RIGHT word!"));

        // Check if player wants to play again or quit
    } else {
        // Deprecate from lives 
        PrintLine(TEXT("That's the WRONG word!"));
    }

    // Check if Isogram 
        // Prompt to guess again
    // Check right number of characters
        // Prompt to guess again 
    
    // Remove life

    // Check if lives > 0 
    // if yes guess again and show remaining lives
    // if no GameOver and HiddenWord
        // prompt player to play again, Press ENTER to play again?
        // Check user input 
        // PlayAgain or Quit 
}

void UBullCowCartridge::InitGame() 
{
    HiddenWord = TEXT("cake"); 
    lives = 5; 
}