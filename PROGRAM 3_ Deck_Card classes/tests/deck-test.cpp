#include <iostream>
#include "../Deck.h"
#include "../Card.h"

using namespace std;

int main(){
    Deck deck;

    #ifdef TESTING
    deck.PrintDeck(); 
    #endif
    deck.shuffleDeck();
    #ifdef TESTING
    deck.PrintDeck();
    #endif

    vector<Deck> cardsDealt;
    
}