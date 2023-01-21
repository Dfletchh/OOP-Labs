#ifndef CARD_H
#define CARD_H

#include "Hand.h"
#include <string>
#include <vector>

class Card {

private:
    std::vector<std::string> rank {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    std::vector<std::string> suit {"Clubs","Diamonds","Hearts","Spades"};

public:
    std::string get_card(int suit_param, int rank_param); 
    std::ostream& operator << (std::ostream& output, Hand hand);
};
#endif