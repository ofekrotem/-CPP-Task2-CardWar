#pragma once
#include "player.hpp"
#include <vector>
namespace ariel {

class Game {
  private:
    Player player1;
    Player player2;
  
  public:
    Game(Player& p1, Player& p2) : player1(p1), player2(p2){}

    Player getFirstPlayer(){
        return player1;
    }

    Player getSecondPlayer(){
        return player2;
    }

    void playTurn();
    void printLastTurn();
    void playAll();
    void printWiner();
    void printLog();
    void printStats();
};
}