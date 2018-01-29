//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//class main.cpp

#include "deck.h"


int main(void){

	//initalizes the deck
    deck *playersDeck; 
	//dynamically allocates memory for the new deck object
	playersDeck = new deck();	
	
	//print the deck 
    std::cout << *playersDeck;
    //deletes the dynamically allocated memory for the new deck object, including what the deck points to
	delete playersDeck;
    
	return 0;
}
