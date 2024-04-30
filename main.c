#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct {
     int value;
     char action[15];
     int isProtected;
} card;


void buildDeck(card *deck);
void printCards(card *player1, card *player2, card *centerRow);
void dealCards(card deck[], card p1[], card p2[]);
void loadDeck(card *deck, FILE *file);
void sortCards(sortCards(card p1[], card p2[]);
void initializeCards(card *player1, card *player2, card *deck, card *centerRow);
void startGame(card player1[], card player2[], card deck[], card centerRow[]);
void shuffleDeck(card *deck);



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
         shuffleDeck(deck);
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
      //sortCards(player1,player2);
     sortCards(player1, player2);
      printCards(player1,player2,centerRow);
      // start game
      startGame(player1, player2, deck, centerRow);
     printCards(player1,player2,centerRow);

     
      
      
     //  while loop to let game go continuously
      //for(int i = 84; i > -1;){
         //




  
  return 0;
}





// void startGame(card player1[], card player2[], card deck[], card centerRow[]);
// Does the initial player 1 and player 2 moves to initiate the game
void startGame(card player1[], card player2[], card deck[], card centerRow[]){
   printf("\n***************GAMESTART***************\nDeck has been shuffled and the cards have been dealt\n");
   int j = 0;
   // player 1 draw card
   for(int i = 83; i > 0; i--){
      if(deck[i].value == 0)
         {continue;}else{ // check for cards in deck
            int replacement = 0;
            // take input for card number from user
            printf("PLayer1 pulls a card to start the game\nYou have pulled %d %s card!", deck[i].value,deck[i].action);
            printf("\nPlayer 1 enter the number of the card you would like to replace: ");
            scanf("%d", &replacement);
            // search through players hand and replace with new card
            for(int j = 0; j < 7; j++){
               if(replacement == player1[j].value){
                  centerRow[0].value = player1[j].value;
                  strcpy(centerRow[0].action,player1[j].action);
                  player1[j].value = deck[i].value;
                  strcpy(player1[j].action,deck[i].action);
                  deck[i].value = 0;
                  strcpy(deck[i].action,"placeholder");
                  break;
                  }
               }
            break;
         }
      }
      printCards(player1,player2,centerRow);
   // player 2 draw 2 cards and pick one
   for(int k = 83; k > 0; k--){
      if(deck[k].value == 0){
         continue;
         }else{
            int p2Choice = 0;
            int p2handremovenum = 0;
            printf("\nPlayer2 draws two cards\nYou have pulled %d %s and %d %s cards!",deck[k].value,deck[k].action,deck[k-1].value,deck[k-1].action);
            printf("\nPlayer2 choose one of the cards:");
            scanf("%d",&p2Choice);
            printf("Choose a card from your hand to discard:");
            scanf("%d",&p2handremovenum);
            for(int h = 0; h < 7; h++){
               if(p2handremovenum == player2[h].value){// search through hand to replace with new card
               // move card to center row
                  centerRow[1].value = player2[h].value;
                  strcpy(centerRow[1].action,player2[h].action);
                  player2[h].value = p2Choice;
                  for(int i = 83; i > 0; i--){
                     if(deck[i].value == p2Choice){
                        strcpy(player2[h].action,deck[i].action);
                        deck[i].value == 0;
                        strcpy(deck[i].action,"placeholder");
                        }
                     }
                  }
               }
            break;
            }
      }
      
   
   
      
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
             case 0: strcpy(deck[i].action,"shift2Right"); break;
             case 1: strcpy(deck[i].action,"protect"); break;
             case 2: strcpy(deck[i].action,"shift2Left"); break;
             case 3: strcpy(deck[i].action,"swapAdjacent"); break;
             case 4: strcpy(deck[i].action,"removeMiddle"); break;
             case 5: strcpy(deck[i].action,"removeRight"); break;
             case 6: strcpy(deck[i].action,"removeLeft"); break;
             case 7: strcpy(deck[i].action,"swapSkip1Card"); break;
             
             }
          
          
     }
     
}

// void shuffleDeck(card *deck);
// Shuffles the cards in a given deck of 84 cards
void shuffleDeck(card *deck) {
   int n = 84;
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        
        // swap cards using temp
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}


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
     int handSize = 7;
     card temp;
     temp.value = 0;
     strcpy(temp.action, "tempAction");
     
     for (i = 1; i < handSize; i++) {
          j = i;
          while (j > 0 && p1[j].value > p1[j - 1].value) {
               temp.value = p1[j].value;
               strcpy(temp.action, p1[j].action);

               p1[j].value = p1[j - 1].value;
               strcpy(p1[j].action, p1[j-1].action);

               p1[j - 1].value = temp.value;
               strcpy(p1[j-1].action, temp.action);
               --j;
          }
          j = i;
          while (j > 0 && p2[j].value > p2[j - 1].value) {
               temp.value = p2[j].value;
               strcpy(temp.action, p2[j].action);
               
               p2[j].value = p2[j - 1].value;
               strcpy(p2[j].action, p2[j-1].action);
               
               p2[j - 1].value = temp.value;
               strcpy(p2[j-1].action, temp.action);
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
        player1[j].isProtected = 0;
     }

     
     for (int k = 0; k < size; k++) {
        player2[k].value = 0;              
        strcpy(player2[k].action, "placeholder"); 
        player2[k].isProtected = 0;
     }

     size = 8;
     for (int h = 0; h < size; h++) {
        centerRow[h].value = 0;             
        strcpy(centerRow[h].action, "placeholder"); 

     }
}




// void printCards(card *player1, card *player2, card *centerRow);
// Prints all the cards in both players hands and the center row
void printCards(card player1[], card player2[], card centerRow[]){

   printf("\n");
   printf("player1s hand:\n");// prints all player 1s cards to console
   printf("\n");
   for(int i = 0; i < 7; i++){// prints top of cards
      if(player1[i].value > 9){printf("-");}// prints extra incase of double digits in card number
      if(player1[i].isProtected == 1){printf("P");}else{printf("-");}
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
      printf("%d %s", player1[i].value, player1[i].action);
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
     if(centerRow[i].value == 0){continue;}
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
     if(centerRow[i].value == 0){break;}
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
     if(centerRow[i].value == 0){break;}
      printf("|");
      printf("%d %s", centerRow[i].value, centerRow[i].action);
      printf("| ");
      }
      
   printf("\n");
   // prints partial of card body
   for(int i = 0; i < 7; i++){
     if(centerRow[i].value == 0){break;}
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
     if(centerRow[i].value == 0){break;}
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
