#include "card.hpp"
#include <iostream>
#include <string>

using namespace std;

Card::Card() : rank(1), suit(3) {} // Default constructor   
Card::Card(int newRank, int newSuit) : rank(newRank), suit(newSuit) {} // Parameterized constructor initializes rank and suit to provided values

bool Card:: isFaceCard(){
    if (rank == 11 || rank == 12 || rank == 13) {
        return true; // Returns true if the card is a face card (Jack, Queen, King)
    }
    return false; // Returns false otherwise
}

bool Card::isValid(){
    if (rank <= 13 && rank >= 1 && suit <4 && suit >= 0){
        return true;

    } else{
        cout << "Error: Invalid card." << endl;
        return false;
    }
}

ostream& operator << (ostream& os, Card card){
    switch(card.rank){
        case 1:
            os << "Ace";
            break;
        case 11:
            os << "Jack";
            break;
        case 12:
            os << "Queen";
            break;
        case 13:
            os << "King";
            break;
        default:
            os << card.rank; // Outputs the rank of the card
    }
    os << " of ";
    switch(card.suit){
        case 0:
            os << "Clubs";
            break;
        case 1:
            os << "Diamonds";
            break;
        case 2:
            os << "Hearts";
            break;
        case 3:
            os << "Spades";
            break;
    }
    return os;

}

istream& operator >> (istream& is, Card& card){
    string rankNames[] = {"", "Ace", "2", "3", "4", "5", "6", "7",
                                            "8", "9", "10", "Jack", "Queen", "King"};
    string suitNames[] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    string r, of, s;
    is >> r >> of >> s;
    int newRank = 0, newSuit = -1;
    for (int i = 1; i <= 13; ++i)
        if (rankNames[i] == r) newRank = i;
    for (int i = 0; i < 4; ++i)
        if (suitNames[i] == s) newSuit = i;

   
    card.rank = newRank;
    card.suit = newSuit;
    return is;
}

bool Card::operator <(Card c){
    int a = rank, b = c.rank;
#ifdef ACE_HIGH
    if (a == 1) a = 14;   // ace ranks above the king
    if (b == 1) b = 14;
#endif
    if (a != b) return a < b;
    return suit < c.suit;
}

bool Card::operator >(Card c){
    int a = rank, b = c.rank;
#ifdef ACE_HIGH
    if (a == 1) a = 14;
    if (b == 1) b = 14;
#endif
    if (a != b) return a > b;
    return suit > c.suit;
}

bool Card:: operator ==(Card c){
    if (rank == c.rank && suit == c.suit){
        return true;
    }else{
        return false;
    }
}