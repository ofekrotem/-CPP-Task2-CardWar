#pragma once
#include "card.hpp"
#include <string>
#include <vector>
#include <iostream>

namespace ariel {
using namespace std;

class Player {
  private:
    string name;
    vector<Card> cards;
    int turnsWon;
    int cardsWon;
  
  public:
    Player(string playerName) {
        this->name = move(playerName);
        this->cardsWon = 0;
        this->turnsWon = 0;

    }
    Player(){
      this->name = "Afhad";
        this->cardsWon = 0;
        this->turnsWon = 0;
    }
    void printDeck(){
      for(unsigned int i = 0; i< this->cards.size();i++){
        cout << this->cards[i].toString() << endl;
      }
    }
    void setName(string playerName);

    void addCard(Card c);

    void addToCardsWon(int toAdd);

    void addToTurnsWon(int toAdd);
    
    int getCardsWon() const;

    int getTurnsWon() const;

    Card drawCard();
  
    string getName() const;

    int stacksize();

    int cardesTaken() const;
};
}