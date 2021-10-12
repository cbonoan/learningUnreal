// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    InitGame();

    //PrintLine(TEXT("The Hidden Word is: %s\nIt is %i characters long."), *HiddenWord, HiddenWord.Len()); // Debug Line 
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{    
    if(!bGameOver) {
        ProcessGuess(Input);
        
    } else {
        ClearScreen();
        InitGame();
    }
}

void UBullCowCartridge::InitGame() 
{
    // Welcome player 
    PrintLine(TEXT("Welcome to Bull Cows!")); // Any string needs to be wrapped in the TEXT macro

    HiddenWord = TEXT("cake"); 
    lives = HiddenWord.Len(); 
    bGameOver = false; 

    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); // Magic number remove!
    PrintLine(TEXT("You have %i lives. Good luck!"), lives);
    PrintLine(TEXT("Enter your guess then\npress ENTER to continue..."));

}

void UBullCowCartridge::EndGame(bool correctGuess) 
{
    bGameOver = true; 
    ClearScreen();
    if(!correctGuess) {
        PrintLine(TEXT("You have no more lives! Try again next time!"));
        PrintLine(TEXT("The hidden word was: %s"), *HiddenWord);
    } else {
        PrintLine(TEXT("That's the RIGHT word! You WIN!"));
    }
    PrintLine(TEXT("Press ENTER to play again..."));
}

void UBullCowCartridge::ProcessGuess(FString Guess) 
{
    if(Guess == HiddenWord) {
        EndGame(true); 
        return;
    }

    // Check isogram
    // if (!isIsogram) {
    //    PrintLine(TEXT("No repeating letters, guess again.")); 
    // }
    
    if(Guess.Len() != HiddenWord.Len()) {
        PrintLine(TEXT("That's the wrong word!"));
        PrintLine(TEXT("The Hidden Word is %i characters long. No lives will be taken away."), HiddenWord.Len());
        return;
    }
    
    --lives; 
    if(lives > 1) {
        PrintLine(TEXT("You lost a life! You now have %i lives!"), lives);
    } else if(lives == 1){
        PrintLine(TEXT("You lost a life! You now have %i life!!! Guess carefully..."), lives);
    }
    
    if(lives == 0) {
        EndGame(false);
    }
    
    // Show player Bulls and Cows
}