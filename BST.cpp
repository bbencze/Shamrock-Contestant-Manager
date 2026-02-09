//Bee Bencze
//bencze@pdx.edu

#include "BST.h"
#include <iostream>
#include <memory>
#include <string>

using namespace std;

//insert a contestant into the BST
void ContestantBST::insert(unique_ptr<Contestant> contestant){
    root = insertHelper(move(root), move(contestant));
}


//recursive insert helper
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


//remove a rider from the bst
void ContestantBST::remove(int number){
    root = removeHelper(move(root), number);
}


//recursive remove helper
unique_ptr<BSTNode> ContestantBST::removeHelper(unique_ptr<BSTNode> node, int number) {
    if (!node){
        cout<<"Unable to find this rider"<<endl;
        return nullptr;
    }   

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

//find min function, returns left child node
BSTNode* ContestantBST::findMin(BSTNode* node){
    while (node && node->left){
        node = node->left.get();
    }

    return node;
}

//display function
void ContestantBST::display() const{
    displayHelper(root.get());
}

//recusrive display function helper
void ContestantBST::displayHelper(BSTNode* node) const {
    if(node != nullptr){
        displayHelper(node->left.get());
        node->data->display();
        displayHelper(node->right.get());
    }
}

//removes all nodes
void ContestantBST::removeAll(){
    removeAllHelper(root.get());
    root.reset();
}

//removal all helper
void ContestantBST::removeAllHelper(BSTNode* node){
    if(node != nullptr){
        removeAllHelper(node->left.get());
        removeAllHelper(node->right.get());
    }
}

//search function
Contestant* ContestantBST::search(int number){
    return searchHelper(root.get(), number);
}

//recursive search function helper
Contestant* ContestantBST::searchHelper(BSTNode* node, int number){
    if(node == nullptr){
        return nullptr;
    }

    if(node->data->get_number() == number){
        return node->data.get();
    }

    if (number < node->data->get_number()) {
        return searchHelper(node->left.get(), number);  //search left subtree
    } else {
        return searchHelper(node->right.get(), number);  //search right subtree
    }
}

//searches and calls checkPro if GPracer is found
void ContestantBST::searchAndCheckPro(int number){
    Contestant* rider = searchHelper(root.get(), number);

    if(rider == nullptr){
        cout<<"Rider "<<number<<" not found"<<endl;
        return;
    }

    if(auto gpRacer = dynamic_cast<GPRacer*>(rider)){
        gpRacer->checkProStatus();
    }else{
        cout<<"Rider #"<<number<<" is not a GP Racer\n\n";
    }
}