#include "hand.hpp"

/******************************************************************
 * Function: operator<(Card const &c1, Card const &c2)
 * Description: compares two given Cards by their rank for sorting
 * Parameters: Card const &c1, Card const &c2
 * Pre-Conditions: c1 and c2 must be initialized
 * Post-Conditions: c1 and c2 remain the same
******************************************************************/
bool operator< (Card const &c1, Card const &c2){
  return (c1.getRank() < c2.getRank());
}

/******************************************************************
 * Function: Hand()
 * Description: Default Hand constructor that initializes a dynamic
                array of cards and initializes numCards to 0
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: A new array of default Cards is created
******************************************************************/
Hand::Hand(){
  numCards = 0;
  cards = new Card[52];
}

/******************************************************************
 * Function: ~Hand()
 * Description: Destructor that deletes the dynamically created
                array of cards
 * Parameters: None
 * Pre-Conditions: cards must be instantiated
 * Post-Conditions: cards is deleted
******************************************************************/
Hand::~Hand(){
  delete[] cards;
}

/******************************************************************
 * Function: getCards()
 * Description: gets this Hand's cards
 * Parameters: None
 * Pre-Conditions: cards has been initialized
 * Post-Conditions: cards' value is accessible
******************************************************************/
Card* Hand::getCards(){
  return cards;
}

/******************************************************************
 * Function: getNumCards()
 * Description: gets this Hand's numCards
 * Parameters: None
 * Pre-Conditions: numCards has been initialized
 * Post-Conditions: numCards's value is accessible
******************************************************************/
int Hand::getNumCards(){
  return numCards;
}

/******************************************************************
 * Function: addCard(Card card)
 * Description: adds the given card to the cards array in this Hand
                and resorts the array
 * Parameters: Card card
 * Pre-Conditions: card has been initialized
 * Post-Conditions: cards contains another card
******************************************************************/
void Hand::addCard(Card card){
  cards[numCards] = card;
  this->numCards++;
  sort(cards, cards + numCards);
}

/******************************************************************
 * Function: hasRank(int rank)
 * Description: true if cards array has a card of the given rank,
                false otherwise
 * Parameters: int rank
 * Pre-Conditions: rank must be a positive integer
 * Post-Conditions: cards and rank don't change
******************************************************************/
bool Hand::hasRank(int rank){
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      return true;
    }
  }
  return false;
}

/******************************************************************
 * Function: removeCard(int rank)
 * Description: removes a single card of the given rank from cards
 * Parameters: int rank
 * Pre-Conditions: rank must be a positive integer
 * Post-Conditions: cards has one less card
******************************************************************/
Card Hand::removeCard(int rank){
  Card removed;
  int cardPos = -1;
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      cardPos = i;
    }
  }
  /* store card of given rank */
  removed = cards[cardPos];
  /* set rank and suit such that the sort will put card at the end */
  cards[cardPos].setRank(69);
  cards[cardPos].setSuit(69);
  sort(cards, cards + numCards);
  this->numCards = this->numCards - 1;

  return removed;
}

/******************************************************************
 * Function: checkBook(int rank)
 * Description: true if cards has 4 cards of the same rank, false
                otherwise
 * Parameters: int rank
 * Pre-Conditions: rank must be a positive integer
 * Post-Conditions: cards has one less card
******************************************************************/
bool Hand::checkBook(int rank){
  //check for full book of rank in hand
  int count = 0;
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      count++;
    }
  }
  if(count > 3){
    return true;
  }
  return false;
}

/******************************************************************
 * Function: printHand()
 * Description: prints the rank and Suit of every card in this Hand
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Hand::printHand(){
  for(int i = 0; i < numCards; i++){
    cout << "Rank: " << cards[i].getRank() << " " << "Suit: " << cards[i].getSuit() << endl;
  }
}
