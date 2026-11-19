#ifndef CARDTREE_H
#define CARDTREE_H
#include <iostream>
#include "card.hpp"

struct TreeNode {
    Card card;
    TreeNode* left;
    TreeNode* right;
};

class CardTree {
private:
    TreeNode* root;   // nullptr when the tree is empty
    int numCards;

    // Recursive private helper functions
    TreeNode* copySubtree(const TreeNode* node);
    void destroySubtree(TreeNode* node);
    TreeNode* insertNode(TreeNode* node, const Card& card);
    TreeNode* removeNode(TreeNode* node, const Card& card);
    void printInOrderHelper(const TreeNode* node, std::ostream& outs) const;
    void printPreOrderHelper(const TreeNode* node, std::ostream& outs) const;
    int heightHelper(const TreeNode* node) const;

public:
    CardTree();                                    // creates an empty tree
    CardTree(const CardTree& other);               // deep copy
    CardTree& operator=(const CardTree& other);    // deep copy, safe for self-assignment
    ~CardTree();                                   // frees every node

    int getNumCards() const;
    bool addCard(const Card& card);                // false if the card is already in the tree
    bool contains(const Card& card) const;
    const Card* findCard(const Card& card) const;  // read-only pointer, or nullptr if not found
    bool removeCard(const Card& card);             // false if the card is not in the tree
    void printInOrder(std::ostream& outs) const;
    void printPreOrder(std::ostream& outs) const;
    int getHeight() const;                         // empty tree = 0, root only = 1
    bool isEmpty() const;
};

#endif // CARDTREE_H