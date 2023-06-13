
#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H


#include <iostream>
#include <string>
#include "Humanic.h"


using namespace std;

class World;

class Optimusprime : public Humanic {
    friend class World;
    public:
        Optimusprime();
        Optimusprime(World *wrld, int x, int y);

        string getName();
        int getStrength();
        int getHitpoint();
        int getType();

    private:
        int ID;
        static int count;
};



#endif