#include<iostream>
#include<sstream>
#include "Player.h"
using std::vector, std::string, std::size_t;

Player::Player(bool isAI) : isAI(isAI), hand(hand) {

}

void Player::addToHand(Card* c){
    // TODO: Add the card c to the player's hand
    hand.push_back(c);
}

size_t Player::getHandSize(){
    // TODO: Implement getter
    return hand.size();
}

std::string Player::getHandString(){
    // TODO: Implement getter
    std::stringstream ss;
    for (size_t i = 0; i < getHandSize(); i++){
        string suit = "";
        if (i == getHandSize() - 1){ // avoid printing comma at the end
            // -> shorthand for dereferencing pointer and then accessing member
            ss << hand[i]->getRank() << " " << hand[i]->getSuit(); 
        }
        else {
            ss << hand[i]->getRank() << " " << hand[i]->getSuit() << ", ";
        }
    }

    return ss.str(); // return string containing stringstream's content in it
}

Card* Player::playCard(vector<string> const& suits, string& currentRank, string& currentSuit){
    // TODO: Choose a card to play and return the chosen card. Update currentRank and currentSuit.
    if (isAI){
        for (size_t i = 0; i < getHandSize(); i++){ // iterate from new to old cards
            if (hand[i]->canBePlayed(currentRank, currentSuit)){

                // store card
                Card* playedCard = hand[i];

                // increment card's timesPlayed
                playedCard->play();

                // update rank (and suit in nested if statement)
                currentRank = playedCard->getRank();

                // ai implementation
                
                // ai will always play first card from its hand that it can legally play
                if (currentRank == "8"){
                    currentSuit = playedCard->getSuit();
                }
                // if played card isn't an 8, update current suit to the suit of the played card
                else {
                    currentSuit = playedCard->getSuit();
                }

                // remove from player's hand
                hand.erase(hand.begin() + i);
                return playedCard;
        
            }
        }
    }
    else{ // human implementation
        std::cout << "Your hand contains: " << getHandString() << std::endl;
        std::cout << "The next card played must be a " << currentRank << " or " << currentSuit << std::endl;
        std::cout << "What card would you like to play? (enter \"draw card\" to draw a card)" << std::endl;

        // enter while loop and break whenever valid input is given
        bool invalidInput = true;
        while(invalidInput){
            string inputRank = "";
            string inputSuit = "";
            std::cin >> inputRank >> inputSuit;

            //-------check if it's a card that's available to use-------
            if (!(inputRank == currentRank && inputSuit == currentSuit)){
                
            }


            //-------check if it's a card that's available to use-------

            // for loop to iterate through hand and check if card matches inputted card
            for (size_t i = 0; i < getHandSize(); i++){
                if (hand[i]->getRank() == inputRank && hand[i]->getSuit() == inputSuit){
                    
                }
            }

            //---------------check if card is an 8----------


        }

        //---------------check if card is an 8----------


    }
    // if no card was played
    return nullptr;


}