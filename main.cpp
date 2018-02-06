//John Kang and Patrick Hanbury
//Fundamental of Algorithms
//Project2a
//class main.cpp

#include "deck.h"

void playFlip();

int main(void){

	playFlip();
    
	return 0;
}

void playFlip(){
    //create deck
    deck playersDeck;

    //shuffle deck three times
    playersDeck.shuffle();
    playersDeck.shuffle();
    playersDeck.shuffle();

    //initialize score to zero
    double playersPoints = 0;
    std::string continueGame = "1";

    //placeholder variables
    card dealtCard;
    std::string cardPoint;
    std::string cardSuit;

    while(continueGame == "1"){
        //deal card
        dealtCard = playersDeck.deal();
        std::cout << "Your card is a " << dealtCard.getPoint() << " of " << dealtCard.getSuit() << std::endl;

        //put card at bottom of deck
        //playersDeck.replace(dealtCard);

        cardSuit = dealtCard.getSuit();
        cardPoint = dealtCard.getPoint();

        //increase or decrease points based on dealt card
        if(cardPoint == "Ace"){
            playersPoints += 10.0;
        }

        if(cardPoint == "King" || cardPoint == "Queen" || cardPoint == "Jack"){
            playersPoints += 5.0;
        }

        if(cardPoint == "7"){
            playersPoints = playersPoints/2.0;
        }

        if(cardPoint == "2" || cardPoint == "3" || cardPoint == "4" || cardPoint == "5" || cardPoint == "6"){
            playersPoints = 0;
        }

        if (cardSuit == "Hearts"){
            playersPoints+=1;
        }

        std::cout<< "You now have " << playersPoints << " points. Would you like to continue? Input 1 if so, or 0 if not" << std::endl;
        std::cin >> continueGame;

               //check that the input is valid
        while(continueGame != "1" && continueGame != "0"){
            std::cout << "Invalid input, try again" << std::endl;
            std::cin>>continueGame;
        }



    }

    //output final score
    std::cout << "Congratulations. Your final score was " << playersPoints << " points!" << std::endl;


}
