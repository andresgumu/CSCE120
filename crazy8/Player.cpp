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
                currentSuit = playedCard->getSuit();

                // remove from player's hand
                hand.erase(hand.begin() + i);

                return playedCard;
            }
        }
    }
    else{ // human implementation

        // tell person current rank and suit and prompt to choose a card to play
        std::cout << "Your hand contains: " << getHandString() << std::endl;
        std::cout << "The next card played must be a " << currentRank << " or " << currentSuit << std::endl;
        std::cout << "What would you like to play? (enter \"draw card\" to draw a card)" << std::endl;

        // enter while loop and break whenever valid input is given
        while(true){
            string inputRank = "";
            string inputSuit = "";

            std::cin >> inputRank;

            //------------handle "draw card"-----------------
            if (inputRank == "draw"){

                // check if next word is card
                std::string nextWord;
                std::cin >> nextWord;
                if (nextWord == "card"){
                    return nullptr;
                }
            }

            // read suit if player chooses not to draw 
            std::cin >> inputSuit;
            Card* playedCard = nullptr;
            size_t playedCardIndex = -1;

            //---for loop to iterate through hand and check if card matches inputted card---
            for (size_t i = 0; i < getHandSize(); i++){
                if (hand[i]->getRank() == inputRank && hand[i]->getSuit() == inputSuit){
                    playedCard = hand[i];
                    playedCardIndex = i;
                    break;
                }
            }
            if (playedCard == nullptr){
                std::cout << "That's not a card you have. Try again." << std::endl;
                continue;
            }

            //-------check if it's a card that's available to use-------
            if (!playedCard->canBePlayed(currentRank, currentSuit)){
                std::cout << "You can't play that card. Try again." << std::endl;
                continue;
            }
            
            //-------card is valid, handle 8 logic -------------

            // update current rank
            currentRank = playedCard->getRank();

            //check if card is an 8
            if (inputRank == "8"){
                std::cout << "What suit would you like to declare?" << std::endl;
                
                bool invalidSuit = true;
                // check if suit chosen is valid
                while (invalidSuit){
                    string suitChosen = "";
                    std::cin >> suitChosen;

                    for (size_t i = 0; i < suits.size(); i++){
                        if (suitChosen == suits[i]){
                            currentSuit = suitChosen;
                            invalidSuit = false;
                            break;
                        }
                    }
                    
                    if (invalidSuit){
                        std::cout << "That's not a suit in this deck. Try again." << std::endl;
                    }

                }
            }
            else { // handle non-8 logic
                currentSuit = playedCard->getSuit();
            }

            // update hand and return played card
            playedCard->play();
            hand.erase(hand.begin() + playedCardIndex);

            return playedCard;
        }
    }

    // if no card was played
    return nullptr;
}