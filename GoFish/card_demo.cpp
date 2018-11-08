// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
  int numCards = 7;

  Player p1("Joe");
  Player p2("Jane");

  Deck d;
  d.shuffle();
  d.showDeck(); //testing

  dealHand(d, p1, numCards);
  dealHand(d, p2, numCards);

  cout << p1.getName() <<" has : " << p1.showHand() << endl; //testing
  cout << p2.getName() <<" has : " << p2.showHand() << endl; //testing

  Card card1;
  Card card2;
  bool book;

  //remove all books from hand
  book = p1.checkHandForBook(card1, card2);
  cout << book << " " << card1 << " " << card2 << endl; //testing
  if (book) {
    while (book) {
      p1.bookCards(card1, card2);
      book = p1.checkHandForBook(card1, card2);
    }
  }
  cout << p1.showBooks() << endl; //testing
  cout << p1.showHand() << endl; //testing

  book = p2.checkHandForBook(card1, card2);
  cout << book << " " << card1 << " " << card2 << endl; //testing
  if (book) {
    while (book) {
      p2.bookCards(card1, card2);
      book = p2.checkHandForBook(card1, card2);
    }
  }
  cout << p2.showBooks() << endl; //testing
  cout << p2.showHand() << endl; //testing

  //choose card from hand
  Card cardA;
  cardA = p1.chooseCardFromHand();
  cout << p1.getName() << " asks - Do you have a " << cardA.rankString(cardA.getRank()) << "?" << endl; //testing

  //ask if other player has this card
  Card cardB;
  bool success;
  success = p2.rankInHand(cardA);
  cout << success << endl; //testing
  if (success) {
    cout << p2.getName() << " says - Yes. I have a " <<cardA.rankString(cardA.getRank()) << "." << endl;
    cardB = p2.removeCardFromHand(cardA);
    cout << "cardA: " << cardA << endl; //testing
    cout << "cardB: " << cardB << endl; //testing
    cout << "Player 1 hand: " << p1.showHand() << endl; //testing
    cout << "Player 2 hand: " << p2.showHand() << endl; //testing


  }





  /*  int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;*/

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

/*  Card c;
  cout << c << endl;
  Card c1(5,Card::hearts);
  cout << c1 << endl;
  Card c2(13,Card::diamonds);
  cout << c2 << endl;

  Deck d;
  cout << endl;
  d.shuffle();
  cout << endl;
  for (int i=0; i<52; i++) {
    cout << d.dealCard();
    cout << endl;
    cout << d.size();
    cout << endl;
  }

  Player p1;
  Player p2("Joe");
  cout << p1.getName() << endl;
  cout << p2.getName() << endl;

  Card cA(3,Card::hearts);
  Card cB(8,Card::diamonds);

  p1.addCard(cA);
  p2.addCard(cB);

  p1.showHand();
  p2.showHand();*/
