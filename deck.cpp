//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//class deck.cpp

//deck file included
#include "deck.h"

//Deck constructor
deck::deck(){
    //Initializes the variable to null
    head = NULL;

    //Initializes the arrays of suits
    std::string suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

    //Initializes the arrays of numbers/values for the suits
    std::string number[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

    //For loop to iterate between the suits
    for (int i=0 ; i<4; i++){

        //for loop to iterate between between the card values
        for (int k=0; k<13; k++){
            //check if there is enough heap memory for a new card
            if (new card(suits[i], number[k]) == NULL)
            {
                throw "Not enough heap space to create a new card.";
            }

            //create a new card

            card *newCard = new card(suits[i], number[k]);

            //check if new card is the first card
            //if so, set the head to the first card
            if (i == 0 && k == 0){
                head = newCard;
            }

            //check if new card is not first card
            //if so, set the next of the current card to the address of the new card
            if (i != 0 || k != 0) {
                current->next = newCard;
            }

            //set head to new card for next loop
            current = newCard;

        }
    }
}



//New deal function that returns top card in the deck by value. 
card::deck(){
	//Assigns the head node to the top card
	card top = head->nodeValue; 
	//Assigns the head node to the head of the next node
	head = head->next;
	//Returns the assigned top card that was assigned earlier
	return top;
}


//New replace function that places a card at the bottom of the deck. 
void deck::replace(const card& bottom){

	//New dynamically allocated node, with the variable bottom that is passed. 
	node<card> *bottomCard = new node<card> (bottom);
	//Statically allocated node that starts at head, and moves down the list
	node<card> *prev.bottomCard = head;
	
	//If bottomCard is not pointing to NULL, then the loop will iterate
	while (prev.bottomCard->next){
		
		//Moves the next card until it reaches the end of the deck 
		prev.bottomCard = prev.bottomCard->next;
	}
	//Moves the pointer from NULL to the last card to the bottom of the deck, back to bottomCard
	prev.bottomCard->next = bottomCard;		
}


//Free function that grants access to print the deck
std::ostream& operator <<(std::ostream&, deck &d){
    if (d.head == NULL){
        throw "deck is empty";
    }

    //set the current card to the head
    d.current = d.head;

    int cardCount = 1; //for outputting card number in loop
    while(d.current != NULL){
        //output card number, count point and card suit
        std::cout << "Card " << cardCount << ": " << d.current->getPoint() << " of " << d.current->getSuit() << std::endl;
        //change to next card node
        d.current = d.current->next;
        cardCount++;
    }

}
