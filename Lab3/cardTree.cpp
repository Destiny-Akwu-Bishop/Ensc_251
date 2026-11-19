#include "cardTree.hpp"

using namespace std;

// ---------- private helper functions ----------

// Copies a subtree and returns the root of the new copy
TreeNode* CardTree::copySubtree(const TreeNode* node) {
    if (node == nullptr) {
        return nullptr;
    }
    TreeNode* n = new TreeNode;
    n->card = node->card;
    n->left = copySubtree(node->left);
    n->right = copySubtree(node->right);
    return n;
}

// Deletes the children first, then the node itself
void CardTree::destroySubtree(TreeNode* node) {
    if (node == nullptr) {
        return;
    }
    destroySubtree(node->left);
    destroySubtree(node->right);
    delete node;
}

// Returns the root of this subtree after inserting the card
TreeNode* CardTree::insertNode(TreeNode* node, const Card& card) {
    if (node == nullptr) {
        TreeNode* newNode = new TreeNode;
        newNode->card = card;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (card < node->card) {
        node->left = insertNode(node->left, card);
    }
    else if (card > node->card) {
        node->right = insertNode(node->right, card);
    }
    return node;
}

// Returns the root of this subtree after removing the card
TreeNode* CardTree::removeNode(TreeNode* node, const Card& card) {
    if (node == nullptr) {
        return nullptr;
    }
    if (card < node->card) {
        node->left = removeNode(node->left, card);
    }
    else if (card > node->card) {
        node->right = removeNode(node->right, card);
    }
    else {
        if (node->left == nullptr && node->right == nullptr) {   // leaf
            delete node;
            return nullptr;
        }
        else if (node->left == nullptr) {                        // only a right child
            TreeNode* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {                       // only a left child
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        else {                                                   // two children
            TreeNode* succ = node->right;
            while (succ->left != nullptr) {
                succ = succ->left;                               // smallest card in the right subtree
            }
            node->card = succ->card;                             // copy the successor's card up
            node->right = removeNode(node->right, node->card);   // delete the successor's old node
        }
    }
    return node;
}

void CardTree::printInOrderHelper(const TreeNode* node, ostream& outs) const {
    if (node == nullptr) {
        return;
    }
    printInOrderHelper(node->left, outs);
    outs << node->card << endl;
    printInOrderHelper(node->right, outs);
}

void CardTree::printPreOrderHelper(const TreeNode* node, ostream& outs) const {
    if (node == nullptr) {
        return;
    }
    outs << node->card << endl;
    printPreOrderHelper(node->left, outs);
    printPreOrderHelper(node->right, outs);
}

int CardTree::heightHelper(const TreeNode* node) const {
    if (node == nullptr) {
        return 0;
    }
    int l = heightHelper(node->left);
    int r = heightHelper(node->right);
    if (l > r) {
        return 1 + l;
    }
    return 1 + r;
}

// ---------- public functions ----------

CardTree::CardTree() : root(nullptr), numCards(0) {}

CardTree::CardTree(const CardTree& other) : root(nullptr), numCards(other.numCards) {
    root = copySubtree(other.root);
}

CardTree& CardTree::operator=(const CardTree& other) {
    if (this != &other) {                // skip self-assignment
        destroySubtree(root);            // free the old nodes
        root = copySubtree(other.root);  // make a deep copy
        numCards = other.numCards;
    }
    return *this;
}

CardTree::~CardTree() {
    destroySubtree(root);
}

int CardTree::getNumCards() const {
    return numCards;
}

bool CardTree::addCard(const Card& card) {
    if (contains(card)) {
        return false;            // duplicate
    }
    root = insertNode(root, card);
    numCards++;
    return true;
}

bool CardTree::contains(const Card& card) const {
    if (findCard(card) != nullptr) {
        return true;
    }
    return false;
}

// Follows one path down the tree using the BST ordering
const Card* CardTree::findCard(const Card& card) const {
    const TreeNode* cur = root;
    while (cur != nullptr) {
        if (card < cur->card) {
            cur = cur->left;
        }
        else if (card > cur->card) {
            cur = cur->right;
        }
        else {
            return &(cur->card);     // pointer to const Card, so it is read-only
        }
    }
    return nullptr;
}

bool CardTree::removeCard(const Card& card) {
    if (!contains(card)) {
        return false;            // not in the tree
    }
    root = removeNode(root, card);
    numCards--;
    return true;
}

void CardTree::printInOrder(ostream& outs) const {
    printInOrderHelper(root, outs);
}

void CardTree::printPreOrder(ostream& outs) const {
    printPreOrderHelper(root, outs);
}

int CardTree::getHeight() const {
    return heightHelper(root);
}

bool CardTree::isEmpty() const {
    if (numCards == 0) {
        return true;
    }
    return false;
}