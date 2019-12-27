#include "card.hpp"

/******************************************************************
 * Function: Card()
 * Description: Default Card constructor that sets both private
                variables to 0
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: The private variables are initialized
******************************************************************/
Card::Card(){
  rank = 0;
  suit = 0;
}

/******************************************************************
 * Function: getRank() const
 * Description: gets this Card's rank
 * Parameters: None
 * Pre-Conditions: rank has been initialized
 * Post-Conditions: rank's value is accessible
******************************************************************/
int Card::getRank() const{
  return rank;
}

/******************************************************************
 * Function: getSuit() const
 * Description: gets this Card's suit
 * Parameters: None
 * Pre-Conditions: suit has been initialized
 * Post-Conditions: suit's value is accessible
******************************************************************/
int Card::getSuit() const{
  return suit;
}

/******************************************************************
 * Function: setRank(int r)
 * Description: sets this Card's rank
 * Parameters: int r
 * Pre-Conditions: None
 * Post-Conditions: rank is re-assigned to r's value
******************************************************************/
void Card::setRank(int r){
  rank = r;
}

/******************************************************************
 * Function: setSuit(int s)
 * Description: sets this Card's suit
 * Parameters: int s
 * Pre-Conditions: None
 * Post-Conditions: suit is re-assigned to s' value
******************************************************************/
void Card::setSuit(int s){
  suit = s;
}

/******************************************************************
 * Function: printCard()
 * Description: prints this Card's rank and suit
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Card::printCard(){
  cout << "Rank: " << rank << endl;
  cout << "Suit: " << suit << endl;
}
