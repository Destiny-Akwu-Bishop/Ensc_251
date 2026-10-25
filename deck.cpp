#include <iostream>
#include <string>
#include "card.hpp"
#include "deck.hpp"

using namespace std;

Deck::Deck() : numCards(0), head(nullptr) {} // Default constructor
Deck:: Deck(const Deck& deck): numCards(deck.numCards), head(nullptr) {
    Node* last = nullptr;
}
Deck:: ~Deck(){

}//Destructor



Card Deck:: drawTopCard(){


}//implementing drawTopCard function, remove the first node and returns the top card from the deck, deck size should decrease by reducing numCards, assume deck is not empty

bool Deck:: addCard(Card c){
    

}//implementing addCard function, add a card to the beginnning of the deck, return true if successful

void Deck:: printDeck(){
    for ()

}//implementing printDeck function, prints all cards in the deck

bool Deck:: isEmpty(){
    if (numCards == 0){
        return true;
    }
    else{
        return false;
    }

}//implementing isEmpty function, return true when numCards is 0

Card Deck:: findHighCard() const{

}//implementing findHighCard function, find the highest card in the deck, return without modifying
