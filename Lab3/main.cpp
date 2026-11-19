#include <iostream>
#include "card.hpp"
#include "cardTree.hpp"

using namespace std;

int main() {
    // 1-2. Create an empty tree and display its status
    CardTree tree1;
    cout << "tree1 empty? " << (tree1.isEmpty() ? "Yes" : "No")
         << ", cards: " << tree1.getNumCards() << endl;

    // 3. Add the 12 cards (rank, suit): 0 Clubs, 1 Diamonds, 2 Hearts, 3 Spades
    tree1.addCard(Card(7, 2));    // 7 of Hearts
    tree1.addCard(Card(4, 0));    // 4 of Clubs
    tree1.addCard(Card(12, 1));   // Queen of Diamonds
    tree1.addCard(Card(6, 3));    // 6 of Spades
    tree1.addCard(Card(6, 1));    // 6 of Diamonds
    tree1.addCard(Card(10, 0));   // 10 of Clubs
    tree1.addCard(Card(13, 3));   // King of Spades
    tree1.addCard(Card(5, 2));    // 5 of Hearts
    tree1.addCard(Card(9, 1));    // 9 of Diamonds
    tree1.addCard(Card(11, 0));   // Jack of Clubs
    tree1.addCard(Card(3, 1));    // 3 of Diamonds
    tree1.addCard(Card(8, 2));    // 8 of Hearts

    // 4. Try to add 7 of Hearts a second time
    cout << "\nAdding 7 of Hearts again: "
         << (tree1.addCard(Card(7, 2)) ? "successful" : "failed (duplicate)") << endl;

    // 5. Number of cards
    cout << "Cards in tree1: " << tree1.getNumCards() << endl;

    // 6-7. Traversals
    cout << "\ntree1 in-order:" << endl;
    tree1.printInOrder(cout);
    cout << "\ntree1 pre-order:" << endl;
    tree1.printPreOrder(cout);

    // 8. Height
    cout << "\nHeight of tree1: " << tree1.getHeight() << endl;

    // 9-10. contains()
    cout << "\nContains Queen of Diamonds? "
         << (tree1.contains(Card(12, 1)) ? "Yes" : "No") << endl;
    cout << "Contains 8 of Clubs? "
         << (tree1.contains(Card(8, 0)) ? "Yes" : "No") << endl;

    // 11. findCard()
    const Card* found = tree1.findCard(Card(11, 0));
    if (found != nullptr) {
        cout << "findCard found: " << *found << endl;
    }
    else {
        cout << "Jack of Clubs not found" << endl;
    }

    // 12. Copy constructor
    CardTree tree2(tree1);

    // 13. Assignment operator
    CardTree tree3;
    tree3 = tree1;

    // 14. Remove a leaf
    cout << "\nRemoving 5 of Hearts (leaf): "
         << (tree1.removeCard(Card(5, 2)) ? "successful" : "failed") << endl;
    tree1.printInOrder(cout);

    // 15. Remove a node with one child (6 of Spades, since 2 of Spades is not in the tree)
    cout << "\nRemoving 6 of Spades (one child): "
         << (tree1.removeCard(Card(6, 3)) ? "successful" : "failed") << endl;
    tree1.printInOrder(cout);

    // 16. Remove a node with two children
    cout << "\nRemoving 10 of Clubs (two children): "
         << (tree1.removeCard(Card(10, 0)) ? "successful" : "failed") << endl;
    tree1.printInOrder(cout);

    // 17. Remove a card that is not in the tree
    cout << "\nRemoving 8 of Clubs: "
         << (tree1.removeCard(Card(8, 0)) ? "successful" : "failed (not found)") << endl;

    // 18. Display all three trees
    cout << "\ntree1 in-order:" << endl;
    tree1.printInOrder(cout);
    cout << "\ntree2 in-order:" << endl;
    tree2.printInOrder(cout);
    cout << "\ntree3 in-order:" << endl;
    tree3.printInOrder(cout);

    // 19. Number of cards and height of each tree
    cout << "\ntree1: " << tree1.getNumCards() << " cards, height " << tree1.getHeight() << endl;
    cout << "tree2: " << tree2.getNumCards() << " cards, height " << tree2.getHeight() << endl;
    cout << "tree3: " << tree3.getNumCards() << " cards, height " << tree3.getHeight() << endl;

    return 0;
}