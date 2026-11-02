#include <iostream>
#include <string>
#include "card.hpp"
#include "deck.hpp"

using namespace std;

// Default constructor: creates an empty deck
Deck::Deck() : numCards(0), head(nullptr) {}

// Copy constructor: deep copy, keeps the same card order
Deck::Deck(const Deck& deck) : numCards(deck.numCards), head(nullptr) {
    Node* last = nullptr;
    for (Node* cur = deck.head; cur != nullptr; cur = cur->next) {
        Node* n = new Node{cur->card, nullptr};   // brand new node for the copy
        if (head == nullptr) {
            head = n;                             // first node of the copy
        } else {
            last->next = n;                       // attach after the previous one
        }
        last = n;
    }
}

// Destructor: frees every node
Deck::~Deck() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;                        // move forward before deleting
        delete temp;
    }
}

// Getter for the number of cards
int Deck::getNumCards() {
    return numCards;
}

// Removes the first node and returns its card (assumes deck is not empty)
Card Deck::drawTopCard() {
    Node* temp = head;
    Card top = temp->card;
    head = head->next;
    delete temp;
    numCards--;
    return top;
}

// Adds a card to the beginning of the deck
bool Deck::addCard(Card c) {
    Node* n = new Node{c, head};
    if (n == nullptr) {
        return false;
    }
    head = n;
    numCards++;
    return true;
}

// Prints all cards, one per line, top card first
void Deck::printDeck() {
    if (head == nullptr) {
        cout << "(deck is empty)" << endl;
        return;
    }
    int position = 1;
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << position << ". " << cur->card << endl;
        position++;
    }
}

// True when numCards is 0
bool Deck::isEmpty() {
    if (numCards == 0) {
        return true;
    }
    else {
        return false;
    }
}

// Finds the highest card without modifying the deck (assumes not empty)
Card Deck::findHighCard() const {
    if (head == nullptr) {
        return Card();                            // safety fallback
    }
    Card high = head->card;
    for (Node* cur = head->next; cur != nullptr; cur = cur->next) {
        if (cur->card > high) {
            high = cur->card;
        }
    }
    return high;
}