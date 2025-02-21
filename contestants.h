#include <iostream>

using namespace std;

class Contestant{
    public:
        Contestant();
        Contestant(string a_name, int a_number): name(a_name), number(a_number) {}
    protected:
        string name;
        int number;

};

class Kid: public Contestant{
    public:
        Kid();
        Kid(string a_name, int a_number, int the_age, string parent_name);
    protected:
        int age;
        string parent;
};

class Vintage: public Contestant{
    public:
        Vintage();
        Vintage(string a_name, int a_number, int the_year);
    protected:
        int bike_year;
};

class GPRacer: public Contestant{
    public:
        GPRacer();
        GPRacer(string a_name, int a_number, bool is_pro);
    protected:
        bool pro;
};