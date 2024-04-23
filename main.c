#include <stdio.h>
#include <string.h>



typedef struct {
     int value;
     char action[15];
} card;



int main(){
     // declare and initialize variables
     int playerChoice = 0;

     
     // prompt player to shuffle new deck or use old deck
     printf("Welcome to Game of Trains\n Would you like to start from new (enter 1) or load a deck (enter 2)?");
     scanf("%d",&playerChoice);
     while(playerChoice != (1 || 2)){
          printf("Sorry not a valid choice, 1 for new deck, 2 to load deck from file:")
          scanf("%d",&playerChoice);
     }
     

     // deal cards to each player
     

      // go through initial game rules/start game
     // player 1 draws and replaces card
     // player 2 draws two cards and discards one


     //  while loop to let game go continuously




  
  return 0;
}


// void initializeDeck(card *deck);
// Creates a deck using a card array

// void shuffleDeck(card *deck);
// Shuffles the cards in a given deck 

// void dealCards(card *deck);
// Deals cards to the two players

// void sortCards(card *player1, card *player2);
// Sorts cards that are given to the players in ascending order

// void printCards(card *deck);
// Prints all the cards currently on the table to give a visual to the users

// void loadDeck(card *deck, FILE *inp);
// Loads a deck from a preset file for testing purposes as defined in the project description


