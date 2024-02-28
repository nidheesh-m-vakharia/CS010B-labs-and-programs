#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

Deck::Deck()
    : theDeck(vector<Card>()), dealtCards(vector<Card>())
{
    for (int i = 51; i != -1; --i) {

        int divFac = i / 13;
        int modFac = i % 13;

        if (divFac == 0) {
            theDeck.push_back(Card('c', modFac + 1));
        }

        if (divFac == 1) {
            theDeck.push_back(Card('d', modFac + 1));
        }

        if (divFac == 2) {
            theDeck.push_back(Card('h', modFac + 1));
        }

        if (divFac == 3) {
            theDeck.push_back(Card('s', modFac + 1));
        }
    }
}

Card Deck::dealCard() {
    Card dealtCard = theDeck[theDeck.size() - 1];
    theDeck.pop_back();
    dealtCards.push_back(dealtCard);
    return dealtCard;
}

void Deck::shuffleDeck() {
    for (Card card: dealtCards) {
        theDeck.push_back(card);
    }
    dealtCards.clear();
    random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const {return theDeck.size();}

#ifdef TESTING
    #if TESTING
vector<Card> Deck::getDeck() const {return theDeck;}
vector<Card> Deck::getDealtCards() const {return dealtCards;}
void Deck::PrintDeck() const {

    auto print = [](Card c){
        cout <<"---> " << c << endl;
    };
    cout << "Current Deck:\n";
    for (Card c: theDeck) { print(c);}

    cout << "Dealt Cards:\n";
    for (Card c: dealtCards) {print(c);} 
}
    #endif
#endif