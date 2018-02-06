//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//header deck.h

#ifndef DECK_H
#define DECK_H

#include "node.h"
#include <cstdlib>
#include <time.h>

//creating a class called deck
class deck{

public:
    //default constructor
    deck();

    //head node - start of linked list
    node *head;

    //current node as you navigate through linked list
    node *current;

    void shuffle();
    //Free function that grants access to print the deck
    friend std::ostream& operator <<(std::ostream&, deck &d);
    
    //Replace function
    void replace(card& bottom);
    
    //Returns the top card 
    card deal();
};

#endif // DECK_H
