//Fatima Sheikh
//fs7487
//EE312 11/05/2018

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include "player.h"
#include "deck.h"
#include "card.h"

using namespace std;

  Player::Player() {
    static int playerNum = 1;
    //int to string conversion
    string playerString;
    stringstream ss;
    ss << playerNum;
    playerString = ss.str();
    myName = "Player " + playerString; //want to do player 1, player 2, etc.
    playerNum++;
    srand((unsigned)time(0));
  }

  void Player::addCard(Card c) {
    myHand.push_back(c);
  }

  void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    c1 = removeCardFromHand(c1);
    myBook.push_back(c2);
    c2 = removeCardFromHand(c2);
  }

  bool Player::checkHandForBook(Card &c1, Card &c2) {
    int size = myHand.size();
    for (int i=0; i<size; i++) {
      c1 = myHand[i];
      for (int j = i+1; j<size; j++) {
        c2 = myHand[j];
        if (c1.getRank() == c2.getRank()) {
          return true;
        }
      }
    }
    return false;
  }

  bool Player::rankInHand(Card c) const {
    int size = myHand.size();
    for (int i=0; i<size; i++) {
      if (c.getRank() == myHand[i].getRank()) {
        return true;
      }
    }
    return false;
  }

  Card Player::chooseCardFromHand() const {
    int size = myHand.size();
    int index = rand() % size;
    Card c = myHand[index];
    return c;
  }

  bool Player::cardInHand(Card c) const {
    int size = myHand.size();
    for (int i=0; i<size; i++) {
      if (myHand[i] == c) {
        return true;
      }
    }
    return false;
  }

  Card Player::removeCardFromHand(Card c) {
    Card newC;
    int size = myHand.size();
    for (int i=0; i<size; i++) {
      if (myHand[i].getRank() == c.getRank()) { //changed to remove card with same rank
        newC = myHand[i];
        myHand.erase(myHand.begin()+i);
        return newC;
      }
    }
      return c;
  }

  string Player::showHand() const {
    string hand;
    string temp;
    std::vector<Card>::const_iterator it;
    for (it = myHand.begin(); it != myHand.end(); it++) {
      temp = (*it).toString();
      hand = hand + temp + " ";
    }
    return hand;
  }

  string Player::showBooks() const {
    string books;
    string temp;
    std::vector<Card>::const_iterator it;
    for (it = myBook.begin(); it != myBook.end(); it++) {
      temp = (*it).toString();
      books = books + temp + " ";
    }
    return books;
  }

  int Player::getHandSize() const {
    int size = myHand.size();
    return size;
  }

  int Player::getBookSize() const {
    int size = myBook.size();
    return size;
  }
