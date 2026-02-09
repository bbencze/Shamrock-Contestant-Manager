//Bee Bencze
//bencze@pdx.edu

#include "contestants.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

//class for binary tree node
class BSTNode{
    public:
        unique_ptr<Contestant> data;
        unique_ptr<BSTNode> left;
        unique_ptr<BSTNode> right;

        BSTNode(unique_ptr<Contestant> contestant): data(move(contestant)), left(nullptr), right(nullptr) {} //constructor
};

//class for binary search tree data structure
class ContestantBST{
    public:
        ContestantBST(): root(nullptr) {} //constructor for binary search tree

        void insert(unique_ptr<Contestant> contestant); //inserts a contestant into the search tree
        void remove(int number); //removes the rider by their number, takes in a number from user
        void display() const; //displays all riders stored in the tree
        void removeAll(); //removes all riders stored in the tree
        Contestant* search(int number); //searches for a contestant, used in many functions
        void searchAndCheckPro(int number); //searches and checks if a rider is pro or not

    private:
        //root node
        unique_ptr<BSTNode> root;

        unique_ptr<BSTNode> insertHelper(unique_ptr<BSTNode> node, unique_ptr<Contestant> contestant); //recursive insert helper
        unique_ptr<BSTNode> removeHelper(unique_ptr<BSTNode> node, int number); //recursive remove helper
        Contestant* searchHelper(BSTNode* node, int number); //recursive search helper
        BSTNode* findMin(BSTNode* node); //finds min
        void displayHelper(BSTNode* node) const; //recursive display helper
        void removeAllHelper(BSTNode* node); //recursive remove all helper
};