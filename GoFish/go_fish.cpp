//Fatima Sheikh
//fs7487
//EE312, 11/09/18
//Driver program for Go Fish

#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
bool dealCard(Deck &d, Player &p, Card &c);
bool checkCardsInHand(Player &p);
void switchPlayers(Player& currentPlayer, Player& otherPlayer);
void showResult(Player& currentPlayer, Player& otherPlayer, ofstream& myFile);



int main( )
{
    ofstream myFile;
    myFile.open("gofish_results.txt");

    int numCards = 7;
    int numPlayers = 2;

    Player p1("Joe");
    Player p2("Jane");

    Player& currentPlayer = p1;
    Player& otherPlayer = p2;

    Deck d;
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    Card card1;
    Card card2;
    Card card3;

    bool book;

    //remove all books from both hands
    for (int i=0; i<numPlayers; i++) {
      book = currentPlayer.checkHandForBook(card1, card2);
        while (book) {
          currentPlayer.bookCards(card1, card2);
          myFile << currentPlayer.getName() << " books " << card1.toString() << " & " << card2.toString() << "." << endl;
          book = currentPlayer.checkHandForBook(card1, card2);
        }
      switchPlayers(currentPlayer, otherPlayer);
      myFile << endl;
    }

    bool cardsInDeck;
    bool cardsInHand;

    //Game continues until no cards left in deck and no cards left in both players' hands
    while (d.size() > 0 || currentPlayer.getHandSize() > 0 || otherPlayer.getHandSize() > 0) {

      //checks if player has cards in hand
      cardsInHand = checkCardsInHand(currentPlayer);
      while (!cardsInHand) {
        cardsInDeck = dealCard(d, p1, card3);
        if (!cardsInDeck) {
          showResult(currentPlayer, otherPlayer, myFile);
          return EXIT_SUCCESS;
        }
        switchPlayers(currentPlayer, otherPlayer);
        cardsInHand = checkCardsInHand(currentPlayer);
      }

      //choose card from hand
      card1 = currentPlayer.chooseCardFromHand();
      myFile << currentPlayer.getName() << " asks - Do you have a " << card1.rankString(card1.getRank()) << "?" << endl;

      //ask if other player has card with same rank
      bool success;
      success = otherPlayer.rankInHand(card1);

      //player successful when asking other player
      if (success) {
        myFile << otherPlayer.getName() << " says - Yes. I have a " << card1.rankString(card1.getRank()) << "." << endl;
        card2 = otherPlayer.removeCardFromHand(card1);
        currentPlayer.addCard(card2);
        currentPlayer.bookCards(card1, card2);
        myFile << currentPlayer.getName() << " books " << card1.toString() << " & " << card2.toString() << "." << endl;
      }

      //player not successful when asking other player
      else {
        myFile << otherPlayer.getName() << " says - Go Fish" << endl;
        cardsInDeck = dealCard(d, currentPlayer, card3); //checks if cards are left in deck, if not end game (need to add)
        if (!cardsInDeck) {
          showResult(currentPlayer, otherPlayer, myFile);
          return EXIT_SUCCESS;
        }
        myFile << currentPlayer.getName() << " draws " << card3.toString() << endl;
        book = currentPlayer.checkHandForBook(card1, card2);
        if (book) {
          currentPlayer.bookCards(card1, card2);
          myFile << currentPlayer.getName() << " books " << card1.toString() << " & " << card2.toString() << "." << endl;
        }
        else {
        switchPlayers(currentPlayer, otherPlayer);
        }
      }
      myFile << endl;
    }

    showResult(currentPlayer, otherPlayer, myFile);

    return EXIT_SUCCESS;
}


//deals hand at start of game
void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

//checks if deck has cards, deals one card from deck and adds it to hand
bool dealCard(Deck &d, Player &p, Card &c) {
  int numCardsInDeck = d.size();
  if (numCardsInDeck > 0) {
    c = d.dealCard();
    p.addCard(c);
    return true;
  }
  else return false;
}

//checks if player has cards in hand
bool checkCardsInHand(Player &p) {
  int numCardsInHand = p.getHandSize();
  if (numCardsInHand > 0) {
    return true;
  }
  return false;
}

//switches players turns
void switchPlayers(Player& currentPlayer, Player& otherPlayer) {
  Player temp;
  temp = currentPlayer;
  currentPlayer = otherPlayer;
  otherPlayer = temp;
}

//outputs result of game
void showResult(Player& currentPlayer, Player& otherPlayer, ofstream& myFile) {
  int currentPBooks = (currentPlayer.getBookSize())/2;
  int otherPBooks = (otherPlayer.getBookSize())/2;
  if (currentPBooks > otherPBooks) {
    myFile << "Winner is " << currentPlayer.getName() << endl << endl;
    myFile << currentPlayer.getName() << " has " << currentPBooks << " books." << endl;
    myFile << currentPlayer.getName() << "'s books: " << currentPlayer.showBooks() << endl << endl;
    myFile << otherPlayer.getName() << " has " << otherPBooks << " books." << endl;
    myFile << otherPlayer.getName() << "'s books: " << otherPlayer.showBooks() << endl;
  }
  else if (currentPBooks == otherPBooks) {
    myFile << "Tie" << endl;
    myFile << currentPlayer.getName() << " has " << currentPBooks << " books." << endl;
    myFile << currentPlayer.getName() << "'s books: " << currentPlayer.showBooks() << endl << endl;
    myFile << otherPlayer.getName() << " has " << otherPBooks << " books." << endl;
    myFile << otherPlayer.getName() << "'s books: " << otherPlayer.showBooks() << endl;
  }
  else {
    myFile << "Winner is " << otherPlayer.getName() << endl << endl;
    myFile << otherPlayer.getName() << " has " << otherPBooks << " books." << endl;
    myFile << otherPlayer.getName() << "'s books: " << otherPlayer.showBooks() << endl << endl;
    myFile << currentPlayer.getName() << " has " << currentPBooks << " books." << endl;
    myFile << currentPlayer.getName() << "'s books: " << currentPlayer.showBooks() << endl;
  }
}
