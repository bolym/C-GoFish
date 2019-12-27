#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

#ifndef GAME_HPP
#define GAME_HPP
class Game {
  private:
    Deck cards;
    Player players[2];
    bool isGameOver;
  public: /* must have constructors, destructor, accessor methods, and mutator methods */
    Game();
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
    void beginTurns(); /*alternate player's turns, logic for game*/
};
#endif
