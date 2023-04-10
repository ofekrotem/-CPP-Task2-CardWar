#pragma once
#include <string>
#include <iostream>

using namespace std;
const int ERROR = -1;
const int ACE_OR_HEARTS = 0;
const int SPADES = 1;
const int DIAMONDS = 2;
const int CLUBS = 3;
const int JACK = 10;
const int QUEEN = 11;
const int KING = 12;

class Card {
    private:
        int val;
        int shape;

    public:
        Card(int value, int cardShape){
            this->val = value;
            this->shape = cardShape;
        }
        Card(){
            this->val = ERROR;
            this->shape = ERROR;
        }
        
        int getVal() const{
            return this->val;
        }

        int getShape() const{
            return this->shape;
        }

        string toString() const{
            string printShape;
            switch (this->shape)
            {
            case ACE_OR_HEARTS:
                printShape = "Hearts";
                break;
            case SPADES:
                printShape = "Spades";
                break;
            case DIAMONDS:
                printShape = "Diamonds";
                break;
            case CLUBS:
                printShape = "Clubs";
                break;
            default:
                cout <<"invalid shape: " << to_string(this->shape);
                __throw_invalid_argument("Invalid shape");
                break;
            }

            switch (this->val)
            {
            case ACE_OR_HEARTS:
                return "Ace of " + printShape; 
                break;
            case JACK:
                return "Jack of " + printShape;
                break;
            case QUEEN:
                return "Queen of " + printShape;
                break;
            case KING:
                return "King of " + printShape;
                break;
            default:
                return to_string(this->val+1) + " of " + printShape;
                break;
            }          
            
        }
};          