#include <stdio.h>
#include <string.h>



typedef struct {
     int value;
     char action[15];
} card;


void buildDeck(card *deck);
void printCards(card *player1, card *player2, card *centerRow);

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
     

     if(playerChoice == 1){
        // build new deck
        buildDeck(deck);
          // shuffle cards
         }else if(playerChoice == 2){
           // load deck from file
         }
         

      
      
   

     // deal cards to each player
     

      // go through initial game rules/start game
     // player 1 draws and replaces card
     // player 2 draws two cards and discards one


     //  while loop to let game go continuously




  
  return 0;
}



// void printCards(card *player1, card *player2, card *centerRow);
// Prints all the cards in both players hands and the center row
void printCards(card *player1, card *player2, card *centerRow){
   
   printf("player1s hand: ");
   // prints all player 2s cards to console
   for(int i = 0; i < 7; i++){
      printf("%d %s", player2[i].value, player2[i].action);
      printf("\t");
      }
      
   printf("\n");// newline to separate rows of cards
   printf("center row: ");
   
   // prints all center row cards to console
   for(int j = 0; j < 8; j++){
      if(centerRow[j].value != 0){
         printf("%d %s", centerRow[j].value, centerRow[j].action);
         printf("\t");
         }
      }
      
   printf("\n");// newline to separate rows of cards
   printf("player2s hand: ");
   
   // prints all player 1s cards to console
   for(int k = 0; k < 7; k++){
      printf("%d %s", player1[k].value, player1[k].action);
      printf("\t");
      }
      
   printf("\n");// newline to separate rows of cards
      
   }

// void takeTurn(card *player, card *centerSpace, card *deck);
// Allows player to take their turn

// void buildDeck(card *deck);
// Creates a deck using a card array of size 84
void buildDeck(card *deck){

      int actionNum = 0;
      int modNum = 0;
     // iterate through entire deck to initialize cards
     for(int i = 0; i < 84; i++){
          deck[i].value = i+1;
          // modulus actionNum to rotate through 8 abilities for assignment
          actionNum++;
          modNum = actionNum % 8;

          // switch between all 8 abilities
          switch(modNum){
             case 1: strcpy(deck[i].action,"shift2Right"); break;
             case 2: strcpy(deck[i].action,"protect"); break;
             case 3: strcpy(deck[i].action,"shift2Left"); break;
             case 4: strcpy(deck[i].action,"swapAdjacent"); break;
             case 5: strcpy(deck[i].action,"removeMiddle"); break;
             case 6: strcpy(deck[i].action,"removeRight"); break;
             case 7: strcpy(deck[i].action,"removeLeft"); break;
             case 8: strcpy(deck[i].action,"swapSkip1Card"); break;
             
             }
          
          
     }
     
}

// void shuffleDeck(card *deck);
// Shuffles the cards in a given deck 

// void dealCards(card *deck);
// Deals cards to the two players

// void sortCards(card *player1, card *player2);
// Sorts cards that are given to the players in descending order

// void loadDeck(card *deck, FILE *inp);
// Loads a deck from a preset file for testing purposes as defined in the project description


