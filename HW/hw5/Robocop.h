#ifndef ROBOCOP_H
#define ROBOCOP_H


#include <iostream>
#include <string>
#include "Humanic.h"

using namespace std;

class World;

class Robocop : public Humanic {
    friend class World;
    public:
        Robocop();
        Robocop(World *wrld, int x, int y);

        string getName();
        int getStrength();
        int getHitpoint();
        int getType();
    private:
        int ID;
        static int count;
};



#endif