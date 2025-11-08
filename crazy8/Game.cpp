#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<cctype>
#include "Game.h"
using std::string, std::vector;

Game::Game(): players({}), suits({}), ranks({}), 
    deck({}), drawPile({}), discardPile({}) {}

void Game::loadDeckFromFile(string filename){
    // TODO: initialize suits, ranks, deck, and drawPile from the given file

    std::ifstream ifs(filename);
    
    if (!(ifs.is_open())){
        throw std::runtime_error("file could not be opened");
    }

    string line;
    getline(ifs,line);
    //--------------populate suits and ranks-------------------
    std::stringstream ss(line);
    string individualSuits;
    while(ss >> individualSuits){
        // check for invalid suit (cannot contain special characters)
        for (char s: individualSuits){
            if (!(std::isalnum(s))){
                throw std::runtime_error("suits are invalid");
            }
        }
        // store if input is okay
        suits.push_back(individualSuits);
    }

    getline(ifs,line);
    ss.clear(); // clear error flags
    ss.str(line); // set ss content to new "line"

    string individualRanks;
    while(ss >> individualRanks){
        for (char c: individualRanks){
            if (!(std::isalnum(c))){
                throw std::runtime_error("ranks are invalid");
            }
        }
        // store if input is okay
        ranks.push_back(individualRanks);
    }

    // start reading lines
    while (getline(ifs, line)){
        std::stringstream c_ss(line);

        string cardRank;
        string cardSuit;
        // used for error handling (if more than 2 inputs per card line)
        string extraInput;

        //--------check for not enough inputs----------
        if (!(c_ss >> cardRank >> cardSuit)){
            throw std::runtime_error("card is invalid: not enough information");
        }

        //---------check for too many inputs-----------
        if (c_ss >> extraInput){
            throw std::runtime_error("card is invalid: too many inputs per card");
        }

        // at this point, line should have 2 inputs (valid card)

        // initialize bool flags to check for correct suit and rank per vectors populated
        bool suitFound = false;
        bool rankFound = false;


        // check if suit is in suits vector
        for (const string& s: suits){
            if (s == cardSuit){
                suitFound = true;
                break;
            }
        }

        // check if rank is in ranks vector
        for (const string& r: ranks){
            if (r == cardRank){
                rankFound = true;
                break;
            }
        }

        if ((!rankFound) || (!suitFound)){
            throw std::runtime_error("rank/suit is not in the list of allowed rank/suits");
        }

        try{
            Card* card = new Card{cardRank, cardSuit};
            // deck is a permanent index of all cards (will not change)
            // first card in file at position 0, etc.
            deck.push_back(card);
        } catch (const std::invalid_argument& e){
            throw std::runtime_error("Card cannot be allocated on heap (constructor threw error)");
        }

    }
    // drawPile keeps track of cards and has variable size
    // last card in file at position 0, etc. (reverse deck order)
    drawPile.assign(deck.rbegin(),deck.rend());

}


void Game::addPlayer(bool isAI){
    // TODO: add a new player to the game
    Player* newPlayer = new Player(isAI);
    players.push_back(newPlayer);

}



void Game::drawCard(Player* p){
    // TODO: Move the top card of the draw pile to Player p's hand
    // If the draw pile is empty, flip the discard pile to create a new one
    if (drawPile.empty()){
        if (discardPile.size() >= 2){
            std::cout << "Draw pile empty, flipping the discard pile." << std::endl;

            // flip rest of discard pile to turn into drawPile
            drawPile.assign(discardPile.rbegin(),discardPile.rend());

            // draw pile contains all discardPile cards except the most recently played
            drawPile.erase(drawPile.begin());

            // keep just most recently discarded (played) card
            discardPile.erase(discardPile.begin(), discardPile.begin() + discardPile.size() -1);
        }
        else { // if discard pile has less than two cards
            throw std::runtime_error("discard pile contains less than two cards, cannot flip.");
        }
    }
    // move top card of draw pile into the player's hand
    p->addToHand(drawPile.back());
    drawPile.pop_back(); // remove card from the draw pile

}



Card* Game::deal(int numCards){
    // TODO: Flip the top card of the draw pile to be the initial discard
    // then deal numCards many cards to each player

    // start discard pile by discarding top (last) card of the draw pile
    discardPile.push_back(drawPile.back());
    drawPile.pop_back();

    // iterate "numCards" amount of times to populate each player's hand
    for (size_t i = 0; i < numCards; i++){
        // deal cards from the top of the deck to player's hands one at a time
        for (size_t j = 0; j < players.size(); j++){
            drawCard(players[j]);
        }
    }

    // return initially discarded card
    return discardPile.back();
}



string Game::mostPlayedSuit(){
    // TODO: Return the suit which has been PLAYED the most times
    // if there is a tie, choose any of the tied suits

    // x number of suits
    // x number of timesPlayed values

    // iterate through suits, compare timesPlayed with next suit and return biggest
    string maxSuit = suits.front(); // set max to first element of suits initially
    int totalSuitPlayed = 0;
    int totals = 0;

    for (size_t j = 0; j < deck.size(); j++){
        if (deck[j]->getSuit() == maxSuit){
            totalSuitPlayed += deck[j]->getTimesPlayed();
        }
    }

    // find 
    for (size_t i = 1; i < suits.size(); i++){

        maxSuit = suits[i];

        for (size_t k = 0; k < deck.size(); k++){
        // get total for that suit
            if (deck[k]->getSuit() == maxSuit){
                totals += deck[k]->getTimesPlayed();
            }
            if (totalSuitPlayed < totals){
                
            }

    }






        totalSuitPlayed = 0;
        

    }

    return maxSuit;

}



int Game::runGame(){
    // TODO: Run the game and return the number of the winning player
}



//Destructor--Deallocates all the dynamic memory we allocated
//You shouldn't touch this
Game::~Game(){
    for (unsigned int i = 0; i < deck.size(); i++){
        delete deck.at(i);
    }
    for (unsigned int i = 0; i < players.size(); i++) {
        delete players.at(i);
    }
}