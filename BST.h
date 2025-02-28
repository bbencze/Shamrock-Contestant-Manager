#include "contestants.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class BSTNode{
    public:
        unique_ptr<Contestant> data;
        unique_ptr<BSTNode> left;
        unique_ptr<BSTNode> right;

        BSTNode(unique_ptr<Contestant> contestant): data(move(contestant)), left(nullptr), right(nullptr) {}
};

class ContestantBST{
    public:
        ContestantBST(): root(nullptr) {}

        void insert(unique_ptr<Contestant> contestant);
        void remove(int number);
        void display() const;
        void removeAll();
    private:
        unique_ptr<BSTNode> root;

        unique_ptr<BSTNode> insertHelper(unique_ptr<BSTNode> node, unique_ptr<Contestant> contestant);
        unique_ptr<BSTNode> removeHelper(unique_ptr<BSTNode> node, int number);
        BSTNode* findMin(BSTNode* node);
        void displayHelper(BSTNode* node) const;
        void removeAllHelper(BSTNode* node);
};