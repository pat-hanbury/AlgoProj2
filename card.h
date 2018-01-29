//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//class card.cpp

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>


//creating a class called card
class card{

public:
    //default constructor
    card();

    //next pointer
    card * next;

    //Suit function that passes a string by reference
        //Sets the private variable suit
    void Suit(std::string&);

    //Point function that passes a string by reference
        //Sets the private variable point
    void Point(std::string&);

    //getSuit function that accesses private variable suit
    std::string getSuit();

    //getPoint function that accesses private variable point
    std::string getPoint();

    //Constructor that passes the two strings by references
        //Sets the private variables
    card(std::string&, std::string&);

    //Free function that grants access to the private variables suit and point
        //Uses operator overloading to access the node card using c
    friend std::ostream& operator << (std::ostream& ostr, card &c);


//private members of class card.
private:
    //private strings that passes suit and point
    std::string suit, point;

};

#endif
