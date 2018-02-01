//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//header deck.h

#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <cstdlib>
#include <time.h>

//creating a class called deck
class deck{

public:
    //default constructor
    deck();

    //head node - start of linked list
    card *head;

    //current node as you navigate through linked list
    card *current;

    void shuffle();
    //Free function that grants access to print the deck
    friend std::ostream& operator <<(std::ostream&, deck &d);
};

#endif // DECK_H
