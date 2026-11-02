#include <iostream>
#include "card.hpp"
#include "deck.hpp"

using namespace std;

int main() {
    // 1. Create an empty deck
    Deck* original = new Deck();

    // 2. Add the 10 cards (rank, suit): 0 Clubs, 1 Diamonds, 2 Hearts, 3 Spades
    original->addCard(Card(13, 2));   // King of Hearts
    original->addCard(Card(2, 0));    // 2 of Clubs
    original->addCard(Card(4, 3));    // 4 of Spades
    original->addCard(Card(5, 1));    // 5 of Diamonds
    original->addCard(Card(12, 1));   // Queen of Diamonds
    original->addCard(Card(7, 3));    // 7 of Spades
    original->addCard(Card(10, 0));   // 10 of Clubs
    original->addCard(Card(3, 2));    // 3 of Hearts
    original->addCard(Card(4, 1));    // 4 of Diamonds
    original->addCard(Card(1, 3));    // Ace of Spades

    // 3. Display the complete deck
    cout << "Original deck (" << original->getNumCards() << " cards):" << endl;
    original->printDeck();

    // 4. Create a copy of the deck
    Deck* second = new Deck(*original);

    // 5. Remove and display the top card of the original deck
    Card top = original->drawTopCard();
    cout << "\nTop card removed from original: " << top << endl;

    // 6. Check whether either deck is empty
    cout << "\nOriginal deck empty? " << (original->isEmpty() ? "Yes" : "No") << endl;
    cout << "Second deck empty? " << (second->isEmpty() ? "Yes" : "No") << endl;

    // 7. Display both complete decks
    cout << "\nOriginal deck (" << original->getNumCards() << " cards):" << endl;
    original->printDeck();
    cout << "\nSecond deck (" << second->getNumCards() << " cards):" << endl;
    second->printDeck();

    // 8. Find and display the largest card in the original deck
    cout << "\nLargest card in original deck: " << original->findHighCard() << endl;

    // 9. Ask the user to input a card
    Card userCard;
    cout << "\nEnter a card (format: Rank of Suit, e.g. Queen of Hearts): ";
    cin >> userCard;

    // 10. Add that card to the second deck
    if (userCard.isValid()) {
        second->addCard(userCard);
    } else {
        cout << "Invalid card, not added." << endl;
    }

    // 11. Display the second deck
    cout << "\nSecond deck (" << second->getNumCards() << " cards):" << endl;
    second->printDeck();

    // 12. Destroy both decks
    delete original;
    delete second;
    cout << "\nBoth decks destroyed." << endl;

    return 0;
}