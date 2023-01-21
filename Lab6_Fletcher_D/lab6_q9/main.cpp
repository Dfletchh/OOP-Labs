/* 
* Auhtor: Dean Fletcher
* Purpose: This program deals playing cards to the user. Once the program runs a deck of cards
*          is created via Deck and Card classes. The deck is held inside the Deck object and is
*          is then shuffled. The user is prompted how many cards is in the deck and asks how many
*          cards they would like. The cards are drawn from the deck, deleted from the deck, and 
*          then prompted to the user. The new deck size is prompted and the program terminates. 
*/

#include "Deck.h"
#include "console.h"
#include <iostream>

using namespace std;

int main() 
{
    int num_cards, min = 0;
    int max = 52;
    string card;
    Deck deck; // deck object 

    cout << "Card Dealer" << endl << endl;

    deck.set_deck(); // gets a fresh deck of cards
    deck.shuffle_deck(); // shuffles deck of cards
    
    cout << "I have shuffled a deck of " << deck.deck_size() << " cards." << endl << endl;

    num_cards = console::get_int("How many cards would you like?: ", min, max); // input validation 

    cout << "\nHere are your cards:" << endl;
    for (int i = 0; i < num_cards; i++) { // deal card loops
        card = deck.deal_card(); // gets a card from the deck
        cout << card << endl;
    }
    cout << "\nThere are " << deck.deck_size() << " cards left in the deck." << endl;
    cout << "\nGood luck!" << endl;

    return 0;
}