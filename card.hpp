#include <iostream>
using namespace std;

#ifndef CARD_HPP
#define CARD_HPP
class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public: // must have constructors, destructor, accessor methods, and mutator methods
    Card();
    int getRank() const; //returns rank
    int getSuit() const; //returns suit
    void setRank(int r);
    void setSuit(int s);
    void printCard();
};
#endif
