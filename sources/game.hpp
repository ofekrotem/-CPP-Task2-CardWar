#pragma once
#include "player.hpp"
#include "card.hpp"
#include <vector>
#include <ctime>
#include <array>
#include <cstddef>

using namespace std;
namespace ariel {
const int SHAPE_NUM = 4;
const int CARDS_NUM = 13;
const int BASIC_STACK_SIZE = 26;
class Game {
  private:
    //int deck[CARDS_NUM][SHAPE_NUM]={};
    array<array<int, SHAPE_NUM>, CARDS_NUM> deck = {};
    Player& player1;
    Player& player2;
    vector<Card> cardsDeck;
    int draws;
    string lastTurn;
    vector<string> logs;
    bool running;
    Player winner;
    int turnsPlayed;
  
  public:
     Game(Player& p1, Player& p2) : player1(p1), player2(p2){
      if (p1.getName() == p2.getName()){
        this->running = false;
        return;
      }
      this->draws = 0;
      this->turnsPlayed = 0;
      this->lastTurn = "";
      this->running = true;
      srand(time(NULL));
      int counter=0;
      size_t i=0;
      size_t j=0;
      while(counter<BASIC_STACK_SIZE){
        i= static_cast<size_t>(rand()%CARDS_NUM);
        j=static_cast<size_t>(rand()%SHAPE_NUM);
        if(this->deck.at(i).at(j)==0){
          this->deck.at(i).at(j)=1;
          counter++;
          Card card(i,j);
          
          this->player1.addCard(card);
        }
      }
      counter=0;
      while(counter<BASIC_STACK_SIZE){
        i= static_cast<size_t>(rand()%CARDS_NUM);
        j=static_cast<size_t>(rand()%SHAPE_NUM);
        if(this->deck.at(i).at(j)==0){
          this->deck.at(i).at(j)=2;
          counter++;
          Card card(i,j);
          
          this->player2.addCard(card);
        }
      }
    }

    Player getFirstPlayer() const{
        return player1;
    }

    Player getSecondPlayer() const{
        return player2;
    }

    Player getWinner() const{
        return winner;
    }

    void setWinner(Player w){
        this->winner = move(w);
    }

    void playTurn();

    void printLastTurn() const;
    void playAll();
    void printWiner();
    void printLog() const;
    void printStats() const;
};
}