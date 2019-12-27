#include "game.hpp"

/******************************************************************
 * Function: Game()
 * Description: Default Game constructor that sets the private
                boolean variable to false
 * Parameters: None
 * Pre-Conditions: The class itself has already called the constructor
                    for the other private variables
 * Post-Conditions: The game begins as not over
******************************************************************/
Game::Game(){
  isGameOver = false;
}

/******************************************************************
 * Function: intToRank(int rank)
 * Description: takes the integer version of a rank and returns the
                string representation for the user
 * Parameters: int rank
 * Pre-Conditions: rank must be a positive integer
 * Post-Conditions: rank does not change
******************************************************************/
string Game::intToRank(int rank){
  string ranks [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  return ranks[rank];
}

/******************************************************************
 * Function: gameOver()
 * Description: updates isGameOver by checking the total number of
                books between the two players
 * Parameters: None
 * Pre-Conditions: numBooks must be an accurrate rempresentation
 * Post-Conditions: isGameOver is updated
******************************************************************/
void Game::gameOver(){
  if(players[0].getNumBooks() + players[1].getNumBooks() > 12){
    isGameOver = true;
  } else {
    isGameOver = false;
  }
}

/******************************************************************
 * Function: displayGame()
 * Description: displays for the user the current status of the game
                by showing the books and cards for both players
 * Parameters: None
 * Pre-Conditions: None
 * Post-Conditions: None
******************************************************************/
void Game::displayGame(){
  cout << endl << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "\tComputer" << endl;

  cout << "Books: "; /* display book aquired */
  for(int i = 0; i < players[0].getNumBooks(); i++){
    cout << "[" << intToRank(players[0].getBooks()[i]) << "]";
  }
  cout << endl << "Hand: "; /* display hidden cards of computer */
  int numCardsP1 = players[0].getHand().getNumCards();
  for(int i = 0; i < numCardsP1; i++){
    cout << "[] ";
  }

  cout << endl << endl << "\t[Deck]";

  cout << endl << endl << "\tYou" << endl;

  cout << "Books: "; /* display book aquired */
  for(int i = 0; i < players[1].getNumBooks(); i++){
    cout << "[" << intToRank(players[1].getBooks()[i]) << "]";
  }
  cout << endl << "Hand: "; /* display visible cards in user's hand */
  int numCardsP2 = players[1].getHand().getNumCards();
  for(int i = 0; i < numCardsP2; i++){
    cout << "[" << intToRank(players[1].getHand().getCards()[i].getRank()) << "] ";
  }
  /*show the user the indexes available*/
  cout << endl << "     ";
  for(int i = 0; i < numCardsP2; i++){
    if(intToRank(players[1].getHand().getCards()[i].getRank()) == "10"){
      cout << "   " << i << " ";
    } else {
      if(i > 9){
        cout << " " << i << " ";
      } else {
          cout << "  " << i << " ";
      }
    }
  }
  cout << endl;
  cout << "-----------------------------------------------------------" << endl;
}

/******************************************************************
 * Function: checkInput
 * Description: Performs a do-while using question to only accept
 * 		characters that are in valid. Returns integer
 * 		version of input.
 * Parameters: string question, string valid
 * Pre-Conditions: question and valid must not be empty
 * Post-Conditions: question and valid don't change
******************************************************************/
int Game::checkInput(string question, string valid){
   string var_str;
   size_t found;

   do{
      cout << question << endl;
      cin >> var_str;
      found = var_str.find_first_not_of(valid);
   }
   while(found != string::npos && var_str.length() < 3);

   return stoi(var_str);
}

/******************************************************************
 * Function: checkAndChoose()
 * Description: prompts the user to pick a card to request and
                returns the rank of that card
 * Parameters: None
 * Pre-Conditions: the deck of cards must not be empty
 * Post-Conditions: rankChosen is assigned the rank of user's pick
******************************************************************/
int Game::checkAndChoose(){
  /* if turn begins with no cards in hand */
  if(players[1].getHand().getNumCards() < 1 && !isGameOver){
    cout << "You draw a card.";
    players[1].getHand().addCard(cards.deal());
    displayGame();
  }
  int index = -1;
  index = checkInput("Enter the index of the card you wish to request: ", "0123456789");
  int rankChosen = players[1].getHand().getCards()[index].getRank();
  cout << "You ask for a: " << intToRank(rankChosen) << endl;

  /* go fish if the computer has no cards left */
  if(players[0].getHand().getNumCards() < 1){
    cout << "You draw a card.";
    players[1].getHand().addCard(cards.deal()); //go fish
    displayGame();
  }

  return rankChosen;
}

/******************************************************************
 * Function: checkAndRand()
 * Description: determins a random card for the computer to request
                and returns the rank of that card
 * Parameters: None
 * Pre-Conditions: the deck of cards must not be empty
 * Post-Conditions: rankChosen is assigned the rank of random pick
******************************************************************/
int Game::checkAndRand(){
  /* if turn begins with no cards in hand */
  if(players[0].getHand().getNumCards() < 1 && !isGameOver){
    cout << "Computer draws a card.";
    players[0].getHand().addCard(cards.deal());
    displayGame();
  }
  srand(time(NULL));
  int randInd = rand() % players[0].getHand().getNumCards();
  int rankChosen = players[0].getHand().getCards()[randInd].getRank();
  cout << "Computer asks for a: " << intToRank(rankChosen) << endl;

  /* go fish if the user has no cards left */
  if(players[1].getHand().getNumCards() < 1){
    cout << "Computer draws a card.";
    players[0].getHand().addCard(cards.deal()); //go fish
    displayGame();
  }

  return rankChosen;
}

/******************************************************************
 * Function: compHasMatch(int rankChosen)
 * Description: checks computer's hand for card of rankChosen
 * Parameters: rankChosen
 * Pre-Conditions: rankChosen must be a positive integer
 * Post-Conditions: user is updated
******************************************************************/
void Game::compHasMatch(int rankChosen){
  /* count and remove cards of rankChosen from computer's hand */
  int count = 0;
  while(players[0].getHand().hasRank(rankChosen)){
    Card removed = players[0].getHand().removeCard(rankChosen);
    players[1].getHand().addCard(removed);
    count++;
  }
  if(count > 0){
    cout << "Computer gives you " << count << ": " << intToRank(rankChosen) << endl;
  }

  displayGame();
  /* check for book */
  if(players[1].getHand().checkBook(rankChosen)){
    cout << "You got a book!" << endl;
    players[1].removeBook(rankChosen);
    displayGame();
  }
}

/******************************************************************
 * Function: humHasMatch(int rankChosen)
 * Description: checks user's hand for card of rankChosen
 * Parameters: rankChosen
 * Pre-Conditions: rankChosen must be a positive integer
 * Post-Conditions: user is updated
******************************************************************/
void Game::humHasMatch(int rankChosen){
  /* count and remove cards of rankChosen from user's hand */
  int count = 0;
  while(players[1].getHand().hasRank(rankChosen)){
    Card removed = players[1].getHand().removeCard(rankChosen);
    players[0].getHand().addCard(removed);
    count++;
  }
  if(count > 0){
    cout << "You give Computer " << count << ": " << intToRank(rankChosen) << endl;
  }

  displayGame();
  /* check for book */
  if(players[0].getHand().checkBook(rankChosen)){
    cout << "Computer got a book!" << endl;
    players[0].removeBook(rankChosen);
  }
}

/******************************************************************
 * Function: humFish(int rankChosen, bool &myTurn)
 * Description: goes fish for the human and determins if user's
                turn should continue or end
 * Parameters: rankChosen, &myTurn
 * Pre-Conditions: &myTurn must be initialized
 * Post-Conditions: user is updated with results of their turn
******************************************************************/
void Game::humFish(int rankChosen, bool &myTurn){
  cout << "You Go Fish." << endl;
  Card cardDealt = cards.deal();
  int rankDealt = cardDealt.getRank();
  cout << "You draw a: " << intToRank(rankDealt) << endl;
  players[1].getHand().addCard(cardDealt);

  /* check if card dealt was card requested */
  if(rankDealt == rankChosen){
    cout << "You fished for what you wanted!" << endl;
    /* check for book */
    if(players[1].getHand().checkBook(rankChosen)){
      cout << "You got a book!" << endl;
      players[1].removeBook(rankChosen);
    }
    displayGame();
  } else {
    cout << endl;
    /* still check for book of rankDealt instead */
    if(players[1].getHand().checkBook(rankDealt)){
      cout << "You got a book!" << endl;
      players[1].removeBook(rankDealt);
      displayGame();
    }
    /* end of user's turn */
    cout << "\tCOMPUTER'S TURN!\t" << endl;
    myTurn = !myTurn;
  }
}

/******************************************************************
 * Function: compFish(int rankChosen, bool &compTurn)
 * Description: goes fish for the computer and determins if their
                turn should continue or end
 * Parameters: rankChosen, &compTurn
 * Pre-Conditions: &compTurn must be initialized
 * Post-Conditions: user is updated with results of computer's turn
******************************************************************/
void Game::compFish(int rankChosen, bool &compTurn){
  cout << "Computer Go Fish." << endl;
  Card cardDealt = cards.deal();
  int rankDealt = cardDealt.getRank();

  players[0].getHand().addCard(cardDealt);

  /* check if card dealt was card requested */
  if(rankDealt == rankChosen){
    cout << "Computer fished for what it wanted!" << endl;
    /* check for book */
    if(players[0].getHand().checkBook(rankChosen)){
      cout << "Computer got a book!" << endl;
      players[0].removeBook(rankChosen);

    }
  } else {
    cout << endl;
    /* still check for book of rankDealt instead */
    if(players[0].getHand().checkBook(rankDealt)){
      cout << "Computer got a book!" << endl;
      players[0].removeBook(rankDealt);

    }
    /* end of computer's turn */
    cout << "\tYOUR TURN!\t" << endl;
    compTurn = !compTurn;
  }
}

/******************************************************************
 * Function: humanTurn()
 * Description: runs through the structure of the human's turn by
                using the functions made for the human
 * Parameters: None
 * Pre-Conditions: computer's turn must be over
 * Post-Conditions: the user's turn is complete and it is now the
                    computer's turn
******************************************************************/
void Game::humanTurn(){
  displayGame();
  bool myTurn = true;
  while(!isGameOver && myTurn){
    int rankChosen = checkAndChoose();

    /* check for matching rank in computer's hand */
    if(players[0].getHand().hasRank(rankChosen)){
      compHasMatch(rankChosen);
    } else {
      humFish(rankChosen, myTurn);
    }
    gameOver();
  }
}

/******************************************************************
 * Function: compTurn()
 * Description: runs through the structure of the computer's turn by
                using the functions made for the computer
 * Parameters: None
 * Pre-Conditions: human's turn must be over
 * Post-Conditions: the computer's turn is complete and it is now the
                    human's turn
******************************************************************/
void Game::compTurn(){
  displayGame();
  bool compTurn = true;
  while(!isGameOver && compTurn){
    int rankChosen = checkAndRand();

    /* check for matching rank in user's hand */
    if(players[1].getHand().hasRank(rankChosen)){
      humHasMatch(rankChosen);
    } else {
      compFish(rankChosen, compTurn);
    }
    gameOver();
  }
}

/******************************************************************
 * Function: beginTurns()
 * Description: shuffles the deck, deals the initial cards, and
                continues alternating turns until the game is over
 * Parameters: None
 * Pre-Conditions: cards must be initialized with unique Cards
 * Post-Conditions: an entire game of Go Fish has been played
******************************************************************/
void Game::beginTurns(){

  cards.shuffleDeck();
  for(int i = 0; i < 7; i++){ /* deal 7 cards to player 0 */
    players[0].getHand().addCard(cards.deal());
  }

  for(int i = 0; i < 7; i++){ /* deal 7 cards to player 1 */
    players[1].getHand().addCard(cards.deal());
  }

  /* begin alternating turns */
  while(!isGameOver){
    humanTurn();
    compTurn();
  }

  cout << "GAME OVER" << endl;
  displayGame();
  /* declare winner */
  if(players[0].getNumBooks() > players[1].getNumBooks()){
    cout << "Computer Wins!" << endl;
  } else {
    cout << "You Win!" << endl;
  }

}
