#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

#include ".\modules\Deck.h"
#include ".\modules\Card.h"

const string& toSentenceCase(string& word) {
    for (unsigned i = 0; i < word.size(); ++i) {
        if (i == 0) {
            word[i] = toupper(word[i]);
        }
        else {
            word[i] = tolower(word[i]);
        }
    }
    return word;
}

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &cards) {
    for (vector<Card>::const_iterator ii = cards.begin(); ii + 1 != cards.end(); ++ii) {
        for (vector<Card>::const_iterator subii = ii + 1; subii != cards.end(); ++subii) {
            if (subii->getRank() == ii->getRank()) {
                return true;
            }
        }
    }
    return false;
}

// Sends to output stream a hand of Cards on a single line, 
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs 
ostream & operator<<(ostream &out, const vector<Card> &cards) {
    for (
        vector<Card>::const_iterator cardPtr = cards.begin(); 
        cardPtr != cards.end(); 
        ++cardPtr
    )
    {
        out << *cardPtr;
        if (cardPtr + 1 != cards.end()) {
            out << ", ";
        }
    }
    return out;
}

int main() {
    srand(2222);

    unsigned numPairs {0};
    string userDecison;
    bool toFile;
    unsigned cardsPerHand;
    unsigned numberOfDeals;
    string fileName;
    Deck mainDeck;
    ofstream fout;
    double probability;



    cout  << "Do you want to output all hands to a file?(Yes/No) ";
    cin >> userDecison;

    while (true) {
        if (cin.fail() || cin.bad()) {
            cin.clear();
            cout << "\nInvalid input: Stream Failiure";
            exit(-1);
        }
        if (!((toSentenceCase(userDecison) == "Yes") || (toSentenceCase(userDecison) == "No")))
        {
            cout  << "\nDo you want to output all hands to a file?(Yes/No) ";
            cin >> userDecison;
        }

        else {
            toFile = (toSentenceCase(userDecison) == "Yes");
            break;
        }
    }

    if (toFile) {
        cout << "\n\nEnter name of output file: ";
        cin >> fileName;
        if (cin.fail()) {
            cin.clear();
            cout << "\nInvalid input: Stream Failiure";
            exit(-1);
        }
        fout.open(fileName);
        if (!fout.is_open()) {
            cout << "Error: could not load " << fileName << endl;
            exit(-1);
        }


    }

    cout << "\n\nEnter number of cards per hand: ";

    cin >> cardsPerHand;
    if (cin.fail()) {
        cin.clear();
        cout << "Invalid input: Stream Faliure";
        exit(-1);
    }

    cout << "\n\nEnter number of deals (simulations): ";

    cin >> numberOfDeals;
    if (cin.fail()) {
        cin.clear();
        cout << "Invalid input: Stream Faliure";
        exit(-1);
    }

    for (unsigned i = 0; i < numberOfDeals; i++) {
        vector<Card> cardsDealt(0);
        bool isPair = false;

        mainDeck.shuffleDeck(); //check of ourput doesnt match

        for (unsigned j = 0; j < cardsPerHand; j++) {
            cardsDealt.push_back(mainDeck.dealCard());
        }
        if (hasPair(cardsDealt)) {
            isPair = true;
            ++numPairs;
            if (toFile) {
                fout << "Found Pair!! ";
            }
        }
        if (!isPair && toFile) {
            fout << "             ";
        }


        if (toFile) {
            fout << cardsDealt << '\n';
        }
    }

    probability =  (numPairs * 100.0) / numberOfDeals;
    cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: " << probability << '%'<< endl;
    return 0;
}