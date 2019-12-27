#include "goFish.hpp"

/************CARD CLASS*****************/
Card::Card(){
  rank = 0;
  suit = 0;
}

/*
Card::Card(int r, int s) {
  rank = r;
  suit = s;
}
*/

int Card::getRank() const{
  return rank;
}

int Card::getSuit() const{
  return suit;
}

void Card::setRank(int r){
  rank = r;
}

void Card::setSuit(int s){
  suit = s;
}
/*
void Card::printCard(){
  cout << "Rank: " << rank << endl;
  cout << "Suit: " << suit << endl;
}

char Card::intToSuit(int suit){
  char suits [4] = {'H', 'D', 'S', 'C'};
  return suits[suit];
}
string Card::intToRank(int rank){
  string ranks [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  return ranks[rank];
}
*/
/************DECK CLASS*****************/

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

Card* Deck::getCards(){
  return cards;
}

/*
void Deck::printDeck(){
  for(int i = 0; i < numCards; i++){
    cout << "Rank: " << cards[i].getRank() << " ";
    cout << "Suit: " << cards[i].getSuit() << endl;
  }
}
*/

void Deck::shuffleDeck(){
  srand(time(NULL));
  for(int i = 0; i < 1000; i++){
    int card1 = rand() % 52;
    int card2 = rand() % 52;
    Card temp = cards[card1];
    cards[card1] = cards[card2];
    cards[card2] = temp;
  }
}

Card Deck::deal(){
  Card draw = cards[numCards-1];
  numCards--;
  return draw;
}

/************HAND CLASS*****************/
/*
bool Hand::compareRank(Card c1, Card c2){
  return (c1.getRank() < c2.getRank());
}
*/

bool operator< (Card const &c1, Card const &c2){
  return (c1.getRank() < c2.getRank());
}

Hand::Hand(){
  numCards = 0;
  cards = new Card[52];
}

Card* Hand::getCards(){
  return cards;
}

int Hand::getNumCards(){
  return numCards;
}

/*
void Hand::addCards(Card* cardArr, int num){
  for(int i = 0; i < num; i++){
    cards[numCards + i] = cardArr[i];
  }
  numCards = numCards + num;
  sort(cards, cards + numCards);
}
*/

void Hand::addCard(Card card){
  cards[numCards] = card;
  this->numCards++;
  sort(cards, cards + numCards);
}

/*
void Hand::printHand(){
  for(int i = 0; i < numCards; i++){
    cout << "Rank: " << cards[i].getRank() << " " << "Suit: " << cards[i].getSuit() << endl;
  }
}
*/

bool Hand::hasRank(int rank){
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      return true;
    }
  }
  return false;
}

/*
int Hand::numOfRank(int rank){
  int count = 0;
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      count++;
    }
  }
}


Card* Hand::removeCards(int rank, int num){
  //remove cards of that rank, store and return in array
  Card* removed = new Card[num];
  int firstCardPos = -1;
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      firstCardPos = i;
      break;
    }
    break;
  }

  for(int i = 0; i < num; i++){
    removed[i] = cards[firstCardPos];
    cards[numCards - i] = Card();
  }

  sort(cards, cards + numCards);
  return removed;
}
*/

Card Hand::removeCard(int rank){
  Card removed;
  int cardPos = -1;
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      cardPos = i;
    }
  }
  removed = cards[cardPos];

  cards[cardPos].setRank(69);
  cards[cardPos].setSuit(69);
  sort(cards, cards + numCards);
  this->numCards = this->numCards - 1;
  //create new array without removed card

  //cards[cardPos] = Card(); //what to set removed card position to
  return removed;
}

bool Hand::checkBook(int rank){
  //check for full book of rank in hand
  int count = 0;
  for(int i = 0; i < numCards; i++){
    if(cards[i].getRank() == rank){
      count++;
    }
  }
  if(count > 3){
    return true;
  }
  return false;
}

/************PLAYER CLASS*****************/

Player::Player(){
  hand = Hand();
  books = new int[13];
  numBooks = 0;
}

Hand& Player::getHand(){
  return hand;
}

int* Player::getBooks(){
  return books;
}

/*
void Player::setBooks(int rank){
  books[numBooks] = rank;
}
*/

int Player::getNumBooks(){
  return numBooks;
}
/*
void Player::setNumBooks(int add){
  numBooks = numBooks + add;
}
*/
Card Player::randCard(){
  //return a random card from player's hand
  srand(time(NULL));
  int randInd = rand() % hand.getNumCards();
  Card randCard = hand.getCards()[randInd];
  return randCard;
}

void Player::removeBook(int rankChosen){
  books[numBooks] = rankChosen;
  numBooks = numBooks + 1;

  while(hand.hasRank(rankChosen)){
    hand.removeCard(rankChosen);
  }
}

/************GAME CLASS*****************/

Game::Game(){
  cards = Deck();
  players[0] = Player();
  players[1] = Player();
  isGameOver = false;
}

Deck Game::getCards(){
  return cards;
}

string Game::intToRank(int rank){
  string ranks [13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
  return ranks[rank];
}

void Game::gameOver(){
  if(players[0].getNumBooks() + players[1].getNumBooks() > 12){
    isGameOver = true;
  }
  isGameOver = false;
}

void Game::displayGame(){
  //display current game status
  cout << endl << endl;
  cout << "-----------------------------------------------------------" << endl;
  cout << "\tComputer" << endl;

  cout << "Books: ";
  for(int i = 0; i < players[0].getNumBooks(); i++){
    cout << "[" << intToRank(players[0].getBooks()[i]) << "]";
  }
  cout << endl << "Hand: ";
  int numCardsP1 = players[0].getHand().getNumCards();
  for(int i = 0; i < numCardsP1; i++){
    cout << "[" << intToRank(players[0].getHand().getCards()[i].getRank()) << "] ";
  }
  /*
  for(int i = 0; i < numCardsP1; i++){
    cout << "[] ";
  }
  */
  cout << endl << endl;
  cout << "\t[Deck]";

  cout << endl << endl;
  cout << "\tYou" << endl;

  cout << "Books: ";
  for(int i = 0; i < players[1].getNumBooks(); i++){
    cout << "[" << intToRank(players[1].getBooks()[i]) << "]";
  }
  cout << endl << "Hand: ";
  int numCardsP2 = players[1].getHand().getNumCards();
  for(int i = 0; i < numCardsP2; i++){
    cout << "[" << intToRank(players[1].getHand().getCards()[i].getRank()) << "] ";
  }
  cout << endl;
  //indexes
  cout << "     ";
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

int Game::checkAndChoose(){
  //no cards in hand
  if(players[1].getHand().getNumCards() < 1){
    cout << "You draw a card.";
    players[1].getHand().addCard(cards.deal());
    displayGame();
  }
  int index = -1;
  index = checkInput("Enter the index of the card you wish to request: ", "0123456789");
  int rankChosen = players[1].getHand().getCards()[index].getRank();
  cout << "You ask for a: " << intToRank(rankChosen) << endl;

  //check if computer has any cards
  if(players[0].getHand().getNumCards() < 1){
    cout << "You draw a card.";
    players[1].getHand().addCard(cards.deal()); //go fish
    displayGame();
  }

  return rankChosen;
}

int Game::checkAndRand(){
  //no cards in hand
  if(players[0].getHand().getNumCards() < 1){
    cout << "Computer draws a card.";
    players[0].getHand().addCard(cards.deal());
    displayGame();
  }
  srand(time(NULL));
  int randInd = rand() % players[0].getHand().getNumCards();
  int rankChosen = players[0].getHand().getCards()[randInd].getRank();
  cout << "Computer asks for a: " << intToRank(rankChosen) << endl;

  //check if computer has any cards
  if(players[1].getHand().getNumCards() < 1){
    cout << "Computer draws a card.";
    players[0].getHand().addCard(cards.deal()); //go fish
    displayGame();
  }

  return rankChosen;
}

void Game::compHasMatch(int rankChosen){

  //int numOfRank = players[0].getHand().numOfRank(rankChosen);
  while(players[0].getHand().hasRank(rankChosen)){
    Card removed = players[0].getHand().removeCard(rankChosen);
    players[1].getHand().addCard(removed);
  }

  displayGame();
  //check for book
  if(players[1].getHand().checkBook(rankChosen)){
    cout << "You got a book!" << endl;
    players[1].removeBook(rankChosen);
    //gameOver();
    displayGame();
  }
}

void Game::humHasMatch(int rankChosen){

  //int numOfRank = players[1].getHand().numOfRank(rankChosen);
  while(players[1].getHand().hasRank(rankChosen)){
    Card removed = players[1].getHand().removeCard(rankChosen);
    players[0].getHand().addCard(removed);
  }

  displayGame();
  //check for book
  if(players[0].getHand().checkBook(rankChosen)){
    cout << "Computer got a book!" << endl;
    players[0].removeBook(rankChosen);
    //gameOver();
    //displayGame();
  }
}

void Game::humFish(int rankChosen, bool &myTurn){
  cout << "You Go Fish." << endl;
  Card cardDealt = cards.deal();
  int rankDealt = cardDealt.getRank();
  cout << "You draw a: " << intToRank(rankDealt) << endl;
  players[1].getHand().addCard(cardDealt);
  //displayGame();
  //check if card dealt was card requested
  if(rankDealt == rankChosen){
    cout << "You fished for what you wanted!" << endl;
    //check for books
    if(players[1].getHand().checkBook(rankChosen)){
      cout << "You got a book!" << endl;
      players[1].removeBook(rankChosen);
      //gameOver();
    }
    displayGame();
  } else {
    cout << endl;
    if(players[1].getHand().checkBook(rankDealt)){
      cout << "You got a book!" << endl;
      players[1].removeBook(rankChosen);
      //gameOver();
      displayGame();
    }
    cout << "\tCOMPUTER'S TURN!\t" << endl;
    myTurn = !myTurn;
  }
}

void Game::compFish(int rankChosen, bool &compTurn){
  cout << "Computer Go Fish." << endl;
  Card cardDealt = cards.deal();
  int rankDealt = cardDealt.getRank();
  cout << "Computer draws a: " << intToRank(rankDealt) << endl;
  players[0].getHand().addCard(cardDealt);
  //displayGame();
  //check if card dealt was card requested
  if(rankDealt == rankChosen){
    cout << "Computer fished for what it wanted!" << endl;
    //check for books
    if(players[0].getHand().checkBook(rankChosen)){
      cout << "Computer got a book!" << endl;
      players[0].removeBook(rankChosen);
      //gameOver();
      //displayGame();
    }
  } else {
    cout << endl;
    //yeet
    if(players[0].getHand().checkBook(rankDealt)){
      cout << "Computer got a book!" << endl;
      players[0].removeBook(rankChosen);
      //gameOver();
      //displayGame();
    }
    //yeet
    cout << "\tYOUR TURN!\t" << endl;
    compTurn = !compTurn;
  }
}

void Game::humanTurn(){
  displayGame();
  bool myTurn = true;
  while(myTurn){
    int rankChosen = checkAndChoose();

    //check for matching rank in computer's hand
    if(players[0].getHand().hasRank(rankChosen)){
      compHasMatch(rankChosen);
      gameOver();
    } else {
      humFish(rankChosen, myTurn);
      gameOver();
    }
  }
}

void Game::compTurn(){
  displayGame();
  bool compTurn = true;
  while(compTurn){
    int rankChosen = checkAndRand();

    //check for matching rank in human's hand
    if(players[1].getHand().hasRank(rankChosen)){
      humHasMatch(rankChosen);
      gameOver();
    } else {
      compFish(rankChosen, compTurn);
      gameOver();
    }
  }
}

void Game::beginTurns(){
  //alternate player's turns
  //logic for game
  cards.shuffleDeck();
  for(int i = 0; i < 7; i++){ /* 7 cards to player 0 */
    players[0].getHand().addCard(cards.deal());
  }

  for(int i = 0; i < 7; i++){ /* 7 cards to player 1 */
    players[1].getHand().addCard(cards.deal());
  }

  //start turns
  while(!isGameOver){
    humanTurn();
    compTurn();
  }

  cout << "GAME OVER" << endl;
  if(players[0].getNumBooks() > players[1].getNumBooks()){
    cout << "Computer Wins!" << endl;
  } else {
    cout << "You Win!" << endl;
  }

}


/******************************************************************
 * Function: main
 * Description: Executes framework of storing data and user browsing
 * Parameters: int argc, char* argv[]
 * Pre-Conditions: argc must be 2
 * Post-Conditions: argc and argv[] don't change
 ******************************************************************/
int main(int argc, char* argv[]){
  Game game = Game();
  game.beginTurns();

}
