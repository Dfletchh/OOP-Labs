#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>

class Deck {

private:
    std::vector<std::string> deck;
    std::string a_card;

public:
    void shuffle_deck(); 
    int deck_size();
    std::string deal_card();
    void set_deck();
};
#endif