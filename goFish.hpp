#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public: // must have constructors, destructor, accessor methods, and mutator methods
    Card();
    //Card(int r, int s);
    int getRank() const; //returns rank
    int getSuit() const; //returns suit
    void setRank(int r);
    void setSuit(int s);
    //void printCard();
    //char intToSuit(int suit);
    //string intToRank(int rank);
};

class Deck {
  private:
    Card* cards;
    int numCards;  // Number of cards remaining in the deck.
  public: // must have constructors, destructor, accessor methods, and mutator methods
    Deck();
    Card* getCards();
    //void printDeck();
    void shuffleDeck(); //shuffle cards
    Card deal();
};

class Hand {
  private:
    Card* cards;
    int numCards;  // Number of cards in the hand.
  public: // must have constructors, destructor, accessor methods, and mutator methods
    //bool compareRank(Card c1, Card c2);
    Hand();
    Card* getCards();
    int getNumCards();
    //void addCards(Card* cardArr, int num); //append cardArr to cards in hand
    void addCard(Card card);
    //void printHand();
    bool hasRank(int rank);
    int numOfRank(int rank);
    //Card* removeCards(int rank, int num); //remove cards of that rank, store and return in array
    Card removeCard(int rank);
    bool checkBook(int rank); //check for full book of rank in hand
  friend bool operator< (Card const &c1, Card const &c2);
};

class Player {
  private:
    Hand hand;
    int* books;  // Array with ranks for which the player has books.
    int numBooks;
  public:// must have constructors, destructor, accessor methods, and mutator methods
    Player();
    Hand& getHand();
    int* getBooks();
    void setBooks(int rank);
    int getNumBooks();
    void setNumBooks(int add);
    Card randCard(); //return a random card from player's hand
    void removeBook(int rankChosen);
};

class Game {
  private:
    Deck cards;
    Player players[2];
    bool isGameOver;
  public: // must have constructors, destructor, accessor methods, and mutator methods
    Game();
    Deck getCards();
    string intToRank(int rank);
    void gameOver();
    void displayGame();
    int checkInput(string question, string valid);
    int checkAndChoose();
    int checkAndRand();
    void compHasMatch(int rankChosen);
    void humHasMatch(int rankChosen);
    void humFish(int rankChosen, bool &myTurn);
    void compFish(int rankChosen, bool &compTurn);
    void humanTurn();
    void compTurn();
    void beginTurns(); //alternate player's turns //logic for game

};
