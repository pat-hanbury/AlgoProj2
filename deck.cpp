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

    //placement card holder for assigning the previous card value in a new card
    card *previousCard;

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

            //placeholder for card before new card

            previousCard = current;

            //set head to new card for next loop
            current = newCard;

            //assign a previous value to new card
            current->previous = previousCard;
        }
    }
}

/* JOHNS STUFF:FOO

//New deal function that returns top card in the deck by value. 
card deck::deal(){
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
*/

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


void deck::shuffle() {
    /*reorders the nodes of the linked list*/

    std::cout<<"made it to shuffle function" << std::endl;

    //set up randomization capabilities
    srand(time(NULL));

    //number of times to swap cards in deck
    int numberOfSwaps = 100;

    //initialize placeholder variables
    card *node1;
    card *node2;
    card *node1Next;
    card *node1Previous;
    card *node2Next;
    card *node2Previous;

    int randNumber1;
    int randNumber2;

    //do the swaps
    for(int j=0; j < numberOfSwaps; j++) {
        //initialize random numbers

        std::cout << "made it to the for loop of shuffle " << j << std::endl;

        randNumber1 = rand() % 52;
        randNumber2 = rand() % 52;

        //insure random numbers are not the same
        while (randNumber1 == randNumber2) {
            randNumber2 = rand() % 52;
            std::cout<<"while loop 1"<<std::endl;
        }

        //start at head of node
        current = head;

        //find node1
        for (int i = 0; i < randNumber1; i++) {
            current = current->next;
        }

        //set address stored in node1 to address found by current
         //dynamically allocate memory
        node1 = current;

        //start at head of node
        current = head;

        //find node2
        for (int i = 0; i < randNumber2; i++) {
            current = current->next;
        }


        node2 = current;

        node1Next = node1->next;
        node2Next = node2->next;
        node1Previous = node1->previous;
        node2Previous = node2->previous;

        //swap node1 with node2

        //reassign the nodes
        node1->previous = node2Previous;
        node1->next = node2Next;
        node2->next = node1Previous;
        node2->next = node1Next;

        //reassign the nodes surrounding the swapped nodes
        node1Previous->next = node2; //set the next of the original node1's previous to node2
        node1Next->previous = node2; //set the previous of the original node1's next to node2
        node2Previous->next = node1;
        node2Next->previous = node1;
    }

}