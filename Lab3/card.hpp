#ifndef CARD_H
#define CARD_H
#include <iostream>

#define ACE_HIGH

class Card {
private:
    int rank;   // 1 = Ace ... 13 = King
    int suit;   // 0 Clubs, 1 Diamonds, 2 Hearts, 3 Spades

public:
    Card();                          // Ace of Spades
    Card(int newRank, int newSuit);

    bool isFaceCard() const;         // true for Jack, Queen, King
    bool isValid() const;            // rank 1-13 and suit 0-3, otherwise prints an error and returns false

    friend std::ostream& operator<<(std::ostream& os, const Card& card);  // prints [Rank] of [Suit]
    friend std::istream& operator>>(std::istream& is, Card& card);        // reads [Rank] of [Suit]

    bool operator<(const Card& c) const;    // compares rank first (ACE_HIGH aware), then suit
    bool operator>(const Card& c) const;
    bool operator==(const Card& c) const;   // same rank and same suit
};

#endif // CARD_H