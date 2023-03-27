#pragma once
#include "card.hpp"
#include <string>
#include <vector>

namespace ariel {
using namespace std;

class Player {
  private:
    string name;
    vector<Card> cards;
  
  public:
    Player(string playerName) {
        name = move(playerName);
    }
  
    void setName(string playerName) {
        name = move(playerName);
    }
  
    string getName() const {
        return name;
    }

    int stacksize();
    int cardesTaken();
};
}