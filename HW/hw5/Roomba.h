#ifndef ROOMBA_H
#define ROOMBA_H

#include <iostream>
#include "Robot.h"
#include <string>


using namespace std;

class World;

class Roomba : public Robot {
    friend class World;
    public:
        Roomba();
        Roomba(World *wrld, int x, int y);

        string getName();
        int getStrength();
        int getHitpoint();
        int getType();
        int getDamage();
    private:
        int ID;
        static int count;

};


#endif