#include<cctype>
#include<stdexcept>
#include "Card.h"
#include <string>
using std::string;

Card::Card(string rank, string suit) : rank(rank), suit(suit), timesPlayed(0) { // initialize EVERYTHING
    // TODO: implement constructor checks

    // throw invalid_argument if rank or suit are empty OR contain non-alphanumeric chars
    if (rank.empty() || suit.empty() ){
        throw std::invalid_argument("Invalid rank/card");
    }

    // for loop to check for non-alphanumeric chars
    for (char s : rank){
        if (!std::isalnum(s)){
            throw std::invalid_argument("Invalid rank (contains nonalnum char)");
        }
    }
    for (char s : suit){
        if (!std::isalnum(s)){
            throw std::invalid_argument("Invalid card (contains nonalnum char)");
        }
    }
}

string Card::getRank(){
    // TODO: implement getter
    return rank;
}

string Card::getSuit(){
    // TODO: implement getter
    return suit;
}

int Card::getTimesPlayed(){
    // TODO: implement getter
    return timesPlayed;
}

bool Card::canBePlayed(string currentRank, string currentSuit){
    // TODO: return whether or not this card can legally be played given that the previous card
    //  played had rank currentRank and suit currentSuit

    if (getRank() == "8"){ // 8s can always be played
        return true;
    }

    if (getRank() == currentRank){ // if previous rank matches current rank
        return true;
    }

    if (getSuit() == currentSuit){ // iff previous suit matches current suit
        return true;
    }

    return false; // if above conditions all fail (invalid card)
}

//You don't need to modify this
void Card::play(){
    timesPlayed++;
}