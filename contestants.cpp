#include "contestants.h"
using namespace std;

//Contestant class functions
//Default Constructor
Contestant::Contestant(){
    started = false;
    finished = false;
    name = "Null";
    number = 0;
    finish_time = 0;
}

//Start
void Contestant::start(){
    started = true;
}

//Stop
void Contestant::stop(bool finish, int time){
    finished = true;
    if(finish){
        finish_time = time;
    }
}

//Display
void Contestant::display(){
    cout<<"Rider #"<<number<<endl<<"Name: "<<name<<endl;
    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes\n"<<endl;
    }else{
        cout<<endl;
    }
}

//Kid class functions
//default contructor
Kid::Kid(): Contestant(), age(0), parent("Unknown"){}
//Constructor with arguments:
Kid::Kid(string a_name, int a_number, int the_age, string parent_name):
    Contestant(a_name, a_number), age(the_age), parent(parent_name){}

//display
void Kid::display(){
    cout<<"Kid's Class Rider #"<<number<<endl<<"Name: "<<name<<endl<<"Age: "<<age<<endl<<"Parent Name: "<<parent<<endl;
    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes\n"<<endl;
    }else{
        cout<<endl;
    }
}

//Vintage class functions
//default contructor
Vintage::Vintage(): Contestant(), bike_year(1980) {}
//Constructor with arguments:
Vintage::Vintage(string a_name, int a_number, int the_year):
    Contestant(a_name, a_number), bike_year(the_year){}

//display:
void Vintage::display(){
    cout<<"Vintage Class Rider #"<<number<<endl<<"Name: "<<name<<endl<<"Bike Year: "<<bike_year<<endl;
    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes\n"<<endl;
    }else{
        cout<<endl;
    }
}



//GPRacer class functions
//default contructor
GPRacer::GPRacer(): Contestant(), pro(false) {}
//Constructor with arguments:
GPRacer::GPRacer(string a_name, int a_number, bool is_pro):
    Contestant(a_name, a_number), pro(is_pro){}

//display:
void GPRacer::display(){
    cout<<"Vintage Class Rider #"<<number<<endl<<"Name: "<<name<<endl<<"Pro Status: ";
    if(pro){
        cout<<" Pro"<<endl;
    }else{
        cout<<" Not Pro"<<endl;
    }

    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes\n"<<endl;
    }else{
        cout<<endl;
    }
}