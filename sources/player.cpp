#include "player.hpp"

namespace ariel {

    void Player::setName(string playerName) {
        this->name = playerName;
    }

    void Player::addCard(Card c){
      this->cards.insert(this->cards.begin(), c);
    }

    void Player::addToCardsWon(int toAdd){
      this->cardsWon += toAdd;
    }

    void Player::addToTurnsWon(int toAdd){
      this->turnsWon += toAdd;
    }


    int Player::getCardsWon() const{
        return this->cardsWon;
    };

    int Player::getTurnsWon() const{
        return this->turnsWon;
    };

    Card Player::drawCard() {
      Card topCard = this->cards.back();
      this->cards.pop_back();
      return topCard;
    }
  
    string Player::getName() const{
        return name;
    }

    int Player::stacksize(){
      return this->cards.size();
    };

    int Player::cardesTaken() const{
      return this->cardsWon;
    }

}
