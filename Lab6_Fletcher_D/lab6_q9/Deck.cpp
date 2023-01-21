#include "Deck.h"
#include "Card.h"
#include <vector>
#include <algorithm>    // std::shuffle
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock


void Deck::shuffle_deck() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count(); // obtain a time-based seed:
    shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));
}
int Deck::deck_size() {
    return deck.size(); // deck size
}
std::string Deck::deal_card() {
    a_card = deck.front(); // get a card
    deck.erase(deck.begin()); // remove card
    return a_card; // deal card
}
void Deck::set_deck() { 
    Card card; // card object
    for (int i = 0; i < 4; i++) { // suit
        for (int j = 0; j < 13; j++) { // rank
            a_card = card.get_card(i, j); // returns a card 
            deck.push_back(a_card); // adds card to deck
        }
    }
}