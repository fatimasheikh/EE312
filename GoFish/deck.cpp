//Fatima Sheikh
//fs7487
//EE312 11/05/18

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deck.h"
#include "card.h"

using namespace std;

  Deck::Deck() {
    int index = 0;
    for (int suit=0; suit<4; suit++) {
      for (int rank=1; rank<14; rank++) {
          myCards[index] = Card::Card(rank, (Card::Suit) suit);
          index++;
      }
      srand((unsigned)time(0)); //seed random number generator
    }
    myIndex = 0;
    /*for (int i=0; i<SIZE; i++) {
      cout << myCards[i] << endl;
    }*/
  }

  void Deck::shuffle() {
    int i1;
    int i2;
    Card temp;

    for (int i=0; i<SIZE; i++) {
      i1 = rand() % SIZE;
      i2 = rand() % SIZE;
      if (i1 != i2) {
        temp = myCards[i1];
        myCards[i1] = myCards[i2];
        myCards[i2] = temp;
      }
    }
      /*for (int i=0; i<SIZE; i++) {
        cout << myCards[i] << endl;
      }*/
  }

  Card Deck::dealCard() {
    Card c;
    if (myIndex >= 0 && myIndex < SIZE) {
      c = myCards[myIndex];
      myIndex++;
      return c;
    }
    else {
      return myCards[0];
    }
  }

  int Deck::size() const {
    int deckSize;
    deckSize = (SIZE) - myIndex;
    return deckSize;
  }

//my function to print deck
  void Deck::showDeck() const {
    for (int i=0; i<52; i++) {
      cout << myCards[i];
      cout << endl;
    }
  }



  //Card::Suit s;
  //int suitInd = static_cast<int>(s);
//  for (Card::Suit suitInd = static_cast<int>(Card::spades); suitInd <= Card::clubs; suitInd++) {
  //for (Card::Suit suitInd = Card::spades; suitInd <= Card::clubs; suitInd++) {
  //Card::Suit suitInd = Card::spades;
  //for (int suit = Card.spades; suit <= Card.clubs; suit++) {

  //Card c(rankInd, suitInd);
  //myCards[index] = c.toString();
