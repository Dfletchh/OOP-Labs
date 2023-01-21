#include "Hand.h"
#include "Card.h"
#include <vector>

void Hand::operator += (Card card_param) {   
    hand.push_back(card_param);
}
std::vector<Card> Hand::get_hand() const {
    return hand;
}