//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//class node.cpp

//header file inclusion
#include "node.h"

node::node(std::string suits ,std::string number){
    //identify the card
    value.Point(number);
    value.Suit(suits);

    //set the previous and next to NULL by default
    previous = NULL;
    next = NULL;
}

//constructor with no input
node::node(){
    std::string nullValue = "NULL";
    value.Point(nullValue);
    value.Suit(nullValue);
    //set the previous and next to NULL by default
    previous = NULL;
    next = NULL;
}

node::node(card& newCard){
    value = newCard;
    previous = NULL;
    next = NULL;
}
