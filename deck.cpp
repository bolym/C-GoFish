#include "deck.hpp"

/******************************************************************
 * Function: Deck()
 * Description: Default Deck constructor that initializes a dinamic
                array of Cards and sets their rank and suit
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: A full new deck is created
******************************************************************/
Deck::Deck(){
  cards = new Card[52];
  numCards = 52;
  int count = 0;
  for(int r = 0; r < 13; r++){
    for(int s = 0; s < 4; s++){
      cards[count].setRank(r);
      cards[count].setSuit(s);
      count++;
    }
  }
}

/******************************************************************
 * Function: ~Deck()
 * Description: Destructor that deletes the dynamically created
                array of cards
 * Parameters: None
 * Pre-Conditions: cards must be instantiated
 * Post-Conditions: cards is deleted
******************************************************************/
Deck::~Deck(){
  delete[] cards;
}

/******************************************************************
 * Function: getCards()
 * Description: gets this Deck's cards
 * Parameters: None
 * Pre-Conditions: cards has been initialized
 * Post-Conditions: cards' value is accessible
******************************************************************/
Card* Deck::getCards(){
  return cards;
}

/******************************************************************
 * Function: shuffleDeck()
 * Description: randomly shuffles the deck of cards by switching
                two random Cards repeatedly
 * Parameters: None
 * Pre-Conditions: cards must be instantiated
 * Post-Conditions: cards is shuffled
******************************************************************/
void Deck::shuffleDeck(){
  srand(time(NULL));
  /* change two card positions 1000 times to shuffle */
  for(int i = 0; i < 1000; i++){
    int card1 = rand() % 52;
    int card2 = rand() % 52;
    Card temp = cards[card1];
    cards[card1] = cards[card2];
    cards[card2] = temp;
  }
}

/******************************************************************
 * Function: deal()
 * Description: removes and returns a single card from cards
 * Parameters: None
 * Pre-Conditions: cards must be instantiated
 * Post-Conditions: cards loses one card
******************************************************************/
Card Deck::deal(){
  Card draw = cards[numCards-1];
  numCards--;
  return draw;
}

/******************************************************************
 * Function: printDeck()
 * Description: prints rank and Suit of every card in this Deck
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Deck::printDeck(){
  for(int i = 0; i < numCards; i++){
    cout << "Rank: " << cards[i].getRank() << " ";
    cout << "Suit: " << cards[i].getSuit() << endl;
  }
}
