# Assignment 2 - Go Fish
**Due by 11:59pm on Monday, 2/4/2019**

**Demos due by 11:59pm on Monday, 2/18/2019**

The goals of this assignment is to start working with C++ classes and class composition (the "has-a" relationship).  Follow the directions below, and make sure your source code files (**no executable files, `.o` files, or other crufty stuff**) are committed and pushed back into your repository on GitHub to earn credit for the assignment.

## Go Fish game

For this assignment, you will write a program that allows one player to play a game of Go Fish against the computer.  Go Fish is a game that uses a standard deck of 52 playing cards.  Specifically, each card in the deck has a rank and a suit.  There are 13 ranks: the numbers 2 through 10, Jack (usually represented with the letter J), Queen (Q), King (K), and Ace (A).  There are 4 suits: clubs, diamonds, hearts, and spades.  In a 52-card deck, there is one card of each rank for each suit.

A game of Go Fish between two players proceeds as follows:
  * The deck of cards is shuffled, randomizing the order of the cards.
  * Each player is dealt a hand of 7 cards.  Only the player is able to see the cards in their hand.
  * The remaining cards are placed face-down (i.e. with their rank and suit hidden) on the table to form the "stock".
  * One of the players (player A) begins the game by asking the other player (player B) for all of his/her cards of a specific rank (e.g. "Please give me all of your 7's").  To ask for a given rank, a player must have at least one card of that rank in his/her hand.
  * If player B has cards of the requested rank, he/she must give *all* of his/her cards of that rank to player A, and player A gets to take another turn.
  * If player B does not have any cards of the requested rank, he/she says "go fish", and player A must select one card from the stock.  If that card has the rank player A originally requested, then player A gets to take another turn.  Otherwise, it becomes player B's turn.
  * If at any point a player runs out of cards, then, when it is that player's turn to play, they may draw a card from the stock and ask for cards of that rank.  If a player runs out of other cards when it is the other player's turn to ask for a rank, the other player may continue to ask for a rank and draw from the stock until they draw a rank other than the one they asked for.
  * If a player collects all four cards of the same rank, this is called a "book", and the player lays down his/her book on the table.  Both players may see the cards in every book that's laid down.
  * The game continues with the players alternating turns until all of the books are laid down.  At the end of the game, the player who laid down the most books wins.

Here is a nice little online version of Go Fish that you can play to get a feel for how the game works if you've never played it before: https://cardgames.io/gofish/.

## Needed classes

To write your Go Fish game, you should implement the following classes, including the specified members and methods.  You may also add more members and methods, as needed.

```
class Card {
  private:
    int rank;  // Should be in the range 0-12.
    int suit;  // Should be in the range 0-3.
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
};
```

In the `Card` class above, `rank` and `suit` are represented with `int` values, but you must also have some way to map those values to representations players will be familiar with (e.g. a string representation of the suit or rank) when you print information about cards to the screen for players to see.

```
class Deck {
  private:
    Card cards[52];
    int n_cards;  // Number of cards remaining in the deck.
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
};
```
The `Deck` class is the source of all of the cards.  Every `Card` will initially start in a `Deck` object and then be transferred to players' hands (and thus removed from the `Deck`).  An important method that should be implemented for the `Deck` class is one to deal a card by remove a card from the `Deck` and returning it so it can be placed into a player's hand.

```
class Hand {
  private:
    Card* cards;
    int n_cards;  // Number of cards in the hand.
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
};
```
The `Hand` class will hold the cards in one player's hand.  The number of cards a player holds may change, so the size of the array of `Card` objects in a hand may also need to change.  Cards may be added to a player's hand and removed from a player's hand, so the `Hand` class will need functions to do both of those things.  Other useful methods might check for a book and remove a book from the player's hand.

```
class Player {
  private:
    Hand hand;
    int* books;  // Array with ranks for which the player has books.
    int n_books;
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
};
```
The `Player` class represents a single player.  Each `Player` will have a `Hand` object representing its hand and an array keeping track of the books the player has laid down.  Depending on how you implement things, the `Player` class may need methods to add and remove cards from their hand or to check their hand for books.  Another useful method the `Player` class might have is one to figure out what rank they want to ask for.  Note that the `Player` class must represent both the human player and the computer player.  You should write your class methods accordingly and add any extra data members needed to accomplish this.

```
class Game {
  private:
    Deck cards;
    Player players[2];
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
}
```
The `Game` class represents the state of an entire game.  It contains objects representing the deck of cards and both players.  The methods of the `Game` class should contain all of the logic for the game.  For example, it would be useful to have methods in the `Game` class that check whether the game is over and that execute a player's turn.

### Program features

Your program should do the following:
  * Set up a deck of 52 cards as described above.
  * Shuffle the deck (i.e. randomize the order of cards).
  * Deal 7 cards to the two players.
  * Play a game of Go Fish as described above, with the following gameplay features:
    * Print the current state of the game (e.g. the cards held by the human player and the books laid down by both the human player and the computer) after each turn (keeping the computer player's cards hidden).
    * On the human player's turn, prompt the user for a rank to ask for.  When they enter a rank, either give all of the computer player's cards of that rank to the human (if the computer player has cards of the requested rank) or execute a "go fish", drawing a card from the stock into the human player's hand.  Make sure to alert the user what the result of their turn is.
    * On the computer player's turn, the computer should randomly select a rank from its hand for which to ask the other player, and the appropriate actions should be taken (i.e. cards are taken from the human player's hand, or the computer draws a card from the stock).  The user should be alerted about what the computer player asked for and what the result of its turn was.
  * Once the game is over, you should announce the winner and ask the user if they want to play again.
  * You should not have any memory leaks in your program.

### Program design

It is up to you how to design an interface to allow the user to play the Go Fish game.

Your program should use the classes above along with any other classes or functions you need.  Your program should be well modularized.  That is, it should be factored into reasonably-sized (preferably small) functions that each perform some specific logical task.

You should separate your source code several files:
  * `gofish.cpp` - This should contain your `main()` function.
  * You should also have one interface header (`.hpp`) file and one implementation (`.cpp`) file for each of the classes above, as well as for any additional classes you implement.

You should also write a `Makefile` that specifies the compilation of your program.

### Code style

You must include a header comment for each source code file that contains a description of the file (including how to run the program, command line arguments, etc. if the file contains your `main()` function), your name, and the date.  Your code should be well commented, including header comments for *all* functions describing what the function does, its parameters, and any pre- and post-conditions for the function.  You should appropriately use whitespace, newlines, and indentation.

Make sure you review the style guidelines for the course, and start trying to follow them:

http://web.engr.oregonstate.edu/~hessro/static/media/cs162-style-guidelines.4812c1d9.pdf

## Submitting your program

To submit your program, you need to make sure the following files are committed into your git repository and pushed to your `master` branch on GitHub before the due date above:
  * `gofish.cpp`
  * All of the `.hpp` and `.cpp` files containing the interface and implementation of your classes.
  * `Makefile`
Do not commit any other files (other than the ones that were already in your repository at the start of the assignment).  A good way to check whether your assignment is submitted is to simply look at your repo on GitHub (i.e. https://github.com/OSU-CS162-W19/assignment-2-YourGitHubUsername).  If your files appear there before the deadline, they they are submitted.

## Grading criteria

Your program **MUST** compile and run on `flip.engr.oregonstate.edu`, so make sure you have tested your work there before you make your final submission, since a program that compiles and runs in one environment may not compile and run in another.  **Assignments that do not compile on `flip` will receive a grade of 0.**  If you do not have an ENGR account, you can create one at https://teach.engr.oregonstate.edu/.

This assignment is worth 100 points total:
  * 90 points: your program meets the specifications above
    * 10 points: correctly initializes game with 52 cards and 2 players
    * 10 points: correctly shuffles and deals deck
    * 10 points: correctly alternates turns between players
    * 10 points: correctly transfers cards between player hands when a card is stolen
    * 10 points: correctly draws a card from the stock when a player has to go fish
    * 10 points: correctly implements computer player who uses random selection
    * 10 points: correctly determines when game is over and who the winner is
    * 10 points: correctly implements each of the required classes (Card, Deck, Hand, Player, Game)
    * 10 points: correctly factors program into files and uses a Makefile

  * 10 points: your code is appropriately commented and uses consistent and appropriate style

Your work on this assignment will be graded by demoing it with a TA.  During your demo, you will compile and run your program for the TA and walk them through your source code, describing to them how it works.  It'll be your responsibility to sign up for a 10-minute demo slot with a TA by the demo due date above.  **You will receive a zero on the assignment if you don't demo it with a TA by the demo due date.**
