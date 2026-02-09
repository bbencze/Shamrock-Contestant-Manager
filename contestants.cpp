//Bee Bencze
//bencze@pdx.edu

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
    cout<<name<<" has started their race!\n=-=-=-=-=-=-=-=-=-=\n"<<endl;
    started = true;
}

//Stop
void Contestant::stop(bool finish, int time){
    if(started){
        finished = true;
        if(finish){
            finish_time = time;
        }
    }else{
        cout<<"This rider has not yet started their race!\n=-=-=-=-=-=-=-=-=-=\n"<<endl;
    }
}

//Display
void Contestant::display(){
    cout<<"\n=-=-=-=-=-=-=-=-=-=\nRider #"<<number<<endl<<"Name: "<<name<<endl;
    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes"<<endl;
    }else{
        cout<<endl;
    }
}

int Contestant::get_number(){
    return number;
}

//Kid class functions
//default contructor
Kid::Kid(): Contestant(), age(0), parent("Unknown"){}
//Constructor with arguments:
Kid::Kid(string a_name, int a_number, int the_age, string parent_name):
    Contestant(a_name, a_number), age(the_age), parent(parent_name){}

//display
void Kid::display(){
    cout<<"\n=-=-=-=-=-=-=-=-=-=\nKid's Class Rider #"<<number<<endl<<"Name: "<<name<<endl<<"Age: "<<age<<endl<<"Parent Name: "<<parent<<endl;
    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes"<<endl;
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
    cout<<"\n=-=-=-=-=-=-=-=-=-=\nVintage Class Rider #"<<number<<endl<<"Name: "<<name<<endl<<"Bike Year: "<<bike_year<<endl;
    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes"<<endl;
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
    cout<<"=-=-=-=-=-=-=-=-=-=\nGrand Prix Class Rider #"<<number<<endl<<"Name: "<<name<<endl<<"Pro Status: ";
    if(pro){
        cout<<" Pro"<<endl;
    }else{
        cout<<" Not Pro"<<endl;
    }

    if(finished){
        cout<<"Finishing time: "<<finish_time<<" Minutes"<<endl;
    }else{
        cout<<endl;
    }
}

//check pro status using RTTI
void GPRacer::checkProStatus(){

    cout << "Checking Pro status for: " << name << "\n"; 
    if (typeid(*this) == typeid(GPRacer)) {
        cout << "This is a GP Racer, ";
        cout << (pro ? "Professional" : "Amateur") << " racer.\n=-=-=-=-=-=-=-=-=-=\n\n";
    } else {
        cout << "Not a GP Racer.\n=-=-=-=-=-=-=-=-=-=\n\n"; 
    }
}