/******************************************************************
 * Program: go_fish.cpp
 * Author: Michael Boly
 * Date: 1/30/2019
 * Description: Plays Go Fish by the rules
 * Input: The user chooses an index of the cards in their hand to
          request from the computer
 * Output: A wholesome game of Go Fish guarenteed to satisfy your
           gaming desires for hours on end.
 *****************************************************************/

#include "game.hpp"

/******************************************************************
 * Function: main()
 * Description: Creates a game of Go Fish (user vs. computer) that
                repeats until the user is as sick of playing Go Fish
                as I am.
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: The user will be appreciating your hard work.
 ******************************************************************/
int main(){
  int again = 1;
  while(again == 1){
    Game game;
    game.beginTurns();
    again = game.checkInput("Enter 1 to play again or 2 to exit: ", "12");
  }
}
