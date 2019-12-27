#include "card.hpp"
#include "hand.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#ifndef PLAYER_HPP
#define PLAYER_HPP
class Player {
  private:
    Hand hand;
    int* books;  // Array with ranks for which the player has books.
    int numBooks;
  public:// must have constructors, destructor, accessor methods, and mutator methods
    Player();
    ~Player();
    Hand& getHand();
    int* getBooks();
    int getNumBooks();
    void setNumBooks(int add);
    Card randCard(); //return a random card from player's hand
    void removeBook(int rankChosen);
};
#endif
