#include "card.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#ifndef HAND_HPP
#define HAND_HPP
class Hand {
  private:
    Card* cards;
    int numCards;  // Number of cards in the hand.
  public: // must have constructors, destructor, accessor methods, and mutator methods
    Hand();
    ~Hand();
    Card* getCards();
    int getNumCards();
    void addCard(Card card);
    bool hasRank(int rank);
    Card removeCard(int rank);
    bool checkBook(int rank); //check for full book of rank in hand
    void printHand();
  friend bool operator< (Card const &c1, Card const &c2);
};
#endif
