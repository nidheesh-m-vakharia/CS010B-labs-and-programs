#include "../Card.h"
#include <iostream>

using namespace std;

int main() {
    Card card1;
    Card card2('S', 10);
    Card card3('d', 12);
    Card card4('x', 13);
    Card card5('h', 16);
    Card card6('D', 1);

    cout << card1 << endl;
    cout << card2 << endl;
    cout << card3 << endl;
    cout << card4 << endl;
    cout << card5 << endl;
    cout << card6 << endl;
    return 0;

}