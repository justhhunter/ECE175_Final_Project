#include <stdio.h>
#include <string.h>

const char* numVisuals[] = {
     "|\n|\n|\n|\n|\n"//1
     "------\n     |\n     |\n     |\n------\n|\n|\n|\n------"//2

}

typedef struct {
     int value;
     char action[15];
} card;


void buildDeck(card *deck);
void printCards(card *player1, card *player2, card *centerRow);
void printSingleCard(int cardVal);

int main(){
     // declare and initialize variables
     card deck[84];
     card discardPile[84];
     card player1[7];
     card player2[7];
     card centerRow[8]; //unsure of total for center row, double check before turn in
     int playerChoice = 0;

     
     // prompt player to shuffle new deck or use old deck
     printf("Welcome to Game of Trains\n Would you like to start from new (enter 1) or load a deck (enter 2)?");
     scanf("%d",&playerChoice);
     while((playerChoice != 1) && (playerChoice != 2)){
          printf("Sorry not a valid choice, 1 for new deck, 2 to load deck from file:");
          scanf("%d",&playerChoice);
     }
     

     // deal cards to each player
     

      // go through initial game rules/start game
     // player 1 draws and replaces card
     // player 2 draws two cards and discards one


     //  while loop to let game go continuously




  
  return 0;
}

// void takeTurn(card *player, card *centerSpace, card *deck);
// Allows player to take their turn

// void buildDeck(card *deck);
// Creates a deck using a card array of size 84
void buildDeck(card *deck){

     // iterate through entire deck to initialize cards
     for(int i = 0; i < 84; i++){
          deck[i].value = i+1;
          // when we learn all card values we can create a process to disperse them in correct numbers
          // until then well use a placeholder
          strcpy(deck[i].action, "placeholder");
     }
     
}

// void shuffleDeck(card *deck);
// Shuffles the cards in a given deck 

// void dealCards(card *deck);
// Deals cards to the two players

// void sortCards(card *player1, card *player2);
// Sorts cards that are given to the players in descending order

// void printCards(card *player1, card *player2, card *centerRow);
// Prints all the cards currently on the table to give a visual to the users
void printCards(card *player1, card *player2, card *centerRow){
     for(int i = 0; i < 7; i++){
           
     }
     for(int j = 0; j < 8; j++){
           
     }
     for(int k = 0; k < 7; k++){
           
     }
}

void printSingleCard(int cardVal){
     // check to see if there are two digits
     if(cardVal > 9){// separate digits for printing purposes
          int tensDigit = cardVal / 10;
          int onesDigit = cardVal % 10;
     }

}

// void loadDeck(card *deck, FILE *inp);
// Loads a deck from a preset file for testing purposes as defined in the project description


