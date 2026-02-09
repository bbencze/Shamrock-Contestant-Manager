//Bee Bencze
//bencze@pdx.edu

#include <iostream>


using namespace std;

//base class for all contestants
class Contestant{
    public:
        Contestant();
        Contestant(string a_name, int a_number): started(false), finished(false), name(a_name), number(a_number), finish_time(0){}
        void start(); //starts the race
        void stop (bool finish, int time); //stops the race, marks whether the rider has finished, and logs their time
        virtual void display(); //displays rider info
        int get_number(); //getter :(

    protected:
        bool started; //bool for if race has started
        bool finished; //bool for if rider finished the race
        string name; //string for rider name
        int number; //int for rider number
        int finish_time; //int for finish time

};

//class for a kid's race
class Kid: public Contestant{
    public:
        Kid();
        Kid(string a_name, int a_number, int the_age, string parent_name); 
        void display(); //display function for derived class
    protected:
        int age; //age for the rider
        string parent; //string for parent's name, also shows age and parent's name
};

//derived class for a race with vintage bikes
class Vintage: public Contestant{
    public:
        Vintage();
        Vintage(string a_name, int a_number, int the_year);
        void display(); //display function for the vintage class, also shows bike year
    protected:
        int bike_year; //integer to store the bike's year
};

//derived class for GP Racers
//most competitive race, open to professional riders
class GPRacer: public Contestant{
    public:
        GPRacer();
        GPRacer(string a_name, int a_number, bool is_pro);
        void display(); //display that includes the rider's pro status
        void checkProStatus(); //RTTI function which checks a rider's pro status
    protected:
        bool pro; //integer for pro starus
};