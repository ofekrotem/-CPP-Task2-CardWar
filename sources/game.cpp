#include "game.hpp"
#include <iostream>
namespace ariel {


void Game::playTurn() {
    if(this->running){
        if (player1.stacksize() == 0 && player2.stacksize() == 0) {
            this->running = false;
            if (player1.getCardsWon() > this->player2.getCardsWon()){
                this->winner = player1;
            } else if (player1.getCardsWon() < this->player2.getCardsWon()){
                this->winner = player2;
            }else {
                Player win("Game ended with a draw!");
                this->winner = win;
            }
            return;
        }
        this->turnsPlayed +=1;
        this->lastTurn ="";
        Card p1  = this->player1.drawCard();
        Card p2 = this->player2.drawCard();
        cardsDeck.push_back(p1);
        cardsDeck.push_back(p2);
        bool turn = false;
        int diff = p1.getVal() - p2.getVal();
        while (!turn){
            if (p1.getVal() != 0 && p2.getVal() != 0){
                diff = p1.getVal() - p2.getVal();

                if(diff > 0){
                    this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". " + player1.getName() + " wins.";
                    turn = true;
                    this->player1.addToTurnsWon(1);
                    this->player1.addToCardsWon(cardsDeck.size());
                    this->cardsDeck.clear();
                }
                else if (diff < 0)
                {
                    this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". " + player2.getName() + " wins.";
                    turn = true;
                    this->player2.addToTurnsWon(1);
                    this->player2.addToCardsWon(cardsDeck.size());
                    this->cardsDeck.clear();
                }
                else
                {
                    this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". Draw. ";
                    this->draws +=1;

                    if(player1.stacksize() < 2 || player2.stacksize() < 2){
                        turn = true;
                        this->cardsDeck.clear();
                        Player win("Game ended with a draw!");
                        this->winner = win;
                        this->running = false;
                        return;
                    }
                    p1  = this->player1.drawCard();
                    p2 = this->player2.drawCard();
                    cardsDeck.push_back(p1);
                    cardsDeck.push_back(p2);
                    p1  = this->player1.drawCard();
                    p2 = this->player2.drawCard();
                    cardsDeck.push_back(p1);
                    cardsDeck.push_back(p2);    
                }
            } else {
                if (p1.getVal() == 0 && p2.getVal() == 0){
                    this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". Draw. ";
                    this->draws +=1;

                    if(player1.stacksize() < 2 || player2.stacksize() < 2){
                        turn = true;
                        this->cardsDeck.clear();
                        Player win("Game ended with a draw!");
                        this->winner = win;
                        this->running = false;
                        return;
                    }
                    p1  = this->player1.drawCard();
                    p2 = this->player2.drawCard();
                    cardsDeck.push_back(p1);
                    cardsDeck.push_back(p2);
                    p1  = this->player1.drawCard();
                    p2 = this->player2.drawCard();
                    cardsDeck.push_back(p1);
                    cardsDeck.push_back(p2); 
                } else if (p1.getVal() == 0){
                    if (p2.getVal() == 1) {
                        this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". " + player2.getName() + " wins.";
                        this->player2.addToCardsWon(this->cardsDeck.size());
                        this->player2.addToTurnsWon(1);
                    } else {
                        this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". " + player1.getName() + " wins.";
                        this->player1.addToCardsWon(this->cardsDeck.size());
                        this->player1.addToTurnsWon(1);
                    }
                    turn = true;
                    this->cardsDeck.clear();
                } else {
                    if (p1.getVal() == 1) {
                        this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". " + player1.getName() + " wins.";
                        this->player1.addToCardsWon(this->cardsDeck.size());
                        this->player1.addToTurnsWon(1);
                    } else {
                        this->lastTurn += player1.getName() + " played " + p1.toString() + " " + player2.getName() + " played " + p2.toString() + ". " + player2.getName() + " wins.";
                        this->player2.addToCardsWon(this->cardsDeck.size());
                        this->player2.addToTurnsWon(1);
                    }
                    turn = true;
                    this->cardsDeck.clear();
                }
            }
        }
        this->logs.push_back(lastTurn);
    
    } else{
        __throw_logic_error("Game over!");
    }
}

void Game::printLastTurn() const {
    cout << this->lastTurn << endl;
}

void Game::playAll() {
    while (this->running)
    {
        this->playTurn();
    }
    
}

void Game::printWiner() {
    if(this->running){
        cout << "Game is still running, no winner yet!" << endl;
        return;
    }
    cout << this->winner.getName() << endl;
}

void Game::printLog() const{
    for(unsigned int i=0; i<this->logs.size();i++){
        cout << this->logs[i] << endl;
    }
}

void Game::printStats() const{
    float p1WinRate = (float(this->player1.getTurnsWon())/this->turnsPlayed)*100;
    float p2WinRate = (float(this->player2.getTurnsWon())/this->turnsPlayed)*100;
    float drawRate = (float(this->draws)/float(this->turnsPlayed))*100;
    cout << this->player1.getName() << ":" << endl << "Cards won: " << to_string(player1.getCardsWon()) << endl << "Win rate: " << to_string(p1WinRate) << "%" << endl << endl << this->player2.getName() << ":" << endl << "Cards won: " << this->player2.getCardsWon() << endl << "Win rate: " << to_string(p2WinRate) << "%" << endl << endl << "Game stats:"  << endl << "Number of draws: " << to_string(this->draws) << endl << "Draw rate: " << to_string(drawRate) << "%" << endl;
}




}
