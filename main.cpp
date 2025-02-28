#include "BST.h"
#include <iostream>

using namespace std;

int main(){
    auto rider1 = make_unique<Contestant>("Mike Bencze", 729);
    auto rider2 = make_unique<Kid>("Eli Tomac", 1, 10, "John");
    auto rider3 = make_unique<Vintage>("Malcolm Smith", 2, 1971);
    auto rider4 = make_unique<GPRacer>("Ricky Carmichael", 4, true);

    ContestantBST bst;

    bst.insert(move(rider1));
    bst.insert(move(rider2));
    bst.insert(move(rider3));
    bst.insert(move(rider4));

    cout<<"All contestants sorted by number\n";
    bst.display();

    cout<<"\nRemoving Rider #1 (Eli Tomac)\n";
    bst.remove(1);

    cout<<"Remaining Contestants: \n";
    bst.display();

    cout<<"Removing all contestants\n";
    bst.removeAll();


    return 0;
}