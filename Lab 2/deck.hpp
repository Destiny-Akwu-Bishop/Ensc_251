#ifndef DECK_H
#define DECK_H
#include "card.hpp"
#include <iostream>

struct Node{
    Card card;
    Node* next;
};
class Deck{
    private:
        int numCards;
        Node* head;

    public:
    Deck(); // Default constructor
    Deck(const Deck& deck); // Copy constructor
    ~Deck();//Destructor
    int getNumCards(); // Getter for numCards

    Card drawTopCard(); // remove and return the top card from the deck, deck size should decrease by reducing numCards, assume deck is not empty
    bool addCard(Card c); // add a card to the beginnning of the deck, return true if successful

    bool isEmpty(); // return true when numCards is 0
    Card findHighCard() const; // find the highest card in the deck, return without modifying
    void printDeck(); // prints all cards in the deck



};


#endif // DECK_H