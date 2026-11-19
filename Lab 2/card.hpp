#ifndef CARD_H
#define CARD_H
#include <iostream>

#define ACE_HIGH

class Card{
    private:
        int rank;
        int suit;

    public:
        Card(); // Default constructor
        Card(int newRank, int newSuit);

        bool isFaceCard(); // returns true if the card is a face card (Jack, Queen, King)
        bool isValid(); //Returns true if the card is valid (rank between 1 and 13, suit between 1 and 4), otherwise prints an error message and returns false

        friend std::ostream& operator<<(std::ostream& os, Card card); //Output the rank and suit of the card in the format : [Rank] of [Suit]
        friend std::istream& operator>>(std::istream& is, Card& card); //Reads the rank and suit of the cards from the input stream in the format: [Rank] of [Suit]

        bool operator <(Card c); //returns true if cards suit and rank are less than the other card's suit and rank, otherwise returns false
        bool operator >(Card c); //returns true if cards suit and rank are greater than the other card's suit and rank, otherwise returns false

        bool operator ==(Card c); //returns true if cards suit and rank are equal to the other card's suit and rank, otherwise returns false

};





#endif // CARD_H