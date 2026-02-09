//Bee Bencze
//bencze@pdx.edu

#include "BST.h"
#include <iostream>
#include <vector>

using namespace std;


//get a number selection
int getUserSelection(int low, int high){
    int choice;
    while(true){
        string input;
        getline(cin, input); //gets the user input

        try{
            choice = stoi(input); //attempt to convert input to an integer

            if(choice >= low && choice <= high){ //iof successful and number is in the range, return number
                return choice;
            }else{ //if number is out of range, display error message
                cout<< "Error: Please enter a number "<<low<<"-"<<high<<endl;
            }
        }catch (const invalid_argument& e){ //error message if input is not an int
            cout<<"Error: Invalid Input, please enter a valid number"<<endl;
        }
    }
}


//gets rider name, takes in a string and returns it after changing it based on user input
string getRiderName(string name){
    cout<<"Please Enter the Rider name"<<endl;
    getline(cin, name);

    return name;
}

//get the parent name, takes in a string and returns it after changing it based on user input
string getParentName(string name){
    cout<<"Please Enter the Parent's name"<<endl;
    getline(cin, name);

    return name;
}


int main(){

    //create the BST
    ContestantBST bst;

    cout<<"Welcome to the Shamrock Contestant Tracker!"<<endl; //welcome message
    int choice; 


    //loop for displaying menu while user has not entered 9 to quit
    while(choice != 9){
        //prompt user and gets a int from the user
        cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease select an action from the menu below:\n1)Display all\n2)Manual Registration\n3)Remove a Contestant\n4)Start\n5)Stop\n6)Auto-populate database\n7)Remove all Contestants\n8)Check Pro Status\n9)Quit Program\n=-=-=-=-=-=-=-=-=-=\n"<<endl;
        choice = getUserSelection(1, 9);

        //display all riders in the bst
        if(choice == 1){
            cout<<"\n=-=-=-=-=-=-=-=-=-=\nDisplaying all riders: \n=-=-=-=-=-=-=-=-=-=\n\n";
            bst.display();

        //manually create a new rider
        }else if(choice == 2){
            cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease select a type of Contestant: \n1)Basic Contenstant(No Class)\n2)Kid's Class Contestant\n3)Vintage rider\n4)GP Racer\n"<<endl;
            int classChoice = getUserSelection(1, 4); //user selects a rider class type
            if(classChoice == 1){ //contestant class
                //get the name for new rider
                string new_rider_name;
                new_rider_name = getRiderName(new_rider_name);

                //get the number for the rider
                int new_rider_number;
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter the rider number: "<<endl;
                new_rider_number = getUserSelection(0, 999);

                //create a new contestant object and insert it into the bst
                auto new_rider = make_unique<Contestant>(new_rider_name, new_rider_number);
                bst.insert(move(new_rider));


            }else if(classChoice == 2){ //Kid class
                //get the name for new rider
                string new_rider_name;
                new_rider_name = getRiderName(new_rider_name);

                //get the number for the rider
                int new_rider_number;
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter the rider number: "<<endl;
                new_rider_number = getUserSelection(0, 999);

                //get the age for the rider
                int new_rider_age;
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter the rider age (8-14): "<<endl;
                new_rider_age = getUserSelection(8, 14);

                //get the parents name
                string new_rider_parent_name;
                new_rider_parent_name = getParentName(new_rider_parent_name);

                //create and insert a Kid object
                auto new_rider = make_unique<Kid>(new_rider_name, new_rider_number, new_rider_age, new_rider_parent_name);
                bst.insert(move(new_rider));


            }else if(classChoice == 3){ //Vintage class
                //get the rider name
                string new_rider_name;
                new_rider_name = getRiderName(new_rider_name);

                //get the rider number
                int new_rider_number;
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter the rider number: "<<endl;
                new_rider_number = getUserSelection(0, 999);

                //get the bike year
                int new_rider_bike_year;
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter the year of the bike (1960 - 1990)"<<endl;
                new_rider_bike_year = getUserSelection(1960, 1990);

                //create and insert the object of the Vintage class
                auto new_rider = make_unique<Vintage>(new_rider_name, new_rider_number, new_rider_bike_year);
                bst.insert(move(new_rider));


            }else if(classChoice == 4){ //GPRacer class
                //get the rider name
                string new_rider_name;
                new_rider_name = getRiderName(new_rider_name);

                //get the rider number
                int new_rider_number;
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter the rider number: "<<endl;
                new_rider_number = getUserSelection(0, 999);

                //prompt the user and ask if the rider has a pro license
                bool new_rider_is_pro;
                int bool_checker = 0;
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nDoes this rider have a Pro License?: \n1)Yes\n2)No\n";
                bool_checker = getUserSelection(1, 2);
                if(bool_checker == 1){
                    new_rider_is_pro = true;
                }else{
                    new_rider_is_pro = false;
                }

                //create and insert an object of the GPRacer type
                auto new_rider = make_unique<GPRacer>(new_rider_name, new_rider_number, new_rider_is_pro);
                bst.insert(move(new_rider));
            }

        //manually remove a rider
        }else if(choice == 3){
            int to_remove; //int for rider number
            cout<<"Please enter the number of the rider to be removed from the database: "<<endl; //prompt for rider number to remove
            to_remove = getUserSelection(0, 999); //gets number from input
            bst.remove(to_remove); //removes rider

        //start a rider's race
        }else if(choice == 4){
            int riderNumber; //int to hold rider number
            cout<<"Enter the rider number for the rider whose race is starting: "<<endl; //prompt for rider number
            riderNumber = getUserSelection(0, 999); //get rider number from user
            Contestant* riderStarting = bst.search(riderNumber); //returns contestant once found
            if(riderStarting != nullptr){ //checks if rider was found
                riderStarting->start(); //starts rider's race
            }else{
                //error message if rider was not found
                cout<<"Rider #"<<riderNumber<<" not found, please check the number and try again.\n\n";
            }

        //stops a rider's race
        }else if(choice == 5){
            int riderNumber; //int for rider number
            cout<<"=-=-=-=-=-=-=-=-=-=\nEnter the rider number for the rider whose race is stopping: "<<endl;
            riderNumber = getUserSelection(0, 999); //gets rider number
            Contestant* riderStopping = bst.search(riderNumber); //returns a contestant after finding them
            if(riderStopping != nullptr){ //check if rider was found
                cout<<"\n=-=-=-=-=-=-=-=-=-=Did this rider finish their race?\n1)Yes\n2)No\n\n";
                int rider_finished = getUserSelection(1, 2); //user selects if rider finished the race
                bool finished;
                if(rider_finished == 1){ //assigns finished variable based on user selection
                    finished = true;
                }else{
                    finished = false;
                }
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter the rider's final time in minutes: \n";
                int minutes = getUserSelection(1, 999); //gets number of minutes for rider's finishing time
                
                riderStopping->stop(finished, minutes); //stops rider race using arguments taken in from user
            }else{
                //error message if rider could not be found
                cout<<"\n=-=-=-=-=-=-=-=-=-=\nRider #"<<riderNumber<<" not found, please check the number and try again.\n=-=-=-=-=-=-=-=-=-=\n\n";
            }
        //auto populate tree
        }else if(choice == 6){
            cout<<"\nAuto-populating list with 16 riders (4 of each class).\n\n";

            auto rider1 = make_unique<Contestant>("Mike Bencze", 729);
            auto rider2 = make_unique<Kid>("Eli Tomac", 1, 10, "John");
            auto rider3 = make_unique<Vintage>("Malcolm Smith", 2, 1971);
            auto rider4 = make_unique<GPRacer>("Ricky Carmichael", 4, true);
            auto rider5 = make_unique<Contestant>("Joey Dunlop", 6);
            auto rider6 = make_unique<Kid>("Ruche Moodley", 21, 13, "Devin");
            auto rider7 = make_unique<Vintage>("Kenny Roberts", 14, 1978);
            auto rider8 = make_unique<GPRacer>("Franco Morbidelli", 22, true);
            auto rider9 = make_unique<Contestant>("Jett Lawrence", 71);
            auto rider10 = make_unique<Kid>("Tatsuki Suzuki", 11, 9, "Tadayuki");
            auto rider11 = make_unique<Vintage>("Tadayuki Okada", 37, 1990);
            auto rider12 = make_unique<GPRacer>("Mat Oxley", 45, false);
            auto rider13 = make_unique<Contestant>("David Gentlecore", 134);
            auto rider14 = make_unique<Kid>("Peter Hill", 127, 9, "Marion");
            auto rider15 = make_unique<Vintage>("Pedro Acosta", 888, 1961);
            auto rider16 = make_unique<GPRacer>("John McGuiness", 97, true);
            bst.insert(move(rider1));
            bst.insert(move(rider2));
            bst.insert(move(rider3));
            bst.insert(move(rider4));
            bst.insert(move(rider5));
            bst.insert(move(rider6));
            bst.insert(move(rider7));
            bst.insert(move(rider8));
            bst.insert(move(rider9));
            bst.insert(move(rider10));
            bst.insert(move(rider11));
            bst.insert(move(rider12));
            bst.insert(move(rider13));
            bst.insert(move(rider14));
            bst.insert(move(rider15));
            bst.insert(move(rider16));
        //removes all riders from the tree
        }else if(choice == 7){
            cout<<"\n=-=-=-=-=-=-=-=-=-=\nRemoving all riders: \n=-=-=-=-=-=-=-=-=-=\n\n";
            bst.removeAll();
        //searches for a rider and checks if they are pro
        }else if(choice == 8){
            cout<<"\n=-=-=-=-=-=-=-=-=-=\nPlease enter a rider number to check their Pro Status: "<<endl;
            int pro_number = getUserSelection(0, 999);
            bst.searchAndCheckPro(pro_number);
        }
    }
    cout<<"\n=-=-=-=-=-=-=-=-=-=\nThank you for using the Shamrock Contestant Tracker, Goodbye.\n=-=-=-=-=-=-=-=-=-=\n"<<endl;
    return 0;
}