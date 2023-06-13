#ifndef BULLDOZER_H
#define BULLDOZER_H


#include <iostream>
#include "Robot.h"
#include <string>

using namespace std;

class World;

class Bulldozer : public Robot {
    friend class World;
    public:
        Bulldozer();
        Bulldozer(World *wrld, int x, int y);

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