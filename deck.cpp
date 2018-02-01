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

            //placeholder for card before new card
            card *previousCard = new card;
            previousCard = current;

            //set head to new card for next loop
            current = newCard;

            //assign a previous value to new card
            current->previous = previousCard;

            //delete dynamically allocated memory
            delete previousCard;
        }
    }
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

void deck::shuffle() {
    /*reorders the nodes of the linked list */

    //set up randomization capabilities
    srand(time(NULL));

    //number of times to swap cards in deck
    int numberOfSwaps = 100;

    //do the swaps
    for(int j=0; j < numberOfSwaps; j++) {
        //initialize random numbers
        int randNumber1 = rand() % 52;
        int randNumber2 = rand() % 52;

        //insure random numbers are not the same
        while (randNumber1 == randNumber2) {
            int randNumber2 = rand() % 52;
        }

        //start at head of node
        current = head;

        //find node1
        for (int i = 0; i < randNumber1; i++) {
            current = current->next;
        }

        //set address stored in node1 to address found by current
        card *node1 = new card; //dynamically allocate memory
        node1 = current;

        //start at head of node
        current = head;

        //find node2
        for (int i = 0; i < randNumber2; i++) {
            current = current->next;
        }

        card *node2 = new card;
        node2 = current;

        //dynamically allocate memory first for the swapping of ndoes
        card *node1Next = new card;
        card *node1Previous = new card;
        card *node2Next = new card;
        card *node2Previous = new card;

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


        //delete dynamically allocated memory
        delete node1;
        delete node2;
        delete node1Next;
        delete node2Next;
        delete node1Previous;
        delete node2Previous;
    }

}