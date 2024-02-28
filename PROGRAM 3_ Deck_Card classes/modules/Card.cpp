#include "Card.h"
#include <iostream>
#include <vector>

using namespace std;

struct Rank {
   int number;
   string name;

   Rank(int, string);
};

Rank::Rank(int number_, string name_)
    : number(number_), name(name_)
{}

vector<Rank> BuildRanks() {
    vector<Rank> temp;
    temp.push_back(Rank(1, "Ace"));
    temp.push_back(Rank(2, "2"));
    temp.push_back(Rank(3, "3"));
    temp.push_back(Rank(4, "4"));
    temp.push_back(Rank(5, "5"));
    temp.push_back(Rank(6, "6"));
    temp.push_back(Rank(7, "7"));
    temp.push_back(Rank(8, "8"));
    temp.push_back(Rank(9, "9"));
    temp.push_back(Rank(10, "10"));
    temp.push_back(Rank(11, "Jack"));
    temp.push_back(Rank(12, "Queen"));
    temp.push_back(Rank(13, "King"));
    return temp;
}

string findRank(const vector<Rank>& v, int num) {
    for (const Rank& rank: v) {
        if (rank.number == num) {
            return rank.name;
        }
    }

    return "NaN";
}

Card::Card()
    : suit('c'), rank(2)
{}

Card::Card(char suit_, int rank_) 
    : suit(suit_), rank(rank_)
{   
    suit = towlower(suit);

    if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's') {
        suit = 'c';
    }

    if (rank < 1 || rank > 13) {
        rank = 2;
    }


}

//Accessors
char Card::getSuit() const {return suit;}

int Card::getRank() const {return rank;}

ostream & operator<<(ostream & out, const Card & card) {
    vector<Rank> rankMap = BuildRanks();

    out << findRank(rankMap, card.rank) << " of ";
    switch (card.suit) {
        case 'c':
            out << "Clubs";
            break;

        case 's':
            out << "Spades";
            break;

        case 'd':
            out << "Diamonds";
            break;

        case 'h':
            out << "Hearts";
            break;

        default:
            out << "Clubs";
            break;
    }
     return out;
}