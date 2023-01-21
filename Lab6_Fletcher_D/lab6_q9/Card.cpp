#include "Card.h"
#include "Hand.h"
#include <string>
#include <vector>

// Creates a string representation of a playing card
std::string Card::get_card(int suit_param, int rank_param) {
    return rank[rank_param] + " of " + suit[suit_param];
}
std::ostream& operator << (std::ostream& output, Hand hand) {
    for (Hand it : hand) {
        output << hand << std::endl;
    }
}
