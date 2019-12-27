#include "card.hpp"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;
#ifndef DECK_HPP
#define DECK_HPP
class Deck {
  private:
    Card* cards;
    int numCards;  // Number of cards remaining in the deck.
  public: // must have constructors, destructor, accessor methods, and mutator methods
    Deck();
    ~Deck();
    Card* getCards();
    void shuffleDeck(); //shuffle cards
    Card deal();
    void printDeck();
};
#endif
