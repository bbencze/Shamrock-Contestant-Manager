#include <iostream>


using namespace std;

class Contestant{
    public:
        Contestant();
        Contestant(string a_name, int a_number): started(false), finished(false), name(a_name), number(a_number), finish_time(0){}
        void start();
        void stop (bool finish, int time);
        virtual void display();
        int get_number();

    protected:
        bool started;
        bool finished;
        string name;
        int number;
        int finish_time;

};

class Kid: public Contestant{
    public:
        Kid();
        Kid(string a_name, int a_number, int the_age, string parent_name);
        void display();
    protected:
        int age;
        string parent;
};

class Vintage: public Contestant{
    public:
        Vintage();
        Vintage(string a_name, int a_number, int the_year);
        void display();
    protected:
        int bike_year;
};

class GPRacer: public Contestant{
    public:
        GPRacer();
        GPRacer(string a_name, int a_number, bool is_pro);
        void display();
    protected:
        bool pro;
};