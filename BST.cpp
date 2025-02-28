#include "BST.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

void ContestantBST::insert(unique_ptr<Contestant> contestant){
    root = insertHelper(move(root), move(contestant));
}

unique_ptr<BSTNode> ContestantBST::insertHelper(unique_ptr<BSTNode> node, unique_ptr<Contestant> contestant){
    if(node == nullptr){
        return make_unique<BSTNode>(move(contestant));
    }

    if(contestant->get_number() < node->data->get_number()){
        node->left = insertHelper(move(node->left), move(contestant));
    }else{
        node->right = insertHelper(move(node->right), move(contestant));
    }

    return node;
}

void ContestantBST::remove(int number){
    root = removeHelper(move(root), number);
}

unique_ptr<BSTNode> ContestantBST::removeHelper(unique_ptr<BSTNode> node, int number) {
    if (!node) return nullptr;  

    if (number < node->data->get_number()) {
        node->left = removeHelper(move(node->left), number);
    } else if (number > node->data->get_number()) {
        node->right = removeHelper(move(node->right), number);
    } else {
        if (!node->left) {
            return move(node->right); 
        } else if (!node->right) {
            return move(node->left);   
        }

        BSTNode* temp = findMin(node->right.get());
        if (temp == nullptr) {
            return node;
        }

        node->data = move(temp->data);  

        temp->data = nullptr;  

        if (node->right) {
            node->right = removeHelper(move(node->right), node->data->get_number());
        } else {
            cerr << "Error: node->right is nullptr before recursive call!" << endl;
        }
    }

    return node;
}

BSTNode* ContestantBST::findMin(BSTNode* node){
    while (node && node->left){
        node = node->left.get();
    }

    return node;
}

void ContestantBST::display() const{
    displayHelper(root.get());
}

void ContestantBST::displayHelper(BSTNode* node) const {
    if(node != nullptr){
        displayHelper(node->left.get());
        node->data->display();
        displayHelper(node->right.get());
    }
}

void ContestantBST::removeAll(){
    removeAllHelper(root.get());
    root.reset();
}

void ContestantBST::removeAllHelper(BSTNode* node){
    if(node != nullptr){
        removeAllHelper(node->left.get());
        removeAllHelper(node->right.get());
    }
}