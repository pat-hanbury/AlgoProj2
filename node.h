//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//class card.cpp

#ifndef NODE_H
#define NODE_H

#include "card.h"
#include <iostream>
#include <string>


//creating a class called card
class node{
public:
    //Member variables
    card value;
    node *next;
    node *previous;

    //member functions
    node(std::string suits, std::string number);
    node();
    node(card& newCard);


private:
};

#endif //NODE_H
