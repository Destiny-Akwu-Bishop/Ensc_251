// Goal: to make a simple playing card management system 
//ENSC 251 Lab 1
//Destiny Akwu-bishop
//Student Number: 301 648 405
//Section 1: Card Class
#include <iostream>
using namespace std;

class Card{
    private:
        int rank;
        int suit;
    
    
        //Section 1.1: Implemment constructor functions, get functions, and set functions
    public:
        Card();
        Card(int r, int s);

        int getRank();
        int getSuit();
        void setRank(int r);
        void setSuit(int s);
        
        //Implement a member function isFaceCard
        bool isFaceCard();
        
        //Implement a member function isValid
        bool isValid();
        
        //Implement an output member function
        void output(ostream &out);
        
        //Implement helper member functions
        void printSuitName();
        void printRankName();

        //friend function equal
        friend bool equal(Card a, Card b);

        

};

Card:: Card() : rank(1), suit(0) {}
Card:: Card(int r, int s): rank(r), suit(s) {}

int Card:: getRank() {return rank;}
int Card:: getSuit() {return suit;}
void Card:: setRank(int r) {rank = r;}
void Card:: setSuit(int s) {suit = s;}


bool Card::isFaceCard(){
    if (rank == 11 || rank == 12|| rank == 13){
        return true;
    }else{
        return false;
    }
}
bool Card::isValid(){
    if(rank>= 1 && rank <= 13 && suit >= 0 && suit <= 3){
        return true;
    }else{
        cout << "Error message: Invalid card" << endl;
        return false;
    }
}
void Card::output(ostream &out){
    out << "Rank: " << rank << ", Suit: " << suit << endl <<  "Face Card: " << isFaceCard() << endl;
}

void Card::printSuitName(){
    switch(suit){
        case 0: 
        cout << "Clubs"<< endl;
        break;
        case 1: 
        cout << "Diamonds"<< endl;
        break;
        case 2: 
        cout << "Hearts"<< endl;
        break;
        case 3: 
        cout << "Spades"<< endl;
        break;
        default:
        cout << "Invalid Suit"<< endl;
    }
}

void Card::printRankName(){
    switch(rank){
        case 1:
        cout << "Ace"<< endl;
        break;
        case 11: 
        cout << "Jack"<< endl;
        break;
        case 12: 
        cout << "Queen"<< endl;
        break;
        case 13: 
        cout << "King"<< endl;
        break;
        default:
        if(rank>= 2&& rank <= 10){
            cout << rank << endl;
        }else{
            cout << "Invalid Rank"<< endl;
    }
    }
}

bool equal(Card a, Card b){
    return a.suit == b.suit && a.rank == b.rank;
}
    


class Deck{
    private:
        Card cards[52];
        int numCards;

    public:
        //Constructor, Getters, and Setters
        Deck(bool full);
        //Getters
        int getNumCards();
        Card getCards(int index);
        //Setters
        void setNumCards(bool full);
        //Implement drawTopCard(): remove and return the top card from the deck
        Card drawTopCard();
        //Implement addCard()
        bool addCard(Card c);
        //Implement printDeck()
        void printDeck();
        //Implement isEmpty()
        bool isEmpty();


            

};
int Deck:: getNumCards(){
    return numCards;
}
Card Deck:: getCards(int index){
    return cards[index];

}
void Deck:: setNumCards(bool full){
    if(full){
        numCards = 52;
    }else{
        numCards = 0;
    }
}
bool Deck:: addCard(Card c){
    if (numCards < 52){

        for (int i = 0; i < numCards; i++){
            if (equal(cards[i], c)){
                cout << "Error message: Card already exists in the deck" << endl;
                return false;
            }
        }
        cards[numCards] = c;
        numCards++;
        return true;
    }
    return false; 

}

Card Deck:: drawTopCard(){
    if (numCards <= 52 && numCards > 0){
        numCards--;
        return cards[numCards];

    }else if (numCards==0){
        cout << "Error message: Deck is empty" << endl;
        return Card();
    }
}
void Deck:: printDeck(){
    for (int i = 0; i < numCards; i++){
        cout << "Card " << i+1 << ": ";
        cards[i].output(cout);
    }
}
bool Deck:: isEmpty(){
    if (numCards == 0){
        return true;
    }else{
        return false;
    }
}
Deck:: Deck(bool full){
    if(full){
        numCards = 52;
        int index = 0;
        for(int s = 0; s < 4; s++){
            for(int r = 1; r <= 13; r++){
                cards[index] = Card(r, s);
                index++;
            }
        }
    }else{
        numCards = 0;
    }
}
//Testing
int main(){
    Card c1(11,0), c3(11,0);
    cout << c1.isFaceCard() << endl;
    cout << c1.isValid()<< endl;
    c1.output(cout);
    c1.printSuitName();
    c1.printRankName();

    Deck d1(false);
    d1.printDeck();
    d1.drawTopCard();
    d1.addCard(c1);
    d1.addCard(c3);
    d1.printDeck();
    d1.isEmpty();

    cout << equal(c1, c3) << endl;





    return 0;
}