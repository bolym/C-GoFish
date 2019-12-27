#include "player.hpp"

/******************************************************************
 * Function: Player()
 * Description: Default Player constructor that initializes an array
                of integers and sets numBooks to 0
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: A new array of integers is created
******************************************************************/
Player::Player(){
  // hand = Hand();
  books = new int[13];
  numBooks = 0;
}

/******************************************************************
 * Function: ~Player()
 * Description: Destructor that deletes the dynamically created
                array of ints
 * Parameters: None
 * Pre-Conditions: books must be instantiated
 * Post-Conditions: books is deleted
******************************************************************/
Player::~Player(){
  delete[] books;
}

/******************************************************************
 * Function: getHand()
 * Description: gets this Player's hand
 * Parameters: None
 * Pre-Conditions: hand has been initialized
 * Post-Conditions: hand's value is accessible
******************************************************************/
Hand& Player::getHand(){
  return hand;
}

/******************************************************************
 * Function: getBooks()
 * Description: gets this Player's books
 * Parameters: None
 * Pre-Conditions: books has been initialized
 * Post-Conditions: books's value is accessible
******************************************************************/
int* Player::getBooks(){
  return books;
}

/******************************************************************
 * Function: getNumBooks()
 * Description: gets this Player's numBooks
 * Parameters: None
 * Pre-Conditions: numBooks has been initialized
 * Post-Conditions: numBooks's value is accessible
******************************************************************/
int Player::getNumBooks(){
  return numBooks;
}

/******************************************************************
 * Function: randCard()
 * Description: returns a randomly picked card in this Player's Hand
                used for the computer to pick its own card to request
 * Parameters: None
 * Pre-Conditions: numCards must accurately represent the logical
                   size of the cards array
 * Post-Conditions: all cards stay the same
******************************************************************/
Card Player::randCard(){
  //return a random card from player's hand
  srand(time(NULL));
  int randInd = rand() % hand.getNumCards();
  Card randCard = hand.getCards()[randInd];
  return randCard;
}

/******************************************************************
 * Function: removeBook(int rankChosen)
 * Description: removes every card of rank given and adds that rank
                to the books array, incrementing numBooks
 * Parameters: int rankChosen
 * Pre-Conditions: rankChosen must be a positive integer
 * Post-Conditions: this Player's hand has no more cards of rankChosen
******************************************************************/
void Player::removeBook(int rankChosen){
  books[numBooks] = rankChosen;
  numBooks = numBooks + 1;
  /* remove a card of rankChosen until there are no more left */
  while(hand.hasRank(rankChosen)){
    hand.removeCard(rankChosen);
  }
}
