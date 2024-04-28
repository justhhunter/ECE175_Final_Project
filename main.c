#include <stdio.h>
#include <string.h>



typedef struct {
     int value;
     char action[15];
} card;


void buildDeck(card *deck);
void printCards(card *player1, card *player2, card *centerRow);
void dealCards(card deck[], card p1[], card p2[]);
void loadDeck(card *deck, FILE *file);
void sortCards(card *player1, card *player2);
void initializeCards(card *player1, card *player2, card *deck, card *centerRow);

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
     // initialize cards
     initializeCards(player1,player2,deck,centerRow);

     if(playerChoice == 1){
        // build new deck
        buildDeck(deck);
          // shuffle deck
          
     }else if(playerChoice == 2){
           // load deck from file
          // check file is correctly opened
          FILE *file = fopen("sampledeck.txt","r");
          if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
             }
          loadDeck(deck,file);
          fclose(file); // close file after use
     }
         
     
      

     // deal cards to each player
     dealCards(deck, player1, player2);
     
     // sort each players hand
     
     printCards(player1,player2,centerRow);
     
      // go through initial game rules/start game
     // player 1 draws and replaces card
     // player 2 draws two cards and discards one


     //  while loop to let game go continuously




  
  return 0;
}


// void startGame(card player1[], card player2[], card deck[], card centerRow[]);



// void printCards(card *player1, card *player2, card *centerRow);
// Prints all the cards in both players hands and the center row
void printCards(card player1[], card player2[], card centerRow[]){

   printf("\n");
   printf("player1s hand:\n");// prints all player 1s cards to console
   for(int i = 0; i < 7; i++){// prints top of cards
      if(player1[i].value > 9){printf("-");}// prints extra incase of double digits in card number
      printf("-");
      for(int j = strlen(player1[i].action) + 3; j > 0; j--){
         printf("-");
      }
      printf(" ");
   }
   printf("\n");

   // prints partial of card body
   for(int i = 0; i < 7; i++){
      printf("|");
      if(player1[i].value > 9){printf(" ");}
      for(int j = strlen(player1[i].action) + 2; j > 0; j--){
         printf(" ");
      }
      printf("|");
      printf(" ");
   }
   printf("\n");

   // prints card information
   for(int i = 0; i < 7; i++){
      printf("|");
      printf("%d %s", player1[i].value, player2[i].action);
      printf("| ");
      }

   printf("\n");
   // prints partial of card body
   for(int i = 0; i < 7; i++){
      printf("|");
      if(player1[i].value > 9){printf(" ");}
      for(int j = strlen(player1[i].action) + 2; j > 0; j--){
         printf(" ");
      }
      printf("|");
      printf(" ");
   }
   printf("\n");
      
   // prints bottom of cards
   for(int i = 0; i < 7; i++){
      printf("-");
      if(player1[i].value > 9){printf("-");}
      for(int j = strlen(player1[i].action) + 3; j > 0; j--){
         printf("-");
      }
      printf(" ");
   }
   printf("\n");
      
   printf("\n");
   printf("center row:\n");
   // prints center row to console
   // prints top of cards
   for(int i = 0; i < 7; i++){
      if(centerRow[i].value > 9){printf("-");}// prints extra incase of double digits in card number
      printf("-");
      for(int j = strlen(centerRow[i].action) + 3; j > 0; j--){
         printf("-");
      }
      printf(" ");
   }
   printf("\n");

   // prints partial of card body
   for(int i = 0; i < 7; i++){
      printf("|");
      if(centerRow[i].value > 9){printf(" ");}
      for(int j = strlen(centerRow[i].action) + 2; j > 0; j--){
         printf(" ");
      }
      printf("|");
      printf(" ");
   }
   printf("\n");

   // prints card information
   for(int i = 0; i < 7; i++){
      printf("|");
      printf("%d %s", centerRow[i].value, centerRow[i].action);
      printf("| ");
      }
      
   printf("\n");
   // prints partial of card body
   for(int i = 0; i < 7; i++){
      printf("|");
      if(centerRow[i].value > 9){printf(" ");}
      for(int j = strlen(centerRow[i].action) + 2; j > 0; j--){
         printf(" ");
      }
      printf("|");
      printf(" ");
   }
   printf("\n");
      
   // prints bottom of cards
   for(int i = 0; i < 7; i++){
      printf("-");
      if(centerRow[i].value > 9){printf("-");}
      for(int j = strlen(centerRow[i].action) + 3; j > 0; j--){
         printf("-");
      }
      printf(" ");
   }
   printf("\n");
      printf("\n");
   printf("player2s hand:\n");
   // prints all player 2s cards to console
   // prints top of cards
   for(int i = 0; i < 7; i++){
      if(player2[i].value > 9){printf("-");}// prints extra incase of double digits in card number
      printf("-");
      for(int j = strlen(player2[i].action) + 3; j > 0; j--){
         printf("-");
      }
      printf(" ");
   }
   printf("\n");

   // prints partial of card body
   for(int i = 0; i < 7; i++){
      printf("|");
      if(player2[i].value > 9){printf(" ");}
      for(int j = strlen(player2[i].action) + 2; j > 0; j--){
         printf(" ");
      }
      printf("|");
      printf(" ");
   }
   printf("\n");

   // prints card information
   for(int i = 0; i < 7; i++){
      printf("|");
      printf("%d %s", player2[i].value, player2[i].action);
      printf("| ");
      }
      
   printf("\n");
   // prints partial of card body
   for(int i = 0; i < 7; i++){
      printf("|");
      if(player2[i].value > 9){printf(" ");}
      for(int j = strlen(player2[i].action) + 2; j > 0; j--){
         printf(" ");
      }
      printf("|");
      printf(" ");
   }
   printf("\n");
      
   // prints bottom of cards
   for(int i = 0; i < 7; i++){
      printf("-");
      if(player2[i].value > 9){printf("-");}
      for(int j = strlen(player2[i].action) + 3; j > 0; j--){
         printf("-");
      }
      printf(" ");
   }
   printf("\n");
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

// void dealCards(card deck[], card p1[], card p2[]);
// Deals cards to the two players
void dealCards(card deck[], card p1[], card p2[]) {
     int i;
     int deckNum = 83;
     for(i = 0; i < 7; i++) {
          //change the player's respective card to the value in the deck, then indicate that the card is no longer in the deck
          strcpy(p1[i].action, deck[deckNum].action);
          p1[i].value = deck[deckNum].value;
          deck[deckNum].value = 0;
          strcpy(deck[deckNum].action, "placeholder");
          deckNum -= 1;
          
          strcpy(p2[i].action, deck[deckNum].action);
          p2[i].value = deck[deckNum].value;
          deck[deckNum].value = 0;
          strcpy(deck[deckNum].action, "placeholder");
          deckNum -= 1;
     }
}

// void sortCards(card *player1, card *player2);
// Sorts cards that are given to the players in descending order
void sortCards(card p1[], card p2[]) {
     int i,j;
     int deckSize = 84;
     card temp;
     for (i = 1; i < deckSize; i++) {
          j = i;
          while (j > 0 && p1[j].value > p1[j - 1].value) {
               temp = p1[j];
               p1[j] = p1[j - 1];
               p1[j - 1] = temp;
               --j;
          }
          j =i;
          while (j > 0 && p2[j].value > p2[j - 1].value) {
               temp = p2[j];
               p2[j] = p2[j - 1];
               p2[j - 1] = temp;
               --j;
          }
     }
}

// void loadDeck(card *deck, FILE *file);
// Loads a deck from a preset file for testing purposes as defined in the project description
void loadDeck(card *deck, FILE *file){
     // iterate through entire file and assign to deck value and actions
     for(int i = 0; i < 84; i++){
          fscanf(file,"%d %[^\n]",&deck[i].value,deck[i].action);
     }
}

//void initializeCards(card *player1, card *player2, card *deck, card *centerRow)
// initializes card arrays for card type struct
void initializeCards(card *player1, card *player2, card *deck, card *centerRow){
     int size = 84;
     for (int i = 0; i < size; i++) {
        deck[i].value = 0;               
        strcpy(deck[i].action, "placeholder"); 
     }
     
     size = 7;
     for (int j = 0; j < size; j++) {
        player1[j].value = 0;              
        strcpy(player1[j].action, "placeholder"); 
     }

     
     for (int k = 0; k < size; k++) {
        player2[k].value = 0;              
        strcpy(player2[k].action, "placeholder"); 
     }

     size = 8;
     for (int h = 0; h < size; h++) {
        centerRow[h].value = 0;             
        strcpy(centerRow[h].action, "placeholder"); 
     }
}
