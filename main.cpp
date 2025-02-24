#include "contestants.h"
#include <iostream>

using namespace std;

int main(){
    Contestant rider("Mike Bencze", 729);
    Kid kid_rider("Eli Tomac", 3, 14, "John");
    Vintage vintage_rider("Malcolm Smith", 2, 1971);
    GPRacer GPrider("Ricky Carmichael", 4, true);

    rider.start();
    kid_rider.start();
    vintage_rider.start();
    GPrider.start();

    rider.stop(true, 34);
    kid_rider.stop(true, 42);
    vintage_rider.stop(true, 38);
    GPrider.stop(true, 27);

    rider.display();
    kid_rider.display();
    vintage_rider.display();
    GPrider.display();


    return 0;
}