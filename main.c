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
void sortCards(card *player1, card *player2);
void initializeCards(card *player1, card *player2, card *deck, card *centerRow);
void startGame(card player1[], card player2[], card deck[], card centerRow[]);
void shuffleDeck(card *deck);
int countCards(card *deck, int n);
int searchCards(card *player, int value, int n);
void drawAndAssignCard(card *deck, card *centerRow, card *player);
void protectCard(card *player, int i);
void takeTurn(card *deck, card *currPlayer, card *oppositePlayer, card *centerRow, int i);



int main(){
     // declare and initialize variables
     card deck[84];
     //card discardPile[84];
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
        for(int i = 0; i < 84; i++){printf("\n%s %d",deck[i].action,deck[i].value);}

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
    printCards(player1,player2,centerRow);
     // sort each players hand
      sortCards(player1,player2);
      printCards(player1,player2,centerRow);
      // start game
      startGame(player1, player2, deck, centerRow);
     printCards(player1,player2,centerRow);

     
      int counter = countCards(deck,84);// 84 minus the 3 cards weve have already removed
      int winFlag = 0;
      int playerEntry = 0;
        int search = 0;
      // loop until cards in deck run out or someone wins
      while(winFlag == 0 && counter > 0){

        // player 1s turn
         printf("Player1 would you like to draw a card or use a card in the center row(Enter 1 to draw a card)? ");
        printf("If you enter a incorrect number I will assume you want to draw a card\n");
         scanf("%d", &playerEntry);
            search = searchCards(centerRow,playerEntry,8);
         if(playerEntry == 1 || search == 0){
            // call draw card function to draw a card
            drawAndAssignCard(deck,centerRow,player1);
            }else{// check if other entry is a card in the centerRow
            // if yes then call that ability
            // have 8 different ability functions
            takeTurn(deck,player1,player2,centerRow,search);
               }
        printCards(player1,player2,centerRow);

            // player 2s turn
         printf("Player2 would you like to draw a card or use a card in the center row(Enter 1 to draw a card)? ");
        printf("If you enter a incorrect number I will assume you want to draw a card\n");
         scanf("%d", &playerEntry);
            search = searchCards(centerRow,playerEntry,8);
         if(playerEntry == 1 || search == 0){
            // call draw card function to draw a card
            drawAndAssignCard(deck,centerRow,player2);
            }else{// check if other entry is a card in the centerRow
            // if yes then call that ability
            // have 8 different ability functions
                takeTurn(deck,player2,player1,centerRow,search);
               }
        printCards(player1,player2,centerRow);
         
         }




  
  return 0;
}


// void takeTurn(card *deck, card *currPlayer, card *oppositePlayer, card *centerRow,)
// checks what the cards ability is and uses it, takes in integer for the players turn
void takeTurn(card *deck, card *currPlayer, card *oppositePlayer, card *centerRow, int i){

    
    int playerChoice = 0;
    int searchResult = 0;

    if(strcmp("shift2Right",centerRow[i].action) == 0){
        // call shift right function
        
    }else if(strcmp("protect",centerRow[i].action) == 0){
        printf("Which card would you like to protect?");
        scanf("%d",&playerChoice);
        searchResult = searchCards(currPlayer,playerChoice,7);
        // call protect function
        protectCard(currPlayer,searchResult);
    }else if(strcmp("shift2Left",centerRow[i].action) == 0){
        // call shft2left function
    }else if(strcmp("swapAdjacent",centerRow[i].action) == 0){
        // call swapAdj function
    }else if(strcmp("removeMiddle",centerRow[i].action) == 0){
        // call remove mid function
    }else if(strcmp("removeRight",centerRow[i].action) == 0){
        // call remove right function
    }else if(strcmp("removeLeft",centerRow[i].action) == 0){
        // call remove left function
    }else if(strcmp("swapSkip1Card",centerRow[i].action) == 0){
        // call swap skip 1 card function
    }
}




// void protectCard(card *player, int i)
void protectCard(card *player, int i){
    player[i].isProtected = 1;
    printf("%d",player[i].isProtected);
}



//int searchCards(card *player, int value, int n)
// searchs a hand for a certain card and returns index
int searchCards(card *player, int value, int n){
   for (int i = 0; i < n; i++) { 
      if (player[i].value == value) {
            return i;  
        }
    }
    return 0; 
   }


//void drawAndAssignCard(card *deck, card *centerRow, card *player)
// Draws a card from the pile and assigns it for the user
void drawAndAssignCard(card *deck, card *centerRow, card *player){
   // get index of deck to pull card from
   int cardIndex = countCards(deck,84);
   int userInp = 0;
   // let user know their card, then they must replace one of the cards in their hand
   printf("You got %d %s card! What would you like to replace it with in your hand?",deck[cardIndex].value,deck[cardIndex].action);
   scanf("%d",&userInp);
   int check = searchCards(player,userInp,7);
   // do a check of the card number to make sure its there
   while(check == -1){
      printf("Invalid Entry\n");
      printf("You got %d %s card! What would you like to replace it with in your hand?",deck[cardIndex].value,deck[cardIndex].action);
      scanf("%d",&userInp);
      check = searchCards(player,userInp,7); // find player card index for entry
      }
   
      // if card has been found then put draw card in hand and chosen card in middle
      
      // find index of card in players hand we have in check
      // find empty index in middle
        for(int j = 0; j < 8;j++){
            if(centerRow[j].value == 0){
                // assign card to empty spot in middle
                centerRow[j].value = player[check].value;
                strcpy(centerRow[j].action,player[check].action);
                break;
                
                } 
            }
      // take newly drawn card and place that in empty spot in players hand
        player[check].value = deck[cardIndex].value;
        strcpy(player[check].action,deck[cardIndex].action);
      // finish and return
   }


//int countCards(card *deck)
// Counts the cards in the deck to return its index
int countCards(card *deck, int n){
   int count = 0;
   for(int i = 0; i < n; i++){
      if(deck[i].value != 0){count++;}
   }
   return (count-1);
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
