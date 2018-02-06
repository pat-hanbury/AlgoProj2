//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//class card.cpp

//header file inclusion
#include "card.h"


//Suit function that passes the argument suit by reference.
void card::Suit(std::string &suit){
    //Creates the variable suit
    this->suit = suit;
}

//Point function that passes the argument point by reference
void card::Point(std::string &point){
     //Creates the variable point
    this->point = point;
}

//Accesses a private string for the variable suit
std::string card::getSuit(){
     //Returns the variable suit.
    return suit;
}

//Accesses a private string for the variable point
std::string card::getPoint(){
    //Returns the variable point.
    return point;
}

//Constructor with two parameters, suit and point, and passes them by reference.
card::card(std::string &suit, std::string &point) {
    //First function calls the function Suit with suit as the string variable
    Suit(suit);
    //Second function calls the function Point with point as the string variable.
    Point(point);
}

card::card(){
    suit = "NULL";
    point = "NULL";
}

//copy constructor
card::card(const card &copiedCard){
    suit = copiedCard.suit;
    point = copiedCard.point;
}