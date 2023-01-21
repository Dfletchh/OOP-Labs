#ifndef HAND_H
#define HAND_H

#include <string>
#include <vector>
#include "Card.h"

class Hand {

private:
    std::vector<Card> hand {};

public:
    void operator += (Card card);   
    std::vector<Card> get_hand() const;

};
#endif