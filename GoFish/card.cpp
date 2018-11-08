//Fatima Sheikh
//fs7487
//EE312 11/04/18

#include <iostream>
//#include <cstring>
#include "card.h"

using namespace std;

  //Default card is Ace of Spades
  Card::Card() {
    myRank = 1;
    mySuit = spades;
  }

  //Card of specified rank and suit
  Card::Card(int rank, Suit s) {
    myRank = rank;
    mySuit = s;
  }

  string Card::toString() const {
    string rank = rankString(myRank);
    string suit = suitString(mySuit);
    string card = rank + suit;
    return card;
  }

  bool Card::sameSuitAs(const Card& c) const {
    return (this->mySuit == c.mySuit);
  }

  int Card::getRank() const {
    return myRank;
  }

  string Card::suitString(Suit s) const {
    string suit;
    if (s == spades) {
      suit = "s";
    }
    else if (s == hearts) {
      suit = "h";
    }
    else if (s == diamonds) {
      suit = "d";
    }
    else if (s == clubs) {
      suit = "c";
    }
    return suit;
  }

  string Card::rankString(int r) const {
    string rank;
    if (r == 1) {
      rank = "A";
    }
    else if (r == 11) {
      rank = "J";
    }
    else if (r == 12) {
      rank = "Q";
    }
    else if (r == 13) {
      rank = "K";
    }
    else {
      rank = to_string(r);
    }
    return rank;
  }

  bool Card::operator ==(const Card& rhs) const {
    return ((myRank == rhs.myRank) && (mySuit == rhs.mySuit));
  }

  bool Card::operator !=(const Card& rhs) const {
    return ((myRank != rhs.myRank) || (mySuit != rhs.mySuit));

  }
  ostream& operator << (ostream& out, const Card& c) {
    out << c.toString();
    return out;

  }
